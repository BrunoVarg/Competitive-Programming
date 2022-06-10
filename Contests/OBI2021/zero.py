n = int(input())
lista = []
soma = 0

for x in range(n):
    num = int(input())
    if num == 0:
        lista.pop()
    else:
        lista.append(num)

for x in lista:
    soma+=x

print(soma)