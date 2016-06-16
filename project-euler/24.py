def fat(n): return 1 if n == 0 else n * fat(n-1)

p = 999999
n = 10
v = [x for x in range(n)]
ans = ""
for i in range(n):
    for j in range(len(v)-1,-1,-1):
        a = fat(n-i-1)*j
        if a <= p:
            p -= a
            ans += str(v[j])
            del v[j]
            break

print(ans)

