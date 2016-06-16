d = [31,28,31,30,31,30,31,31,30,31,30,31]
w = 1
y = 1900

ans = 0

while y < 2001:
    f = 0
    if (y % 4 == 0 and y % 100 != 0) or y % 400 == 0:
        f = 1
    for i in range(12):
        q = d[i]
        if i == 1:
            q += f
        for j in range(q):
            if j == 0 and w == 0 and y > 1900:
                ans += 1
            w += 1
            w = w % 7
    y += 1
print(ans)
        

