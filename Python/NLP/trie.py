# -*-encoding:utf-8-*-
from __future__ import print_function

class Trie(object):
    def __init__(self):
        self.tree = {}

    def insert(self, word):
        """
            在当前Trie树中插入键为word的结点
        """
        tree = self.tree
        for char in word:
            if char not in tree:
                tree[char] = {}
            tree = tree[char]
        tree['exist'] = True
        
    def search(self, word):
        """
            在当前Trie树中搜索键为word的结点
        """
        tree = self.tree
        for char in word:
            if char not in tree:
                return None
            tree = tree[char]
        if 'exist' in tree and tree['exist'] is True:
            return tree
        return None

    def startwith(self, string):
        """
            判断当前Trie树中是否存在以string为前缀的字符串
        """
        tree = self.tree
        for char in string:
            if char not in tree:
                return False
            tree = tree[char]
        return True 

    def search_tree(self, tree, prefix):
        """
            搜索当前子树，返回存在的字符串
        """
        strings = []
        if 'exist' in tree and tree['exist'] == True:
            strings.append(prefix)
        for item in tree:
            if item != 'exist':
                strings.extend(self.search_tree(tree[item], prefix + item))
        return strings

    def get_prefix(self, prefix):
        """
            在当前Trie树中搜索以prefix为前缀的所有项
        """
        if not self.startwith(prefix):
            return []

        tree = self.tree
        for char in prefix:
            if char not in tree:
                return False
            tree = tree[char]
        return self.search_tree(tree, prefix)

if __name__ == '__main__':
    trie = Trie()
    trie.insert('and')
    trie.insert('as')
    trie.insert('at')
    trie.insert('cat')
    trie.insert('car')
    trie.insert('bed')
    print(trie.get_prefix('c'))
