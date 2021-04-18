a, b, c = input().split(" ")

a = float(a)
b = float(b)
c = float(c)

dis = ((b**2) - (4*a*c))**0.5

if(a != 0):
    if(dis > 0.0):
        x1 = ((-1*b) + dis)/(2*a)
        x2 = ((-1*b) - dis)/(2*a)
        print("R1 = %.5f" % x1)
        print("R2 = %.5f" % x2)
    else:
        print("Impossivel calcular")
else:
    print("Impossivel calcular")
