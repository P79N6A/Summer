#-*-encoding:utf-8-*-
"""
    本模块封装了一个查找器， 用于在指定目录下按照一定的规则查找文件
"""
import os
import sys
import re
import shutil
import traceback

reload(sys)
sys.setdefaultencoding('utf-8')


def collect_file_by_suffix(file, dir_path):
    if not os.path.isdir(dir_path):
        os.mkdir(dir_path)
    file_name = os.path.split(file)[1]
    suffix_match = re.search('\.[a-zA-Z0-9]{1,4}$', file)
    if suffix_match:
        suffix = suffix_match.group().replace('.', '')
        dir_suffix = os.path.join(dir_path, suffix)
        if not os.path.isdir(dir_suffix):
            os.mkdir(dir_suffix)
        shutil.copyfile(file, os.path.join(dir_suffix, file_name))
    else:
        dir_suffix = os.path.join(dir_path, '其它')
        if not os.path.isdir(dir_suffix):
            os.mkdir(dir_suffix)
        shutil.copyfile(file, os.path.join(dir_suffix, file_name))


class Finder(object):
    def __init__(self, dir_path, recursion=True):
        self.dir_path = os.path.abspath(dir_path)
        self.recursion = recursion

    def find_by_suffix(self, *suffix):
        """
            根据后缀名找到所有相应的文件,可以传入数量不定的后缀名，如'jpg'等
        """
        ret = []
        unhandle = [self.dir_path]
        while unhandle != []:
            local = unhandle.pop()
            files = os.listdir(local)
            for item in files:
                abs_path = os.path.join(local, item)
                if os.path.isdir(abs_path):
                    unhandle.append(abs_path)
                elif os.path.isfile(abs_path):
                    for suf in suffix:
                        if abs_path.endswith('.' + suf):
                            ret.append(abs_path)
        return ret


    def find_all_file(self):
        """
            根据后缀名找到所有相应的文件,可以传入数量不定的后缀名，如'jpg'等
        """
        ret = []
        unhandle = [self.dir_path]
        while unhandle != []:
            local = unhandle.pop()
            files = os.listdir(local)
            for item in files:
                abs_path = os.path.join(local, item)
                if os.path.isdir(abs_path):
                    unhandle.append(abs_path)
                elif os.path.isfile(abs_path):
                    ret.append(abs_path)
        return ret

                    

if __name__ == '__main__':
    finder = Finder('./')
    files = finder.find_by_suffix('jpg', 'jpeg', 'png', 'gif', 'mp4', 'avi', 'mkv')
    for file in files:
        try:
            collect_file_by_suffix(file, './collect')
        except:
            print traceback.format_exc()
            continue
