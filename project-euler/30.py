ans = 0
for x in range(2,300000):
    if sum(map(lambda x : x**5,map(int,str(x)))) == x:
       ans += x
print(ans)
