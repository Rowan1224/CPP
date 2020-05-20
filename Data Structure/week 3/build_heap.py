# python3
import math
import os,time


def heapify(data,i,swaps):
    
    n = len(data)
    parent = data[i]
    l = (i*2)+1
    r = (i*2)+2
    # print(i,l,r)
    if l>=n:
        return
    else:
                
        left = data[l]
        if r<n:
            right = data[r]
        else:
            right = left
                
        if min(left,right)<parent:
            
            if min(left,right) == left:
                swaps.append((i,l))
                t = data[i]
                data[i] = left
                data[l] = t
                heapify(data,l,swaps)
            else:
                swaps.append((i,r))
                t = data[i]
                data[i] = right
                data[r] = t
                heapify(data,r,swaps)



def build_heap(data,swaps):
    """Build a heap from ``data`` inplace.

    Returns a sequence of swaps performed by the algorithm.
    """
    # The following naive implementation just sorts the given sequence
    # using selection sort algorithm and saves the resulting sequence
    # of swaps. This turns the given array into a heap, but in the worst
    # case gives a quadratic number of swaps.
    #
    # TODO: replace by a more efficient implementation
    
    n = len(data)
    # limit = height(n)
    # for i in range(len(data)):
    #     for j in range(i + 1, len(data)):
    #         if data[i] > data[j]:
    #             swaps.append((i, j))
    #             data[i], data[j] = data[j], data[i]
    c = 0 
    n = int((n-1)/2)
    for i in range(n,-1,-1):
        
        heapify(data,i,swaps)
    # print(c)
    # return swaps


def main():
    n = int(input())
    data = list(map(int, input().split()))
    assert len(data) == n
    # print(height(n))
    # # t1 = time.time()
    # dirt ="/home/ra/Desktop/Data Structure & Algorithm/Data Structure/week2_priority_queues_and_disjoint_sets/1_make_heap/"
    # with open(dirt+'tests/04','r') as file:

    #     d = [l.split(" ") for l in file]
    # t1 = time.time()
    # n = int(d[0][0])
    # data = [int(l) for l in d[1]]
    swaps = []
    build_heap(data,swaps)

    # print((time.time() - t1))
    print(len(swaps))
    for i, j in swaps:
        print(i, j)


if __name__ == "__main__":
    main()
