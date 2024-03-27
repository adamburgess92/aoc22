# Taking way too long to build a parser for this in C++
import itertools

d = []
with open("test_data.txt", "r") as f:
    for line in f:
        d.append(line)
# Clean up text
d = [i.strip("\n") for i in d]
d = [i for i in d if i!='']
# Split into left/right, evaluate text
left = d[0::2]
right = d[1::2]
left = [eval(i) for i in left]
right = [eval(i) for i in right]
assert len(left)==len(right), "left and right should have same length"

def check_and_convert_to_list(a):
    if not(type(a))==list:
        return [a]
    else:
        return a

def compare_single(l: list, r:list) -> bool:
    # print(l)
    # print(r)
    if (len(r)==0):
        return True
    z = itertools.zip_longest(l, r)
    for i in z:
        l, r = i
        l = check_and_convert_to_list(l)
        r = check_and_convert_to_list(r)
        # print(l)
        # print(r)
        # Otherwise...
        if (l[0]==None):
            return True
        if (l[0]<=r[0]):
            compare_single(l[1:], r[1:])
        else:
            # print("incorrect order")
            # return False
            raise RecursionError("X")
    return True

def compare(l:list, r:list):
    try: 
        b = compare_single(l, r)
    except:
        b = False
    return b

test_l = []
test_r = [3]
print(compare(test_l, test_r))

res = [None]
for i in range(0, len(left)):
    print(left[i])
    c = compare(left[i], right[i])
    res.append(c)

trues = [i for i,v in enumerate(res) if v is True]
print(sum(trues))

# 238 is too low...