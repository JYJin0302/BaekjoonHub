import sys
a = [True]*(123456*2+1)
a[0] = False
a[1] = False

for i in range(2,123456*2+1):
    if a[i]:
        for j in range(2*i, 123456*2+1, i):
            a[j] = False
        
while 1:
    inp = int(sys.stdin.readline())
    if inp == 0:
        break
    count = 0
    for i in range(inp+1, 2*inp +1):
        if a[i]:
            count +=1
    print(count)