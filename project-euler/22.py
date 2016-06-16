def get(s):
    ans = 0
    for i in range(len(s)):
        ans += ord(s[i])-ord('A')+1
    return ans
v = list(map(lambda x : x[1:-1],input().split(',')))
v.sort()
ans = 0
for i in range(len(v)):
    ans += (i+1)*get(v[i])
print(ans)
