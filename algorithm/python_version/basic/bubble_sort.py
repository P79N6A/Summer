def bubble_sort(data):
    copy = list(data)
    for i in range(len(copy) - 1):
        for j in range(len(copy) - i - 1):
            if copy[j] > copy[j + 1]:
                copy[j], copy[j + 1] = copy[j + 1], copy[j]
    return copy


if __name__ == '__main__':
    test_list = [1, 9, 2, 8, 3, 7, 4, 6, 5]
    print('Initial list : \t', test_list)
    print('Bubble sort : \t', bubble_sort(test_list))

