lst = ['-1']*26
inp = input()
for i in range(ord('a'), ord('z') + 1):
    if chr(i) in inp:
        lst[i - ord('a')] = str(inp.index(chr(i)))
print(' '.join(lst))