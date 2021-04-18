while True:
    try:
        x1, y1, x2, y2 = input().split(" ")

        x1 = int(x1)
        y1 = int(y1)
        x2 = int(x2)
        y2 = int(y2)

        if ((1 <= x1) and (y2 <= 8)):
            if((x1 == x2) and (y1 == y2)):
                print(0)
            elif(((x1 == x2) and (y1 != y2)) or ((x1 != x2) and (y1 == y2))):
                print(1)
            elif(((x2 - x1) == (y2 - y1)) or (-1*(x2 - x1) == (y2 - y1)) or ((x2 - x1) == -1*(y2 - y1))):
                print(1)
            else:
                print(2)
    except EOFError:
        break
