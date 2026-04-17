def remove_duplicates(data_list):
    s = set()
    for x in data_list:
        s.add(x)
    l = []
    for x in s:
        l.append(int(x))
    return l

def strip_whitespaces(string_list):
    l = []
    for s in string_list:
        s = s.strip(" ")
        l.append(int(s))
    return l
