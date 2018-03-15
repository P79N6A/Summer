'''
    This module has been built for evaluate the performance of sort algorithm.
'''
import random as rd
import time
import math

def bubble_sort(arr):
    '''
        Bubble sort for input array, return a new array sorted.
    '''
    copy = arr[:]
    i, j = 0, len(copy) - 1
    while j >= 1:
        for i in range(j):
            if copy[i] > copy[i + 1]:
                copy[i], copy[i + 1] = copy[i + 1], copy[i]
        j -= 1
    return copy

def display_list(arr, limit=20):
    if type(arr) != list:
        print('Your argu is not list, please check !')
        return
    if len(arr) <= limit:
        print(arr)
    else:
        output = '['
        index = 0
        for item in arr:
            if index < limit -1:
                output = output + str(item) + ', ' 
            elif index == limit -1:
                output += str(item)
            else:
                break
        output += ']'
        print(output)

def main(sort_function, name):
    '''
        Main function.
    '''
    print('Generating big list for sort...')
    demo_list = [rd.randint(1,100) for i in range(1000)]
    print('Length of big list: ', len(demo_list))
    print('Before sort...')
    display_list(demo_list)
    print('Sorting big list now...By', name)
    begin_time = time.time()
    demo_list = sort_function(demo_list)
    end_time = time.time()
    delay = math.trunc(1000 * (end_time - begin_time))
    print('Total time : ', delay, 'ms.')
    print('After sort...')
    display_list(demo_list)


if __name__ == '__main__':
    main(bubble_sort, 'bubble sort')
