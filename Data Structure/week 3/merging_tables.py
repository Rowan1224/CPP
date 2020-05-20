# python3
import sys
import threading


def find(p,djs):
    if djs[p]==p:
        return p
    else:
        djs[p]= find(djs[p],djs)

    return djs[p]

def merge(d,s,djs):
    d = find(d,djs)
    s = find(s,djs)

    djs[s]=d



def main():
    n_tables, n_queries = map(int, input().split())
    counts = list(map(int, input().split()))
    djs = [i for i in range(n_tables)]
    assert len(counts) == n_tables
    m = max(counts)
    for i in range(n_queries):
        d, s = map(int, input().split())
        d = d-1
        s = s -1
        p = find(d,djs)
        q = find(s,djs)
        if p!=q:
            counts[p] = counts[p]+counts[q]
            counts[q] = 0
            merge(p,q,djs)
            m = max(counts[p],m)
        else:
            m = max(counts[p],m)
        print(m)
        # print(djs)
    

sys.setrecursionlimit(10**7)  # max depth of recursion
threading.stack_size(2**27)   # new thread will get stack of such size
threading.Thread(target=main).start()
