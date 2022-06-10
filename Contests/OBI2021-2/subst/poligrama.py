n = int(input())
string = input()

lista = []

for x in range(len(string)):
    for y in range(x+1,len(string)):
        lista = string[x:y+1]
        d = {}
        for x in range(len(lista)):
            if lista[x] not in d:
                d[lista[x]] = 1
            else:
                d[lista[x]] += 1
        tam = len(lista)
        for x, y in d.items():
            if 