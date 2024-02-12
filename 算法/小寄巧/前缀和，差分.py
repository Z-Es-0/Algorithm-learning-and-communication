s=[2,3,8,9,1,3,56,7,8,3,4]
g=[]#前缀和数组
o=0
for i in s:
    o+=i
    g.append(o)
print(g)#前缀和

lst=s[0]
diff=[s[0]]
for i in range(1,len(s)):
    diff.append(s[i]-lst)
print(diff)

def cafen(s):
    '''差分数组'''
    lst=s[0]
    diff=[s[0]]
    for i in range(1,len(s)):
        diff.append(s[i]-lst)
        lst=s[i]
    return diff
print(cafen(g))#前缀和差分回去
