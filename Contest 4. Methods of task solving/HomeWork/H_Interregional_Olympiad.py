n, c = map(int, input().split())
times = [tuple(map(int, input().split())) + (i,) for i in range(1, n + 1)]
times.sort(key=lambda x: x[1])  # Сортируем по времени окончания

ans = []
cur_end = -1

for start, duration, idx in times:
    end = start + duration
    if start >= cur_end:
        ans.append(idx)
        cur_end = end

total = len(ans) * c
print(total)
print(len(ans))
print(*ans, sep=" ")