def array_diff(a,b):    
    for i in b:
        while i in a:
            a.remove(i)

    return a

print(array_diff([1,2,2,2,3,2,2,4,5],[2,5]))
