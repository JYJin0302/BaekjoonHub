n = int(input())
n0 = 0
n1 = n2 = n3 = n4 = n5 = n6 = n7 = n8 = n9 = 1  #끝자리가 i인 계단 수 개수
for _ in range(n - 1):
    n0, n1, n2, n3, n4, n5, n6, n7, n8, n9 = \
    n1, n0 + n2, n1 + n3, n2 + n4, n3 + n5, n4 + n6, n5 + n7, n6 + n8, n7 + n9, n8
print((n0 + n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9) % 1000000000)
