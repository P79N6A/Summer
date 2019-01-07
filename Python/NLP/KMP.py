# -*-encoding:utf-8-*-
from __future__ import print_function

def calculate_prefix_array(pattern):
    print(pattern)
    m = len(pattern)
    Pi = [None for _ in range(m)]
    Pi[0] = 0
    k = 0
    for q in range(1, m):
        while k > 0 and pattern[k + 1] != pattern[q]:
            k = Pi[k]
        if Pi[k + 1] == Pi[q]:
            k = k + 1
        Pi[q] = k
    return Pi


def KMP(string, pattern):
    n = len(string)
    m = len(pattern)
    Pi = calculate_prefix_array(pattern)
    print(Pi)
    q = 0
    for i in range(1, n + 1):
        while q > 0 and Pi[q + 1] != string[i]:
            q = Pi[q]
        if Pi[q + 1] == string[i]:
            q += 1
        if q == m:
            print('Pattern occurs with shift', (i - m), '.')
            return True
        q = Pi[q]
    return False

if __name__ == '__main__':
    T = 'hellomomomentworldstring'
    P = 'momoment'
    print('Match.' if KMP(T, P) else 'Not match.')
