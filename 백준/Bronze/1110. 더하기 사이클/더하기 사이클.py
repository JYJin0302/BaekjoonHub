ini = int(input())
if ini < 10:
    str_num = '0' + str(ini)
else:
    str_num = str(ini)

count = 0
while True:
    result = sum([int(i) for i in str_num])
    count += 1
    str_num = str_num[-1] + str(result)[-1]
    if int(str_num) == ini:
        break

print(count)