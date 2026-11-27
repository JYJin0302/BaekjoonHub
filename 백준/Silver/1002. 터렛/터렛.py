from math import sqrt

result = []
for i in range(int(input())):
    case = list(map(lambda x: int(x), input().split()))
    d = sqrt((case[0] - case[3]) ** 2 + (case[1] - case[4]) ** 2)
    r1 = min(case[2], case[5])
    r2 = max(case[2], case[5])
    if d == 0 and r1 == r2:
        result.append(-1)
    elif d == r1 + r2 or d == r2 - r1:
        result.append(1)
    elif d < r2 - r1 or d > r1 + r2:
        result.append(0)
    else:
        result.append(2)

for i in result:
    print(i)