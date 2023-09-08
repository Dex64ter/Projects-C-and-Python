# Saldo do vovô

N,S = map(int, input().split())
minimum = S
for _ in range(N):
  if S < minimum:
    minimum = S
  m = int(input())
  S += m
if S < minimum:
  minimum = S
print(minimum)