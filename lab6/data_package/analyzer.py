def calculate_mean(num_list):
    total = 0
    i=0
    for x in num_list:
        total+=x
        i=i+1
    return total/i
def find_maximum(num_list):
    m = num_list[0]
    for x in num_list:
        if x>m:
            m = x
    return m

def find_minimum(num_list):
    m = num_list[0]
    for x in num_list:
        if x < m:
            m = x
    return m
