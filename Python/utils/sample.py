import random as rd
import sys

def sample_lines(lines_num):
    total = []
    for line in sys.stdin:
        line = line.strip()
        total.append(total)
    rd.shuffle(total)
    return total[:lines_num]

if __name__ == '__main__':
    try:
        lines_num = int(sys.argv[1])
        sample_lines(lines_num)
    except:
        print >> sys.stderr, 'Argu Error, type of argu must be int > 0.'
