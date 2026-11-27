import sys
count = 0
for i in range(int(input())):
    flag = True

    a = sys.stdin.readline().rstrip()

    check = [a[0]]
    for j in a[1:]:
        if j != check[-1] and j in check:
            flag = False
            break
        check.append(j)

    if flag:
        count += 1

print(count)