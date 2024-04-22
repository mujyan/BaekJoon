while True:
    w = input()
    if w == '0':
        break
    else:
        w = list(map(int, w.split()))
    cur = 1
    for i in range(1, len(w), 2):
        cur *= w[i]
        cur -= w[i+1]
    print(cur)