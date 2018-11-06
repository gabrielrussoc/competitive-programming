import random

n = 100000
q = 100000

print(n, q)

for i in range(q):
    a = random.randint(0, n)
    b = random.randint(a+1, n)
    print(a, b)

