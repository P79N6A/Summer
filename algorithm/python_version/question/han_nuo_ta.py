def calc_step(n):
    if n == 1:
        return 1
    return 2 * calc_step(n-1) + 1

print calc_step(500)
