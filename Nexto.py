from math import sqrt
while True:
  try:
    r1, x1, y1, r2, x2, y2 = input().split(' ')

    r1 = float(r1)
    x1 = float(x1)
    y1 = float(y1)
    r2 = float(r2)
    x2 = float(x2)
    y2 = float(y2)

  
    if((x2 - x1) == 0 and (y2 - y1) == 0):
        if (r1 < r2):
            print('MORTO')
        else:
            print('RICO')
        continue
    elif((x2 - x1) == 0):
        cos = 1
    elif((y2 - y1) == 0):
        cos = 0
    else:
        sen = (x2 - x1)*0 + (y2 - y1)/ (sqrt((x2-x1)**2 + (y2-y1)**2) * sqrt(1**2))
    
    cos = sqrt(1 - sen**2)

    if(cos < 0 or x2 > x1 ):
        pontoMaxX = cos*r2 + x2 
    else:
        pontoMaxX = -cos*r2 + x2 

    pontoMaxY = sen*r2 + y2


    if (r1**2 < (pontoMaxX - x1)**2 + (pontoMaxY - y1)**2 ):
        print('MORTO')
    else:
        print('RICO')
  except EOFError:
    break

