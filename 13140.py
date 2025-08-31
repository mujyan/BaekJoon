import sys
def input():
    return sys.stdin.readline().rstrip()
N = int(input())
for h in range(1, 10):
    for e in range(10):
        if h==e:
            continue
        for l in range(10):
            if l in [h, e]:
                continue
            for o in range(10):
                if o in [h, e, l]:
                    continue
                
                hello = (h*10000 + e*1000 + l*100 + l*10 + o)
                cur = N-hello
                if cur <= 0 :
                    print(f"No Answer")
                    exit(0)
                cur = str(cur)
                chk = set(cur)
                # 5자리 수인가, 5개의 숫자로 이루어져있는가, w가 0인가
                if len(cur) != 5 or len(chk) != 5 or cur[0]=='0':
                    continue
                chk_byint = [int(tmp) for tmp in cur]
                if len(set([h, e, l, o] + chk_byint))!=7:
                    continue
                # o, l 검사
                if int(cur[1]) == o and int(cur[3]) == l:
                    print(f"  {(h*10000 + e*1000 + l*100 + l*10 + o)}")
                    print(f"+ {cur}")
                    print("-------")
                    print(f"{' '*(7-len(str(N)))}{N}")
                    exit(0)
print("No Answer")