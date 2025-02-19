def f(n1, n2, n3, n4, x):
    result = n1 * (x ** 3) + n2 * (x ** 2) + n3 * x + n4
    return result

def main():
    a, b, c, d = map(int, input().split())

    l = -1e6
    r = 1e6 + 10
    eps = 1e-15
    m = 0

    while l < r:
        m = (l + r) / 2.0

        if f(a, b, c, d, l) * f(a, b, c, d, m) < 0:
            r = m
        else:
            l = m

        if abs(f(a, b, c, d, m)) < eps:
            break

    print(m)

if __name__ == "__main__":
    main()
