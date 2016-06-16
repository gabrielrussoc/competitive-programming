n = 1
s = 0
ans = 0

def get_div(s):
    i = 1
    ret = 0
    while i*i < s:
        if s % i == 0:
            ret += 2
        i += 1
    if i*i == s:
        ret += 1
    return ret

while ans <= 500:
    s += n
    n += 1
    ans = max(ans, get_div(s))

print(s)
    
