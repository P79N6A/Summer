import math


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

    middle = math.ceil((end + begin) / 2)
    merge_sort(data, begin=begin, end=middle)
    merge_sort(data, begin=middle, end=end)
    merge_sub_array(data, begin, middle, middle, end)


if __name__ == '__main__':
    test_list = [1, 9, 2, 8, 3, 7, 4, 6, 5]
    print('Initial list : \t', test_list)
    merge_sort(test_list)
    print('Merge sort : \t', test_list)
