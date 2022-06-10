n = int(input())
num = '0123456789'
simb = '[{('
d = {'(':')', '{':'}', '[':']'}
for y in range(n):
    s = input()
    lista = []
    for x in range(len(s)):
        lista.append(s[x])
    for x in range(len(lista)):
        brk = False
        if lista[x] in simb:
            find = lista[x]
            for y in range(x, len(lista)):
                if d[find] == lista[y]:
                    if lista[x+1] == find and lista[y+1] == lista[y]:
                        brk = True
                        print('A expressão possui duplicata.')
                        break
            if brk:
                break
    if not brk:
        print('A expressão não possui duplicata.')
                        
                

    

