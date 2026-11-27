import sys

input = sys.stdin.readline
n, m = map(int, input().split())
base = []
for a in range(n):
    base.append(input().rstrip())  # 입력값 저장

p1 = 'WBWBWBWB'


def dif(inp, p):
    return len([1 for d in range(8) if inp[d] != p[d]])


result = []
for i in range(n - 7):
    for j in range(m - 7):  # 체스판 범위결정

        lines = [b[j:j + 8] for b in base[i:i + 8]]  # 체스판 결정

        diffs = []
        for k in range(8):
            c = dif(lines[k], p1)
            diffs.append(c if k % 2 == 0 else 8 - c)

        total = sum(diffs)
        result.append(total if total <= 32 else 64 - total)

print(min(result))