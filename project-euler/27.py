N = 100000
v = [0 for x in range(N)]
def crivo():
    i = 2
    while i*i < N:
        j = i*i
        while j < N:
            v[j] = 1
            j += i
        i += 1

def count(a,b):
    n = 0
    while True:
        if abs(v[n*n + a*n + b]) != 0:
            break
        n += 1
    return n

ans = 0
maxn = 0
crivo()
for i in range(-1000,1001):
    for j in range(-1000,1001):
        c = count(i,j)
        if c > maxn:
            maxn = c
            ans = i*j

print(ans)
