# Taking way too long to build a parser for this in C++
import itertools

d = []
with open("data.txt", "r") as f:
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
    if not(isinstance(a, list)):
        return [a]
    else:
        return a

def compare_single(l, r):
    z = itertools.zip_longest(l, r)
    for i in z:
        l, r = i
        l = check_and_convert_to_list(l)
        r = check_and_convert_to_list(r)
        print(l)
        print(r)
        # Check lengths:
        if (len(l)==0) & (len(r)>0):
            return True
        elif (len(l)>0) & (len(r)==0):
            return False
        # Check Nones
        elif (l[0] is None) & (r[0] is not None):
            return True
        elif (l[0] is not None) & (r[0] is None):
            return False
        # Check values
        elif (l[0]<r[0]):
            return True
        elif (l[0]>r[0]):
            return False
        # If we haven't broken yet, continue...
        else:
            result = compare_single(l[1:], r[1:])
            if result is not None:
                return result


# test_l = [7,7,7,7]
# test_r = [7,7,7]
# print(compare_single(test_l, test_r))

res = [None]
for i in range(0, len(left)):
    print(left[i])
    print(right[i])
    c = compare_single(left[i], right[i])
    res.append(c)

trues = [i for i,v in enumerate(res) if v is True]
print(sum(trues))

# 238 is too low...