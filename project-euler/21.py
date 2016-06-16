def calc(n):
    i = 2
    ans = 1
    while i*i < n:
        if n % i == 0:
            ans += i + n//i
        i += 1
    if i*i == n:
        ans += i
        
    return ans


v = [calc(i) for i in range(10001)]
v[1] = 0

def good(a):
    b = v[a]
    if (b > 10000 or a == b):
        return False
    if a == v[b]:
        return True
    return False

ans = 0
for i in range(2,10001):
    if good(i):
        ans += i

print(ans)
