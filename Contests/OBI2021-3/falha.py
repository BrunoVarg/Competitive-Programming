n = int(input())
lista = []
d = {}
for x in range(n):
    s = input()
    if s not in d:
        d[s]= 1
    else:
        d[s]+=1
    lista.append(s)
count=0
lista_ord = sorted(lista, key=len)
for x in range(len(lista_ord)):
    for y in range(x+1, len(lista_ord)):
        if lista_ord[x] in lista_ord[y]:
            count+=1
            if lista_ord[x]==lista_ord[y]:
                count+=1


print(count)