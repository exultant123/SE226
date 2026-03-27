unique = set()
dict= {}
freq = {}
def popular():
    itempop = ""
    max = -1
    for item in freq:
        if freq[item]>max:
            itempop = item
            max=freq[item]
    return itempop
def check(item):
    cnt = 0
    for name in dict:
        if item in dict[name]:
            cnt+=1
    freq[item] = cnt
    return cnt
def user():
    name = (input('Enter username: '))
    dict[name] = []
    m = int(input('How many items? '))
    i=1
    while m>0:
        item = (input(f'Item {i}: '))
        dict[name].append(item)
        unique.add(item)
        i+=1
        m-=1

n = int(input('Enter number of users: '))
while n>0:
    user()
    n-=1
print("USER DATA:")
for name in dict:
    print(name + " -> ", end="") 
    print(dict[name])
print("COMMON ITEMS:")
for item in unique:
    if check(item)>1:
        print(item)
print("UNIQUE ITEMS:")
for item in unique:
    if check(item)==1:
        print(item)
print("MOST POPULAR ITEM:")
print(popular())
# print("COMMON ITEMS:")
# for item in unique:
#     if not check(item):
#         print(item)
# print("UNIQUE ITEMS:")
# for item in unique:
#     if check(item):
#         print(item)
