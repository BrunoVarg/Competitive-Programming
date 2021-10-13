a = input()
b = input()
c = input()
d = input()
e = input()
f = input()
lista = [a,b,c,d,e,f]
countv = 0
countp = 0
n = 6
for x in range(n):
    if lista[x] == 'V':
        countv+=1
    else:
        countp+=1

if countv>=5:
    print(1)
elif countv>=3:
    print(2)
elif countv>=1:
    print(3)
elif countv==0:
    print(-1)
