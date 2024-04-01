# Taking way too long to build a parser for this in C++
import itertools

def parse_part_one(filename):
    d = []
    with open(filename, "r") as f:
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
    return left, right

def check_and_convert_to_list(a):
    if not(isinstance(a, list)):
        return [a]
    else:
        return a

def compare_single(l, r):
    if len(l)==0: 
        return True
    if len(r)==0:
        return False
    for i in range(0, len(l)):
        try:
            li = l[i]
            ri = r[i]
            if (li<ri):
                return True
            elif (li>ri):
                return False
        except TypeError:
            ll = check_and_convert_to_list(li)
            rl = check_and_convert_to_list(ri)
            for j in range(0, len(ll)):
                # Left is int, right still contains lists
                if isinstance(ll[j], int) & ~isinstance(rl[j], int):
                    return True
                # Left still contains lists, right is int
                if ~isinstance(ll[j], int) & isinstance(rl[j], int):
                    return False
                try:
                    if (ll[j] < rl[j]):
                        return True
                    elif (ll[j] > rl[j]):
                        return False
                except TypeError:
                    continue
        except IndexError:
            return False
        # Left side is exhausted:
        if i==len(l)-1:
            return True

def get_result_part_one(filename):
    left, right = parse_part_one(filename)
    res = []
    for i, v in enumerate(range(0, len(left))):
        print(left[i])
        print(right[i])
        print(compare_single(left[i], right[i]))
        if compare_single(left[i], right[i]):
            res.append(i+1)
    print(sum(res))

get_result_part_one("day13/data.txt")