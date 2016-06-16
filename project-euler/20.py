def fat(n): return 1 if n == 0 else n * fat (n-1)
print(sum(map(int,str(fat(100)))))
