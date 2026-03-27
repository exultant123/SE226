unique = set()
dict= {}
def user():
    name = (input('Enter username: '))
    
    m = int(input('How many items? '))
    l = []
    i=1
    while m>0:
        item = (input(f'Item {i}: '))
        l.append(item)
        i+=1
        m-=1
    dict[name].append(l)
    print(dict)

n = int(input('Enter number of users: '))
while n>0:
    user()
    n-=1

print(f'Sum of {a} and {b} is {sum(a, b)}')
