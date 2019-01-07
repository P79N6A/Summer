#! /Users/sheng/anaconda2/bin/python
# -*-coding:utf-8-*-
from __future__ import print_function
import sys
import json

reload(sys)
sys.setdefaultencoding('utf-8')


class DFSA(object):
    """
        DFSA 是封装好的确定自动机，自动机的定义格式参考cow.json
    """
    def __init__(self, path):
        with open(path, 'r') as f:
            self.str = json.load(f)
        self.compile()

    def check(self):
        """
            检查自动机的正确性
        """
        pass

    def compile(self):
        """
            编译自动机，检查定义的正确性
        """
        self.begin = self.str['begin']
        self.end = self.str['end']
        self.state = self.str['state']
        self.dic = self.str['dic']
        self.trans = self.str['trans']
        self.check()

    def recognize(self, sentence):
        """
            识别输入的（字符串）序列
        """
        self.str_p = 0
        self.dfsa_p = self.begin
        while (self.str_p < len(sentence)):
            c = sentence[self.str_p]
            if c not in self.dic:
                return False
            if c not in self.trans[self.dfsa_p]:
                return False
            self.dfsa_p = self.trans[self.dfsa_p][c]
            self.str_p += 1
        if self.dfsa_p in self.end:
            return True
        return  False
        


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("Usage: ./DFSA.py [path] [string]")
    else:
        path = sys.argv[1]
        exp = sys.argv[2]
        fsa = DFSA(path)
        print(exp, ' match.' if fsa.recognize(exp) else 'not match.')
