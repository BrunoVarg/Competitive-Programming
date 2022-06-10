import itertools
n, m, k = [int(i) for i in input().split()]
senha = input()
lista = []
orden = []
for i in range(m):
    cod = input()
    lista.append(cod)
p = int(input())


perm  = list(itertools.permutations(lista))

print(perm)

if m==1:
    for x in range(k):
        orden.append(lista[0][x])
        
orden.sort()
    
x = orden[p-1]
new = ''
i = 0
for y in range(len(senha)):
    if senha[y]=='#':
        new+= x[i]
        i+=1
    else:
        new+=senha[y]

print(new)