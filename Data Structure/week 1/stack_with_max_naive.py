#python3
import sys


if __name__ == '__main__':
    stack = []

    num_queries = int(sys.stdin.readline())
    m = -1
    max_stack = []
    for _ in range(num_queries):
        query = sys.stdin.readline().split()

        if query[0] == "push":
            m = max(m,int(query[1]))
            stack.append(int(query[1]))
            max_stack.append(m)
        elif query[0] == "pop":
            stack.pop()
            max_stack.pop()
            
        elif query[0] == "max":

            print(max_stack[-1])
        else:
            assert(0)
