v = []
def go(n):
    ans = 1
    i = 2
    while i*i < n:
        if n % i == 0:
            ans += i + n//i
        i += 1
    if i*i == n:
        ans += i
    if ans > n:
        return True
    return False

def go2(n):
    i = 0
    j = len(v)-1
    for k in v:
        if k+k == n:
            return False
    while i < j:
        if v[i]+v[j] > n:
            j -= 1
        elif v[i]+v[j] < n:
            i += 1
        else:
            return False
    return True

for i in range (2, 28124):
    if go(i):
        v.append(i)

ans = 0
for i in range(1, 28124):
    if go2(i):
        ans += i
print(ans)
