import pprint

# Taking way too long to build a parser for this in C++
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

def parse_part_two(filename):
    d = []
    with open(filename, "r") as f:
        for line in f:
            d.append(line)
    d = [i.strip("\n") for i in d]
    d = [i for i in d if i!='']
    d = [eval(i) for i in d]
    d.append([[2]])
    d.append([[6]])
    return d

def check_and_convert_to_list(a):
    if not(isinstance(a, list)):
        return [a]
    else:
        return a

def compare_atom(li, ri):
    if isinstance(li, int) & isinstance(ri, int):
            if li < ri:
                return True
            elif ri < li:
                return False
    # If both lists:
    elif isinstance(li, list) & isinstance(ri, list):
        for j in range(0, max(len(li), len(ri))):
            try:
                lij = li[j]
            except IndexError:
                return True # Left side ran out of items
            try:
                rij = ri[j]
            except IndexError:
                return False # Right side ran out of items
            if compare_atom(lij, rij) is True:
                return True
            elif compare_atom(lij, rij) is False:
                return False
    # If mix of list and int:
    elif isinstance(li, list) & isinstance(ri, int) | isinstance(li, int) & isinstance(ri, list):
        lil = check_and_convert_to_list(li)
        ril = check_and_convert_to_list(ri)
        for j in range(0, max(len(lil), len(ril))):
            try:
                lilj = lil[j]
            except IndexError:
                return True # Left side ran out of itetms
            try:
                rilj = ril[j]
            except:
                return False # Right side ran out of items
            if compare_atom(lilj, rilj) is True:
                return True
            elif compare_atom(lilj, rilj) is False:
                return False

def compare(l, r):
    for i in range(0, max(len(l), len(r))):
        try:
            li = l[i]
        except IndexError:
            return True
        try:
            ri = r[i]
        except IndexError:
            return False
        b = compare_atom(li, ri)
        if b is False:
            return False
        if b is True:
            return True
    return True

def insertion_sort(ls):
    for i in range(1, len(ls)):
        key = ls[i]
        j = i-1
        while j >= 0 and compare(key, ls[j]) :
                ls[j + 1] = ls[j]
                j -= 1
        ls[j + 1] = key
    return ls

def get_sum_idxs_part_2(ls):
    a = ls.index([[2]])
    print(a)
    b = ls.index([[6]])
    print(b)
    return (a+1)*(b+1)

def get_result_part_one(filename):
    left, right = parse_part_one(filename)
    res = []
    for i, v in enumerate(range(0, len(left))):
        print(left[i])
        print(right[i])
        print(compare(left[i], right[i]))
        if compare(left[i], right[i]):
            res.append(i+1)
    print(sum(res))

def get_result_part_two(filename):
    d = parse_part_two(filename)
    d_sorted = insertion_sort(d)
    pprint.pprint(d_sorted)
    res = get_sum_idxs_part_2(d_sorted)
    print(res)


def test_compare():
    l = [1,[2,[3,[4,[5,6,7]]]],8,9]
    r = [[1],4] # Wnat this to return true
    res = compare(l, r)
    print(res)
# test_compare()

get_result_part_one("day13/data.txt")
get_result_part_two("day13/data.txt")


