import math


def bubble_sort(data):
    copy = list(data)
    for i in range(len(copy) - 1):
        for j in range(len(copy) - i - 1):
            if copy[j] > copy[j + 1]:
                copy[j], copy[j + 1] = copy[j + 1], copy[j]
    return copy


def insert_sort(data):
    copy = list(data)
    for index in range(len(copy)):
        if index == 0:
            pass
        else:
            local = index
            while copy[local] < copy[local - 1] and local >= 1:
                copy[local], copy[local - 1] = copy[local - 1], copy[local]
                local -= 1
    return copy


def merge_sort(data, begin=None, end=None):
    def merge_sub_array(arr, begin1, end1, begin2, end2):
        list1 = arr[begin1:end1]
        list2 = arr[begin2:end2]
        local = begin1
        index1, index2 = 0, 0
        while index1 < len(list1) and index2 < len(list2):
            if list1[index1] < list2[index2]:
                arr[local] = list1[index1]
                local += 1
                index1 += 1
            else:
                arr[local] = list2[index2]
                local += 1
                index2 += 1
        if index1 < len(list1):
            while index1 < len(list1):
                arr[local] = list1[index1]
                local += 1
                index1 += 1
        if index2 < len(list2):
            while index2 < len(list2):
                arr[local] = list2[index2]
                local += 1
                index2 += 1

    if begin is None and end is None:
        begin = 0
        end = len(data)
    if begin + 1 >= end:
        return
    copy = list(data)
    middle = math.ceil(len(copy) / 2)
    print(begin, middle, end)
    merge_sort(copy, begin=begin, end=middle)
    merge_sort(copy, begin=middle, end=end)
    merge_sub_array(copy, begin, middle, middle, end)
    return copy


def quick_sort(data):
    copy = list(data)
    return copy


def shell_sort(data):
    copy = list(data)
    return copy


def heap_sort(data):
    copy = list(data)
    return copy

if __name__ == '__main__':
    test_list = [1, 9, 2, 8, 3, 7, 4, 6, 5]
    print('Initial list : \t', test_list)
    print('Bubble sort : \t', bubble_sort(test_list))
    print('Insert sort : \t', insert_sort(test_list))
    print('Merge sort : \t', merge_sort(test_list))
    print('Quick sort : \t', quick_sort(test_list))
    print('Shell sort : \t', shell_sort(test_list))
    print('Heap sort : \t', heap_sort(test_list))
