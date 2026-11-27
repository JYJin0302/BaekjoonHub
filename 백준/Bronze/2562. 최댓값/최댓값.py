max = 0
index = 0
for i in range(9):
    inp = int(input())
    if inp > max:
        max = inp
        index = i + 1
print(max)
print(index)