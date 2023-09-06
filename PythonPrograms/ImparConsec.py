x = int(input())
y = int(input())

if y < x:
  x,y = y,x
soma = 0
for i in range(x+1,y):
  if i % 2 == 1:
    soma+=i
print(soma)