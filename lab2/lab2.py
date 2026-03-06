def sequence():
    n = input("Please enter a positive integer greater than 9\n")
    n = int(n)
    cnt = 0
    print(str(n) + "->", end="")
    while n>=10:
        c = n
        ans = 0
        while c != 0:
            m = c%10
            c-=m
            c= c //10
            ans+=m
        cnt+=1
        n = ans
        if n>=10:
            print(str(ans) + "->", end="")
        else:
            print(str(ans))
    print("Final value: " + str(ans))
    print("Total steps: " + str(cnt))

def fizzbuzz():
    n = 0
    n = input("Please enter a number between 10 and 100: \n")
    n = int(n)
    while not (n>=10 and n<=100):
        n = input("Invalid input. Please enter a number between 10 and 100: \n")
        n = int(n)
    fizz = 0
    buzz = 0
    fizzbuzz = 0
    for i in range(1,n+1,1):
        if i%3==0 and i%5==0:
            print("FizzBuzz")
            fizzbuzz+=1
        elif i%3==0:
            print("Fizz")
            fizz+=1
        elif i%5==0:
            print("Buzz")
            buzz+=1
        elif i%7==0:
            continue
        else:
            print(i)
    print("--- Summary ---")
    print("Fizz count : " + str(fizz))
    print("Buzz count : " + str(buzz))
    print("FizzBuzz count : " + str(fizzbuzz))

def pattern():
    n = input("Please enter a number between 3 and 9:\n")
    n = int(n)
    for i in range(1,2*n,1):
        k = n-abs(n-i)
        for j in range(1,k+1,1):
            print(j,end="")
        print("\n")

sequence()
fizzbuzz()
pattern()



