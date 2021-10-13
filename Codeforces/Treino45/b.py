s = input()

names = ['danil','olya', 'slava','ann', 'nikita']
count = 0

for x in names:
    for y in s:
        y.lower()
        if(x in y):
            count+=1

if(count==1):
    print('YES')
else:
    print('NO')