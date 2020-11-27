num = float(input())

if((num >= 0) and (num <= 25.0000)):
    print("Intervalo [0,25]")
elif((num > 25.0000) and (num <= 50.000000)):
    print("Intervalo (25,50]")
elif((num > 50.000000) and (num <= 75.00000)):
    print("Intervalo (50,75]")
elif((num > 75.000000) and (num <= 100.00000)):
    print("Intervalo (75,100]")
else:
    print("Fora de intervalo")