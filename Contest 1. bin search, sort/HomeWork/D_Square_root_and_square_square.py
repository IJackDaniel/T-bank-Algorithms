def bin_search(c):
    l = -1
    r = 1e5
    eps = 1e-10

    while r - l >= eps:
        m = (l + r) / 2

        if m ** 2 + (m + 1) ** 0.5 < c:
            l = m
        else:
            r = m
    
    return m

c = float(input())

result = bin_search(c)
print(result)