# Move all the negative elements to one side of the array i.e. to the left side
#User function Template for python3

def segregateElements( arr, s):
    # Your code goes here
    n = -1
    q = []
    for i in range(s):
        if(arr[i]<0):
            q.append(arr[i])
        else:
            n = n+1
            arr[n] = arr[i]
    #print(*q)
    while(q):
        n = n+1
        arr[n] = q[0]
        q.remove(q[0])


#{ 
#  Driver Code Starts
#Initial Template for Python 3


def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        segregateElements(a, n)
        print(*a)

        T -= 1


if __name__ == "__main__":
    main()


# 1.86