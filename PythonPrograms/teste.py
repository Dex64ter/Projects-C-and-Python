def solution(s):
    if s == "":
        return []
    elif len(s)%2 == 0:
        l = []
        for j in range(0,len(s),2):
            l.append(s[j]+s[j+1])
        return l
    else:
        l = []
        for j in range(0,len(s)-1,2):
            l.append(s[j]+s[j+1])
        l.append(s[-1]+"_")
        return l
    
print(solution("asdfads"))