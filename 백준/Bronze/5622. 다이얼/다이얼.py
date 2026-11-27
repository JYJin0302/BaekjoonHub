count = 0
for i in input():
    if 'A'<= i <= 'C':
        count += 3
    elif 'D' <= i <= 'F':
        count += 4
    elif 'G' <= i <= 'I':
        count += 5
    elif 'J' <= i <= 'L':
        count += 6
    elif 'M' <= i <= 'O':
        count += 7
    elif 'P' <= i <= 'S':
        count += 8
    elif 'T' <= i <= 'V':
        count += 9
    else:
        count += 10
print(count)