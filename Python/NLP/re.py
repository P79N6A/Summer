#! /Users/sheng/anaconda2/bin/python
# -*-coding:utf-8-*-
"""
    re.py是一个基本的正则表达式引擎，基于本项目中的FSA包实现
"""
from __future__ import print_function
import sys
import json

reload(sys)
sys.setdefaultencoding('utf-8')

class RE(object):
    def __init__(self):
        pass

    def compile(self, pattern):
        pass
    
    def recognize(self, string):
        return False

    def search(self, string):
        return []
    
    def replace(self, original, rpl):
        return ''



if __name__ == '__main__':
    main()
