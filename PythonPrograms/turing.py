# Testaremos aqui algumas questões
# da gupy
def func(x,y):
    if y ==0:
        return 0
    elif y == 1:
        return x
    else:
        return x + func(x, y-1)
    
print(func(14,60))