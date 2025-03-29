def cyclic_shifts(s):
    n = len(s)
    double_s = s + s
    mn_s = s
    for i in range(1, n):
        current_shift = double_s[i:i + n]
        if current_shift < mn_s:
            mn_s = current_shift
    return mn_s


s = input()
print(cyclic_shifts(s))