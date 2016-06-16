num = ['','one','two','three','four','five','six','seven','eight','nine','ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen',
    'eighteen','nineteen']
dez = ['twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety']
hun = 'hundred'

def solve(n):
    s = ""
    if n >= 100 and n % 100 != 0:
        s += "and"
    if n == 1000:
        s = s + 'onethousand'
        n = n - 1000
    if n >= 100:
        a = n // 100
        s = s + num[a]
        s = s + hun
        n = n - a*100
    if n >= 20:
        a = n // 10
        s = s + dez[a-2]
        a = n % 10
        s = s + num[a]
    else:
        s = s + num[n]
    return len(s)

ans = 0
for i in range(1,1001):
    ans = ans + solve(i)
print(ans)
