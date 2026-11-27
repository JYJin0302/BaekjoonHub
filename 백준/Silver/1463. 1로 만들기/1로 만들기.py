n = int(input())
base = [0, 0, 1, 1]  # 0, 1, 2, 3에서의 횟수
for i in range(4, n + 1):
    check = [base[i - 1]]
    if i % 2 == 0:
        check.append(base[i // 2])
    if i % 3 == 0:
        check.append(base[i // 3])
    base.append(min(check) + 1)
print(base[n])
