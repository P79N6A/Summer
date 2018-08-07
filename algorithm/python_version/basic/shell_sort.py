import math


def insert_sort_whith_gap(data, gap):
    for ite in range(gap):
        for index in range(len(data)):
            if (index - ite) % gap != 0:
                pass
            else:
                if index - ite == 0:
                    pass
                else:
                    local = index
                    while data[local] < data[local - gap] and local >= ite + gap:
                        data[local], data[local - 1] = data[local - 1], data[local]
                        local -= gap


def shell_sort(data):
    gap = math.floor(len(data) / 2)
    while gap > 0:
        insert_sort_whith_gap(data, gap)
        gap = math.floor(gap / 2)


if __name__ == '__main__':
    test_list = [1, 9, 2, 8, 3, 7, 4, 6, 5]
    print('Initial list : \t', test_list)
    shell_sort(test_list)
    print('Shell sort : \t', test_list)
