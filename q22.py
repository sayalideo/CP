# Factorials of large numbers
# Works for all testcases, largest n = 1000 
# 8 company tags

def factorial(n):
    if(n==1):
        return 1
    return n*(factorial(n-1))
    
t = int(input(''))
for _ in range(t):
    n = int(input(''))
    print(factorial(n))

# 0.03