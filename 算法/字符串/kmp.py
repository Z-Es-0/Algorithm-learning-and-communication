def build_next(s):
    next=[0]
    l=0
    i=1
    while i <len(s):
        if s[l]==s[i]:
            l+=1
            next.append(l)
            i+=1
        else:
            if l==0:
                next.append(0)
                i+=1
            else:
                l=next[l-1]
    return next

def kmp(s,ned):
    next=build_next(s)
    i=0
    j=0
    while i<len(s):
        if s[i]==ned[j]:
            i+=1
            j+=1
        elif j>0:
            j=next[j-1]
        else:
            i+=1
        if j ==len(ned):
            return i - j
    return -1
if __name__=='__main__':
    s=input()
    y=input()
    print(build_next(s))
    print(kmp(s,y))