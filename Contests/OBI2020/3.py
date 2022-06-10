n, k, u = [int(i) for i in input().split()]
cartelas = []
pontos = [0]*n
for x in range(n):
    lista = [int(i) for i in input().split()]
    cartelas.append(lista)

sorteados = [int(i) for i in input().split()]

for x in range(len(sorteados)):
    for y in range(n):
        if sorteados[x] in cartelas[y]:
            pontos[y] +=1
    if k in pontos:
        break

for x in range(len(pontos)):
    if pontos[x] == k:
        print(x+1, end = " ")

    