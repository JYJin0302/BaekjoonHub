def is_prime(n):
    if n <= 1:
        return False
    if n == 2 or n == 3 or n == 5 or n == 7:
        return True
    if n % 2 == 0 or n % 3 == 0 or n % 5 == 0 or n % 7 == 0:
        return False
    for i in range(11, int(n**0.5)+1, 2):
        if n % i == 0:
            return False
    return True
a, b = map(int, input().split())
for i in range(a, b+1):
    if is_prime(i):
        print(i)