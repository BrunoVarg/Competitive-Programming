cartas = input()
countc=0
counte=0
counto=0
countp=0
repetcopas = False
repetespadas = False
repetouros = False
repetpaus = False
copas =[0]*13
espadas = [0]*13
ouros = [0]*13
paus = [0]*13
aux = []
baralho = []
i=0
atual = ''

for x in range(len(cartas)):
    if x== len(cartas)-1:
        baralho.append(aux)
    
    if i !=3:
        aux.append(cartas[x])
    else:
        baralho.append(aux)
        i=0
        aux = []
        aux.append(cartas[x])
    i+=1

for x in range(len(baralho)):
    num = int(baralho[x][0] + baralho[x][1])
    naipe = baralho[x][2]
    if naipe == 'C':
        copas[num-1] += 1
        if copas[num-1] >=2:
            repetcopas = True
        countc+=1
    elif naipe == 'E':
        espadas[num-1] += 1
        if espadas[num-1] >=2:
            repetespadas = True
        counte+=1
    elif naipe == 'U':
        ouros[num-1] += 1
        if ouros[num-1] >=2:
            repetouros = True
        counto+=1
    elif naipe == 'P':
        paus[num-1] += 1
        if paus[num-1] >=2:
            repetpaus = True
        countp+=1

if repetcopas == True:
    print('erro')
else:
    calc = 13-countc
    print(calc)

if repetespadas == True:
    print('erro')
else:
    calc = 13 - counte
    print(calc)

if repetouros == True:
    print('erro')
else:
    calc = 13-counto
    print(calc)

if repetpaus == True:
    print('erro')
else:
    calc = 13 - countp
    print(calc)


