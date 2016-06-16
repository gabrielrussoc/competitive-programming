i = 3
f1 = 1
f2 = 1
while True:
    fib = f1+f2
    f1 = f2
    f2 = fib
    if len(str(fib)) >= 1000:
        print(i)
        break
    i += 1

