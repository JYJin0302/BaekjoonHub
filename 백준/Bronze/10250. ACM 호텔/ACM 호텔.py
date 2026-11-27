for i in range(int(input())):
    h, w, n = map(int, input().split())
    h_f = n%h
    if h_f == 0:
        h_f = h
    
    w_f = str(int(n/h + 0.999))
    if len(w_f) == 1:
        w_f = '0' + w_f
     
    print(f'{str(h_f)}{w_f}')