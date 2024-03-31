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
    if not(isinstance(a, list)):
        return [a]
    else:
        return a

def compare_single(l, r):
    for i in range(0, len(l)):
        # print(l[i])
        # print(r[i])
        try:
            li = l[i]
            ri = r[i]
            if (li<ri):
                return True
            elif (li>ri):
                return False
        except TypeError:
            ll = check_and_convert_to_list(li)
            rl =check_and_convert_to_list(ri)
            if (ll < rl):
                return True
            elif (ll > rl):
                return False
        except IndexError:
            return False
        # Left side is exhausted:
        if i==len(l)-1:
            return True



# test_l = [[4,4],4,4]
# test_r = [[4,4],4,4,4]
# print(compare_single(test_l, test_r))

res = [None]
for i in range(0, len(left)):
    print(left[i])
    print(right[i])
    print(compare_single(left[i], right[i]))


# 238 is too low...