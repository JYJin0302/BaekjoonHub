base = [666,1666]
n = int(input())

test = 2666
while len(base)<n:
    if '666' in str(test):
        base.append(test)
    test+=1
print(base[n-1])