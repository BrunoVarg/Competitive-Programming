n = int(input())
v = []
min = []
for _ in range(n):
    op = input().split()
    if(op[0]=='PUSH'):
        elem = int(op[1])
        v.append(elem)
        
        if(len(min)==0):
            min.append(elem)
        else:
            last = min[len(min)-1]
            if elem<last:
                min.append(elem)
            else:
                min.append(last)
    elif(op[0]=='POP'):
        v.pop()
        min.pop()
    else:
        if(len(min)==0):
            print('EMPTY')
        else:
            print(min[len(min)-1])