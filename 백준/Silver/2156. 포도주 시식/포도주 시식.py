base = []
n = int(input())
for i in range(n):
    base.append(int(input()))
if n < 3:
    print(sum(base))
else:
    dp = [base[0], base[0] + base[1], max(base[0], base[1]) + base[2]]
    for i in range(3, n):
        if i == 3:
            dp.append(max(dp[i - 2], max(dp[: i - 2]) + base[i - 1]) + base[i])
        else:
            dp.append(max(dp[i - 2], max(dp[i - 4: i - 2]) + base[i - 1]) + base[i])
    print(max(dp[n - 1], dp[n - 2]))
