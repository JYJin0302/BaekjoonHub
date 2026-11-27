def special_sum(n):
    for i in str(n):
        n += int(i)
    return n


a = int(input())
check = 0
for i in range(len(str(a)) * 9, 0, -1):
    if a <= i: continue
    if special_sum(a-i) == a:
        print(a - i)
        check = 1
        break
if not check:
    print(0)