# Reverse the array
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input('').split()))
    
    for i in range(n//2):
        temp = a[i]
        a[i] = a[n-i-1]
        a[n-i-1] = temp
    print(*a,sep=' ') # * is unzip operator used to print without brackets and commas

# here in line 11, a newline is added by default after printing the whole array