import math


def max_sub_array(array, begin=None, end=None):
    def max_sub_array_mid(arr, begin_m, end_m, middle):
        l_sum, l_max_index, l_max_sum = 0, None, None
        l_local = middle - 1
        while l_local >= begin_m:
            l_sum += arr[l_local]
            if l_max_index is None:
                l_max_index = l_local
                l_max_sum = arr[l_local]
            elif l_sum > l_max_sum:
                l_max_index = l_local
                l_max_sum = l_sum
            l_local -= 1

        r_sum, r_max_index, r_max_sum = 0, None, None
        r_local = middle
        while r_local < end_m:
            r_sum += arr[r_local]
            if r_max_index is None:
                r_max_index = r_local + 1
                r_max_sum = arr[r_local]
            elif r_sum > r_max_sum:
                r_max_index = r_local + 1
                r_max_sum = r_sum
            r_local += 1

        if l_max_sum is None:
            l_max_sum = 0
            l_max_index = middle

        if r_max_sum is None:
            r_max_sum = 0
            r_max_index = middle

        ret = dict()
        ret['sum'] = l_max_sum + r_max_sum
        ret['begin'] = l_max_index
        ret['end'] = r_max_index
        return ret

    if begin is None and end is None:
        begin = 0
        end = len(array)
    res = dict()

    if begin + 1 == end:
        res['begin'] = begin
        res['end'] = end
        res['sum'] = array[begin]
        return res

    if begin == end:
        res['begin'] = begin
        res['end'] = end
        res['sum'] = 0
        return res

    mid = math.floor((begin + end) / 2)

    l = max_sub_array(array, begin, mid)
    r = max_sub_array(array, mid, end)
    m = max_sub_array_mid(array, begin, end, mid)

    if l['sum'] >= r['sum'] and l['sum'] >= m['sum']:
        return l
    elif r['sum'] >= l['sum'] and r['sum'] >= m['sum']:
        return r
    else:
        return m


if __name__ == '__main__':
    test_list = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
    result = max_sub_array(test_list)
    print('begin :', result['begin'], 'end:', result['end'], 'sum:', result['sum'])
