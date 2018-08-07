import math


def quick_sort(data, begin=None, end=None):
    def partition(data_p, begin_p, end_p):
        cmp = data_p[end_p - 1]
        i = begin_p - 1
        j = begin_p
        for j in range(begin_p, end_p - 1):
            if data_p[j] <= cmp:
                data_p[i + 1], data_p[j] = data_p[j], data_p[i + 1]
                i += 1
        data_p[i + 1], data_p[end_p - 1] = data_p[end_p - 1], data_p[i + 1]
        return i + 1

    if begin is None and end is None:
        begin = 0
        end = len(data)
    if begin >= end:
        return
    
    part_index = partition(data, begin, end)
    quick_sort(data, begin, part_index)
    quick_sort(data, part_index + 1, end)


if __name__ == '__main__':
    test_list = [1, 9, 2, 8, 3, 7, 4, 6, 5]
    print('Initial list : \t', test_list)
    quick_sort(test_list)
    print('Quick sort : \t', test_list)
