import sys
read = sys.stdin.readline

n1, n2, n3 = 0, 0, 0  # 더한 값를 저장
for _ in range(int(read())):
    r1, r2, r3 = map(int, read().split())
    n1, n2, n3 = r1 + min(n2, n3), r2 + min(n1, n3), r3 + min(n1, n2)

print(min(n1, n2, n3))