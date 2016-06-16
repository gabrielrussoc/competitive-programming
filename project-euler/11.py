a = []

for i in range(20):
    b = list(map(int,input().split()))
    a.append(b)


ans = 0
for i in range(20):
    for j in range(17):
        ans = max(ans, a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j+3])


for i in range(17):
    for j in range(20):
        ans = max(ans, a[i][j] * a[i+1][j] * a[i+2][j] * a[i+3][j])

for i in range(17):
    for j in range(17):
        ans = max(ans, a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3])

for i in range(17):
    for j in range(3, 20):
        ans = max(ans, a[i][j] * a[i+1][j-1] * a[i+2][j-2] * a[i+3][j-3])

print(ans)

