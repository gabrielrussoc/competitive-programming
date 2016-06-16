memo = {}

def solve(a):
    if a == 1:
        return 0
    if a in memo:
        return memo[a]
    
    if a&1:
        memo[a] = 1 + solve(3*a + 1)
    else:
        memo[a] = 1 + solve(a//2)
    return memo[a]

ans = 0
maxi = 0
for i in range(1,1000000):
    if solve(i) > maxi:
        maxi = solve(i)
        ans = i
print(ans)
