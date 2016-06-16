v = []
tam = 100
for i in range(tam):
    v.append(list(map(int,input().split())))


dp = [[0 for x in range(y+1)] for y in range(tam)]

for i in range(tam):
    dp[tam-1][i] = v[tam-1][i]

for i in range(tam-2,-1,-1):
    for j in range(i+1):
        dp[i][j] = v[i][j] + max(dp[i+1][j], dp[i+1][j+1])

print(dp[0][0])
