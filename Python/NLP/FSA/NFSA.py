#! /Users/sheng/anaconda2/bin/python
# -*-coding:utf-8-*-
from __future__ import print_function
import sys
import json

reload(sys)
sys.setdefaultencoding('utf-8')


class NFSA(object):
    """
        NFSA 是封装好的非确定自动机，自动机的定义格式参考cow.json
    """
    def __init__(self, path):
        self.path = path
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
        with open(self.path, 'r') as f:
            self.str = json.load(f)
        self.begin = self.str['begin']
        self.end = self.str['end']
        self.state = self.str['state']
        self.dic = self.str['dic']
        self.trans = self.str['trans']
        self.check()

    def recognize(self, string):
        def next_state(seq):
            return seq.pop()
        
        def new_state(seq):
            new_state = []
            if string[self.str_p] in self.trans[self.nfsa_p]:
                for item in self.trans[self.nfsa_p][string[self.str_p]]:
                    if (item, self.str_p + 1) not in  seq:
                        new_state.append((item, self.str_p + 1))
            if u'epsilon' in self.trans[self.nfsa_p]:
                for item in self.trans[self.nfsa_p][u'epsilon']:
                    if (item, self.str_p) not in  seq:
                        new_state.append((item, self.str_p))
            return new_state

        def accept(string):
            if self.nfsa_p in self.end and self.str_p == len(string):
                return True
            return False


        agenda = [(self.begin, 0)]
        self.nfsa_p, self.str_p = next_state(agenda)
        while True:
            if accept(string):
                return True
            else:
                agenda.extend(new_state(agenda))
            
            if len(agenda) == 0:
                return False
            else:
                 self.nfsa_p, self.str_p = next_state(agenda)
        return True


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("Usage: ./NFSA.py [path] [string]")
    else:
        path = sys.argv[1]
        exp = sys.argv[2]
        fsa = NFSA(path)
        print(exp, ' match.' if fsa.recognize(exp) else 'not match.')