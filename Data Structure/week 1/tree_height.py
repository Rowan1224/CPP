# python3

import sys
import threading


def compute_height(root,tree):
    # Replace this code with a faster implementation
    # max_height = 0
    # for vertex in range(n):
    #     height = 0
    #     current = vertex
    #     while current != -1:
    #         height += 1
    #         current = parents[current]
    #     max_height = max(max_height, height)
    # return max_height
    mx  = -1
    if root in tree.keys():
        for n in tree[root]:
            mx = max(compute_height(n,tree),mx)
        return mx+1
    else:
        return 1


def main():
    n = int(input())
    parents = list(map(int, input().split()))
    tree = {}
    root = 0
    for i in range(0,len(parents)):
        if parents[i] == -1:
            root  = i

        if parents[i] in tree.keys():
            tree[parents[i]].append(i)

        else:
            tree[parents[i]] = [i]
    print(compute_height(root, tree))


# In Python, the default limit on recursion depth is rather low,
# so raise it here for this problem. Note that to take advantage
# of bigger stack, we have to launch the computation in a new thread.
sys.setrecursionlimit(10**7)  # max depth of recursion
threading.stack_size(2**27)   # new thread will get stack of such size
threading.Thread(target=main).start()
