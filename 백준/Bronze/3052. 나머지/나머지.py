a = [0]*42
for i in range(10):
    a[int(input())%42] = 1
print(a.count(1))