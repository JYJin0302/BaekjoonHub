for i in range(int(input())):
    inp = list(map(lambda x: int(x), input().split()))
    start = inp[:2]
    finish = inp[2:]

    count = 0
    for j in range(int(input())):
        inter = 0
        loc = list(map(lambda x: int(x), input().split()))
        if sum(list(map(lambda x, y : (x - y) ** 2, start, loc[:2]))) < loc[2]**2:
            inter += 1
        if sum(list(map(lambda x, y: (x - y) ** 2, finish, loc[:2]))) < loc[2] ** 2:
            inter += 1
            
        if inter == 1:
            count += 1
        
    print(count)    