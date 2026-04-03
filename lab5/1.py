def factorial(x):
    if x==0:
        return 1
    if x==1:
        return 1
    return x*factorial(x-1)
print(factorial(5))

def exp_x(x,n):
    abs_val = lambda x: abs(x)
    sum=0
    for i in range(n):
        sum+=abs_val((-1)**i*(x**(2*i))/(factorial(2*i)))
    return sum
print(exp_x(2,3))

# Global variable
G_sum = 0

def last(n, r, i=0):
    """
    Recursively computes the equation:
    G_n = 1 + r + r^2 + ... + r^n
     Recursion stops when i > n
    - Each recursion adds r^i to the global variable sum
    """
    global G_sum
    
    if i > n:
        return
    
    G_sum += r ** i
    last(n, r, i + 1)


last(5, 4)
print("G_n =", G_sum)