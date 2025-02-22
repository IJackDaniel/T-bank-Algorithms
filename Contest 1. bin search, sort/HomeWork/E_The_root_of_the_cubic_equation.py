def f(n1, n2, n3, n4, x):
    return n1 * (x ** 3) + n2 * (x ** 2) + n3 * x + n4


a, b, c, d = map(int, input().split())

l = -1e10 - 1
r = 1e10 + 1
eps = 1e-10
x = None

while abs(r - l) >= eps:
    x = (l + r) / 2
    y1 = f(a, b, c, d, x)
    y2 = f(a, b, c, d, l)

    if y1 * y2 <= 0:
        r = x
    else:
        l = x
print(x)
