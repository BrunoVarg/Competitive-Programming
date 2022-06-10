n = int(input())

inicio = 0
tempo = []
mensagens = []
enviadas = []
soma = 0
for x in range(n):
    tipo,num = input().split()
    num = int(num)
    if x == n-1:
        tempo.pop()
    if tipo == 'T':
        tempo.append(num)
    else:
        if x!=0:
            tempo.append(1)
        mensagens.append([tipo,num])
    if tipo == 'E':
        if num not in enviadas:
            enviadas.append(num)

enviadas.sort()

for x in enviadas:
    for y in range(len(mensagens)):
        if x == mensagens[y][1]:
            if mensagens[y][0] == 'R' and inicio==0:
                inicio = y
            if mensagens[y][0] == 'E':
                termino = y
    for j in range(inicio, termino):
        soma += tempo[j]
    
    if soma ==0:
        soma = -1
    print(f'{x} {soma}')
    soma = 0
    inicio = 0

print(tempo)
    

