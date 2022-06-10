n, c = [int(i) for i in input().split()]
infec = [0]*n
transm = []
result = []

for x in range(c):
    prov = [int(i) for i in input().split()]
    transm.append(prov)
    
for x in range(len(transm)):
    for y in range(2, len(transm[x])):
        pessoa = transm[x][y]-1
        infec[pessoa]=1
            
for x in range(len(infec)):
    if infec[x] == 0:
        result.append(x+1)

result.sort()
for x in result:
    print(x)
