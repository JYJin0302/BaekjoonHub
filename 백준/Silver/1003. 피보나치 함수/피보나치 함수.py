def fibonacci(n):
    a = 1
    b = 1
    for i in range(n - 2):
        a, b = b, a + b
    return b

res = []
for i in range(int(input())):
    inp = int(input())
    if inp == 0:
        result = [1, 0]
    elif inp == 1:
        result = [0, 1]
    else:
        result = [fibonacci(inp - 1), fibonacci(inp)]
    res.append(result)
for i in res:
    print(i[0], i[1])