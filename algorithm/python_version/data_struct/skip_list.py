# -*-encoding:utf-8-*-
"""
    本模块实现了对跳表的封装，实现了基本的插入、删除、查找等功能
    在本模块的当前的实现下，同一个值仅保存在一个结点中，层次信息保存在一个引用数组中
"""
from __future__ import print_function
import random

class SkipListNode(object):
    """
        跳表的结点
    """
    def __init__(self, key=None, layer=0, data=None, is_begin=False, is_end=False):
        self.layer = layer
        self.key = key
        self.data = data
        self.next = [None for _ in range(layer + 1)]
        self.is_begin = is_begin
        self.is_end = is_end

class SkipList(object):
    """
        跳表结构的封装
    """
    def __init__(self):
        self.layer = -1
        self.begin = SkipListNode(layer=self.layer,is_begin=True)
        self.end = SkipListNode(layer=self.layer, is_end=True)
    
    def _layer(self):
        """
            针对插入的新的结点，生成随机的层数
        """
        k = 0
        while(random.randint(0, 1) != 0):
            k += 1
        return k

    def find(self, key):
        local = self.begin
        layer = self.layer
        while layer >= 0:
            while (not local.next[layer].is_end)\
                and local.next[layer].key <= key:
                local = local.next[layer]
            layer -=1
        if local.key == key:
            return local
        return None

    def insert(self, key):
        layer = self._layer()
        if layer > self.layer:
            self.layer += 1
            self.begin.next.append(self.end)
            self.begin.layer += 1
            layer = self.layer

        node = SkipListNode(key, layer)
        # link记录了每一层中node的前驱，一共有layer层
        link = []
        layer_i = layer
        local = self.begin
        while layer_i >= 0: # 遍历层
            while (not local.next[layer_i].is_end)\
                and local.next[layer_i].key <= key: # 遍历层内链表
                local = local.next[layer_i]
            link.append(local)
            layer_i -= 1
        link = list(reversed(link))

        for i in range(len(link)):
            ii = len(link) - i - 1
            point = link[ii]
            old_link = point.next[ii]
            point.next[ii] = node
            node.next[ii] = old_link

    def to_list(self):
        if self.layer < 0:
            return []
        ret = []
        layer_num = 0
        local = self.begin
        while not local.is_end:
            if not local.is_begin:
                ret.append(local.key)
            local = local.next[layer_num]
        return ret

    def minimum(self):
        if self.layer < 0:
            return None
        layer_num = 0
        local = self.begin
        if not local.next[layer_num].is_end:
            return local.next[layer_num]
        return None

    def maximum(self):
        if self.layer < 0:
            return None
        layer_num = 0
        local = self.begin
        while not local.next[layer_num].is_end:
            local = local.next[layer_num]
        if not local.is_begin:
            return local
        return None

    def adjust_layer(self):
        layer_num = self.layer
        while layer_num >= 0:
            if self.begin.next[layer_num].is_end:
                self.layer -= 1
                self.begin.next = self.begin.next[:self.layer + 1]
            else:
                break
            layer_num -= 1

    def remove(self, key):
        # link记录了每一层中node的前驱，一共有layer层
        link = []
        layer_i = self.layer
        local = self.begin
        while layer_i >= 0: # 遍历层
            while True: # 遍历层内链表
                if (not local.next[layer_i].is_end)\
                    and local.next[layer_i].key < key:
                    local = local.next[layer_i]
                elif local.next[layer_i].key == key:
                    link.append(local)
                    break
                else:
                    break
            layer_i -= 1
        link = list(reversed(link))

        for i in range(len(link)):
            ii = len(link) - i - 1
            point = link[ii]
            point.next[ii] = point.next[ii].next[ii]

        self.adjust_layer()
