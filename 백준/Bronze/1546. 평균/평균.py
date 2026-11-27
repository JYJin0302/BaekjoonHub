n = int(input())
a = list(map(int, input().split()))
m = max(a)
print(sum(list(map(lambda x: x/m*100, a)))/n)