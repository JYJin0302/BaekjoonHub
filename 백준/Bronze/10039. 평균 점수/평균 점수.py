import sys
result = 0
for i in sys.stdin:
    if int(i) < 40:
        i = '40'
    result += int(i)
print(result//5)