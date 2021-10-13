num = input()

n = int(input())
count=0
d = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
for x in range(n):
    s = input()
    passa = True
    if(len(num) == len(s)):
        for y in range(len(s)):
            if(s[y] not in d[num[y]]):
                passa = False
                break
        if(passa):
            count+=1
print(count)