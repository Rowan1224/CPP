# python3

from collections import namedtuple

Request = namedtuple("Request", ["arrived_at", "time_to_process"])
Response = namedtuple("Response", ["was_dropped", "started_at"])


class Buffer:
    def __init__(self, size):
        self.size = size
        self.finish_time = []

    def process(self, request):
        # write your code here
        return Response(False, -1)

def binary_search(key, arr):

    r = len(arr)-1
    l = 0
    while l<=r:
        x = (r-l)/2
        
        mid = l+int(x)
        # print(mid)
        if arr[mid]>key:
            r = mid-1
        else:
            l = mid+1

    return r+1

   
    



def process_requests(requests, buffer):
    responses = []
    start,process = requests[0]
    times = [process]
    size = 1
    responses.append(start)
    for i in range(1,len(requests)):
        a, p = requests[i]
        stack_size = size-binary_search(a,times)+1
        if stack_size>buffer:
            responses.append(-1)
        else:
            responses.append(max(times[-1],a))
            times.append(times[-1]+p)
            size = size+1



            
    return responses


def main():
    buffer_size, n_requests = map(int, input().split())
    requests = []
    # times = [0]
    for _ in range(n_requests):
        arrived_at, time_to_process = map(int, input().split())
        requests.append((arrived_at, time_to_process))
        # times.append(times[-1]+time_to_process)

    # buffer = Buffer(buffer_size)
    # del times[0]
    # print(binary_search(10,times))
    if n_requests > 0:
        responses = process_requests(requests, buffer_size)
        for response in responses:
            print(response)


if __name__ == "__main__":
    main()
