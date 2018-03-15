import math

'''
    二叉查找树节点的结构（dict）：
        node['val']:    number  节点的数据
        node['left']:   dict    左孩子引用
        node['right']:  dict    右孩子引用
        node['parent']: dict    父节点引用
'''


class BST(object):
    def __init__(self, data=None):
        self.root = None
        if data is not None:
            self.build(data)

    def insert(self, item):
        tmp = dict()
        tmp['val'] = item
        tmp['left'] = None
        tmp['right'] = None
        tmp['parent'] = None
        if self.root is None:
            self.root = tmp
        else:
            parent = None
            local = self.root
            while local is not None:
                if item > local['val']:
                    parent = local
                    local = local['right']
                else:
                    parent = local
                    local = local['left']
            if local == parent['left']:
                parent['left'] = tmp
                tmp['parent'] = parent
            elif local == parent['right']:
                parent['right'] = tmp
                tmp['parent'] = parent




    def search(self):
        pass

    def remove(self):
        pass

    def build(self, data):
        if type(data) != list:
            print('data type incorrect !')
            return
        for item in data:
            self.insert(item)

    def in_order_traverse(self, node):
        if node is None:
            return
        self.in_order_traverse(node['left'])
        print(node['val'])
        self.in_order_traverse(node['right'])



    def pre_order_traverse(self, node):
        if node is None:
            return
        print(node['val'])
        self.in_order_traverse(node['left'])
        self.in_order_traverse(node['right'])

    def pro_order_traverse(self, node):
        if node is None:
            return
        self.in_order_traverse(node['left'])
        self.in_order_traverse(node['right'])
        print(node['val'])


if __name__ == '__main__':
    bst = BST()
    test_list = [1, 9, 2, 8, 3, 7, 4, 6, 5]

    bst.build(test_list)
    print('\nPreorder Traverse:')
    bst.pre_order_traverse(bst.root)
    print('\nInorder Traverse:')
    bst.in_order_traverse(bst.root)
    print('\nProorder Traverse:')
    bst.pro_order_traverse(bst.root)

    bst.insert(10)
    print('\nPreorder Traverse:')
    bst.pre_order_traverse(bst.root)
    print('\nInorder Traverse:')
    bst.in_order_traverse(bst.root)
    print('\nProorder Traverse:')
    bst.pro_order_traverse(bst.root)

    # bst.remove(5)
    # print(bst.pre_order_traverse())
    # print(bst.in_order_traverse())
    #
    # result = bst.search(6)
    # print('Search result :', result['val'])
