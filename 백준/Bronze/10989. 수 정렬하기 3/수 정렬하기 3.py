import sys

input = sys.stdin.readline

n = int(input())
count = [0] * 10001
result = [0] * 10001
for i in range(n):
    count[int(input())] += 1

for i in range(10001):
    count_num = count[i]
    if count_num != 0:
        for j in range(count_num):
            print(i)
                     