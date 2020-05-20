# python3

from collections import namedtuple

def compare(parent,left,right):
    pt, p = parent
    lt, l = left
    rt, r = right

    if l<r and l<p:
        return 1
    elif r<l and r<p:
        return 2
    
    elif l==r and l<p:
        if lt<= rt:
            return 1
        else:
            return 2

    elif l==r and l==p:
        if lt<pt and lt<=rt:
            return 1
        elif rt<pt and rt<lt:
            return 2
    else:
        return 0
      


def heapify(data,i):
    
    n = len(data)
    parent = data[i]
    l = (i*2)+1
    r = (i*2)+2
    if l>=n:
        return
    else:
                
        left = data[l]
        if r<n:
            right = data[r]
        else:
            right = data[l]

        com = compare(parent,left,right)
        if com  == 1:
            
            data[i] = left
            data[l] = parent
            heapify(data,l)
        elif com == 2:
           
            data[i] = right
            data[r] = parent
            heapify(data,r)
        else:
            return
        



def build_heap(data):
        
    n = len(data)
    n = int((n-1)/2)
    for i in range(n,-1,-1):        
        heapify(data,i)




def main():
    n_workers, n_jobs = map(int, input().split())
    jobs = list(map(int, input().split()))
    assert len(jobs) == n_jobs

    data = [(i,jobs[i]) for i in range(min(n_workers,n_jobs))]
    build_heap(data)
    result = [(i,0) for i in range(min(n_workers,n_jobs))]

    if n_jobs>n_workers:
        for i in range(n_workers,n_jobs):
            result.append(data[0])
            t, p = data[0]
            data[0] = (t,jobs[i]+p)
            heapify(data,0)
    for t,p in result:
        print(str(t)+" "+str(p))

if __name__ == "__main__":
    main()
