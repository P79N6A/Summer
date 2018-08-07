import math

class MinHeap(object):
    def __init__(self, list_data):
        self.data = list_data
        self.heap_size = 0

    # fix min-heap
    def min_heapify(self, index):
        left_index = 2 * index + 1
        right_index = 2 * (index + 1)
        min_index = index

        # local is leaf node
        if left_index + 1 > self.heap_size:
            return

        if left_index + 1 == self.heap_size:
            # local just has left child
            # Find index of minimun
            if self.data[index] > self.data[left_index]:
                min_index = left_index
                self.data[index], self.data[min_index] = self.data[min_index], self.data[index]
                self.min_heapify(min_index)
        else:
            # local has two child
            # Find index of minimun
            if self.data[index] > self.data[left_index] or self.data[index] > self.data[right_index]:
                if self.data[left_index] <= self.data[index] and self.data[left_index] <= self.data[right_index]:
                    min_index = left_index
                if self.data[right_index] <= self.data[index] and self.data[right_index] <= self.data[left_index]:
                    min_index = right_index

            if min_index != index:
                self.data[index], self.data[min_index] = self.data[min_index], self.data[index]
                self.min_heapify(min_index)

    def build_min_heap(self):
        self.heap_size = len(self.data)
        # index of the last no-leaf node
        last_index = math.floor(self.heap_size / 2) - 1
        for index in range(last_index + 1):
            index = last_index - index
            self.min_heapify(index)

    def heap_sort(self):
        print(self.data)
        cache = list()
        for i in range(self.heap_size):
            cache.append(self.data[0])
            self.heap_size -= 1
            self.data[0] = self.data[self.heap_size]
            self.data.pop()
            self.min_heapify(0)
        return cache

    def min_heap_insert(self):
        pass

    def heap_extract_min(self):
        pass

    def heap_increase_key(self):
        pass

    def heap_maximun(self):
        pass


if __name__ == '__main__':
    my_heap = MinHeap([1, 9, 2, 8, 3, 7, 4, 6, 5])
    my_heap.build_min_heap()
    after_sort = my_heap.heap_sort()
    print('After Sort : ', after_sort)
