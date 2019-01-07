# -*- coding: utf-8 -*- 
"""
    本模块提供一些通用的功能
"""
from __future__ import print_function
import sys
import json

import math
import time

import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

import torch
import jieba
from torch.autograd import Variable

CONNECT_TAG = u'TAG_CON'
BEGIN_TAG = u'TAG_BEG'
END_TAG = u'TAG_END'
UNKNOWN_TAG = u'TAG_UNK'
NAME_TAG = u'TAG_NAME'
VALUE_TAG = u'TAG_VALUE'
jieba.add_word(CONNECT_TAG.encode('utf8'))
jieba.add_word(BEGIN_TAG.encode('utf8'))
jieba.add_word(END_TAG.encode('utf8'))
jieba.add_word(UNKNOWN_TAG.encode('utf8'))
jieba.add_word(NAME_TAG.encode('utf8'))
jieba.add_word(VALUE_TAG.encode('utf8'))

reload(sys)
sys.setdefaultencoding('utf-8') 

class WordMap:
    """
        词典类，提供单词、索引、频率之间的相互映射
    """
    def __init__(self, name, dir_path):
        self.name = name
        self.dir_path = dir_path
        self.word2index = {}
        self.word2count = {}
        self.index2word = {}
        self.n_words = 0
    
    def reset(self, name=None, dir_path=None):
        if name is not None:
            self.name = name

        if dir_path is not None:
            self.dir_path = dir_path

        self.word2index = {}
        self.word2count = {}
        self.index2word = {}
        self.n_words = 0

    def _find_index_available(self):
        i = 0
        while i in self.index2word:
            i += 1
        return i

    def addWord(self, word, freq):
        if word.isspace() or word == u'':
            return
        if word not in self.word2index:
            index = self._find_index_available()
            self.word2index[word] = index
            self.index2word[index] = word
            self.word2count[word] = freq
            self.n_words += 1
        else:
            self.word2count[word] += freq

    def get_word(self, index):
        if index in self.index2word:
            return self.index2word[index]
        else:
            return UNKNOWN_TAG

    def get_count(self, word):
        if word in self.word2count:
            return self.word2count[word]
        else:
            return 0

    def get_index(self, word):
        if word in self.word2index:
            return self.word2index[word]
        else:
            return self.word2index[UNKNOWN_TAG]

    def has_word(self, word):
        if word in self.word2count:
            return True
        return False

    def save(self):
        word_list = self.word2count.items()
        word_list = sorted(word_list, key = lambda x:x[1], reverse=True)
        with open(self.dir_path, 'w') as f:
            for item in word_list:
                f.write(item[0] + u'\t' + str(item[1]) + u'\t' + str(self.word2index[item[0]]) + u'\n')

    def load(self):
        self.reset()
        with open(self.dir_path, 'r') as f:
            lines = f.readlines()
            for i in range(len(lines)):
                line = lines[i].strip().decode('utf-8')
                fields = line.split(u'\t')
                if len(fields) != 3:
                    continue
                word = fields[0]
                freq = int(fields[1])
                index = int(fields[2])
                if word not in self.word2index:
                    self.index2word[index] = word
                    self.word2index[word] = index
                    self.word2count[word] = freq
                    self.n_words += 1
                else:
                    self.word2count[word] += freq


    def sentence_to_index(self, sentence):
        if type(sentence) != unicode:
            sentence = sentence.decode('utf8')
        pieces = jieba.lcut(sentence.strip())
        return map(lambda x: self.get_index(x.decode('utf8')), pieces)
    
    def index_to_index(self, index_str):
        if type(index_str) != unicode:
            index_str = index_str.decode('utf8')
        index_list = index_str.strip().split(u' ')
        return map(lambda x: self.get_word(int(x)), index_list)

    def set_size(self, size):
        self.save()
        self.reset()
        with open(self.dir_path, 'r') as f:
            lines = f.readlines()
            for i in range(len(lines)):
                if i >= size:
                    break
                line = lines[i].strip().decode('utf-8')
                fields = line.split(u'\t')
                if len(fields) != 3:
                    continue
                word = fields[0]
                freq = int(fields[1])
                index = int(fields[2])
                if word not in self.word2index:
                    self.index2word[index] = word
                    self.word2index[word] = index
                    self.word2count[word] = freq
                    self.n_words += 1
                else:
                    self.word2count[word] += freq
        

    def filter_low_freq(self, minimum):
        restore = []
        for word in self.word2count:
            count = self.word2count[word]
            if count >= minimum:
                restore.append((word, count))
        self.reset()
        for item in restore:
            self.addWord(item[0], item[1])