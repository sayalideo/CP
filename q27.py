#code
from collections import defaultdict
t = int(input())
for _ in range(t):
    m,n = list(map(int,input().strip().split()))
    arr = list(map(int,input().strip().split()))
    sub = list(map(int,input().split()))
    a = defaultdict(int)
    s = defaultdict(int)
    for i in arr:
        a[i] += 1
    for j in sub:
        s[j] += 1
    flag = 0
    for k,v in s.items():
        if(v!=a[k]):
            print("No")
            flag = 1
            break
    if(flag == 0):
        print("Yes")