# -*- coding:utf-8 -*-
class Solution:
    def is_available(self, row, col, threshold):
        if row <= 0:
            row = abs(row)
        if col <= 0:
            col = abs(col)
        s = 0
        while(row != 0):
            s += (row % 10)
            row /= 10
        while(col != 0):
            s += (col % 10)
            col /= 10
        if s <= threshold:
            return True
        else:
            return False
    

    def stack_push(self, x, y, stack, rows, cols, visited):
        if x >= 0 and x <rows:
            if y>= 0 and y < cols:
                if (x, y) not in visited and (x, y) not in stack:
                    # print 'Push ', (x, y)
                    stack.append((x, y))

        
    def movingCount(self, threshold, rows, cols):
        # write code here
        visited = set()
        avail_cnt = 0
        travel_stack = [(0, 0)]
        while(len(travel_stack) != 0):
            local = travel_stack.pop()
            if self.is_available(local[0], local[1], threshold):
                print 'Visit => ', local, 'Stack => ', travel_stack
                avail_cnt += 1
                visited.add(local)
                self.stack_push(local[0] - 1, local[1], travel_stack, rows, cols, visited)
                self.stack_push(local[0], local[1] - 1, travel_stack, rows, cols, visited)
                self.stack_push(local[0] + 1, local[1], travel_stack, rows, cols, visited)
                self.stack_push(local[0], local[1] + 1, travel_stack, rows, cols, visited)
        return avail_cnt



if __name__ == '__main__':
    solution = Solution()
    print solution.movingCount(5, 10, 10)

