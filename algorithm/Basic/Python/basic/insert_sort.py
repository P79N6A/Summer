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


if __name__ == '__main__':
    test_list = [1, 9, 2, 8, 3, 7, 4, 6, 5]
    print('Initial list : \t', test_list)
    print('Insert sort : \t', insert_sort(test_list))

