def is_ugly(num):
    while num % 2 == 0:
        num = num / 2
    while num % 3 == 0:
        num = num / 3
    while num % 5 == 0:
        num = num / 5
    if num == 1:
        return True
    else:
        return False


def get_ugly_num_solution(index):
    # write code here
    i = 0
    m = 1
    while i != index:
        if is_ugly(m) is True:
            i += 1
        m += 1
    return m - 1


print(get_ugly_num_solution(1000))
