c, q = input().split()

c = int(c)
q = float(q)

if(c == 1):
    total = (4.00 * q)
if(c == 2):
    total = (4.50 * q)
if(c == 3):
    total = (5.00 * q)
if(c == 4):
    total = (2.00 * q)
if(c == 5):
    total = (1.50 * q)
    
print("Total: R$ %.2f" % total)
