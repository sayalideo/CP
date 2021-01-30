# Given an array, rotate the array by one position in clock-wise direction.
# Input : N = 5 A[] = {1, 2, 3, 4, 5} Output:5 1 2 3 4 

def rotate( arr, n):
   last = arr[-1]
   for i in range(n-1,0,-1):
       arr[i] = arr[i-1]
   arr[0] = last

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        rotate(a, n)
        print(*a)

        T -= 1


if __name__ == "__main__":
    main()

# 0.02