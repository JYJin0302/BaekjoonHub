def is_hans(n):
    digit = list(str(n))
    diff = []
    for i in range(len(digit) - 1):
        diff.append(int(digit[i]) - int(digit[i + 1]))
    if len(set(diff)) == 1:
        return True
    return False

n = int(input())
if n < 100:
    print(n)
else:
    count = 0
    for i in range(100, n+1):
        if is_hans(i):
            count += 1
    print(count + 99)