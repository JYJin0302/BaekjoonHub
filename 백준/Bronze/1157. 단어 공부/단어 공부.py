inp = input()

base = [0]*26
case = ord('a') - ord('A')
for i in range(ord('A'), ord('Z') + 1):
    base[i - ord('A')] = inp.count(chr(i)) + inp.count(chr(i + case))

max_num = max(base)
if base.count(max_num) > 1:
    print('?')
else:
    print(chr(base.index(max_num) + ord('A')))