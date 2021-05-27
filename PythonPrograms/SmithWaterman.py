seq1 = input()
seq2 = input()
match = int(input())
mismatch = int(input())
gap = int(input())

def reverseString(text):
    return text[::-1]

# Criação da primeira sequência com gaps
aux = gap
sequencia1 = []
for i in range(2):
    sequencia1.append([0]*len(seq1))
    for j in range(len(seq1)):
        sequencia1[0][j] = seq1[j]
for x in range(len(seq1)):
    sequencia1[1][x] = aux
    aux = aux + gap

# Criação da segunda sequência com gaps
aux = gap
sequencia2 = []
for i in range(2):
    sequencia2.append([0]*len(seq2))
    for j in range(len(seq2)):
        sequencia2[0][j] = seq2[j]
for x in range(len(seq2)):
    sequencia2[1][x] = aux
    aux = aux + gap

# Tabela
ultimac = []
tabela = []
for i in range(len(seq1)):
    tabela.append([0]*len(seq2))
    h = sequencia1[1][i]
    for j in range(len(seq2)):
        if(i == 0):
            v = sequencia2[1][j] + gap
            h = h + gap

            if(j == 0):
                if(sequencia1[0][i] == sequencia2[0][j]):
                    d = match
                else:
                    d = mismatch    
            else:
                if(sequencia1[0][i] == sequencia2[0][j]):
                    d = sequencia2[1][j-1] + match
                else:
                    d = sequencia2[1][j-1] + mismatch
            
            maior = max(v, h, d)
            tabela[i][j] = maior
            h = tabela[i][j]
        else:
            h = h + gap
            v = tabela[i-1][j] + gap
            if(j == 0):
                if(sequencia1[0][i] == sequencia2[0][j]):
                    d = sequencia1[1][i-1] + match
                else:
                    d = sequencia1[1][i-1] + mismatch
            else:
                if(sequencia1[0][i] == sequencia2[0][j]):
                    d = tabela[i-1][j-1] + match
                else:
                    d = tabela[i-1][j-1] + mismatch

            maior = max(v, h, d)
            tabela[i][j] = maior
            h = tabela[i][j]

# Maior Score
scoremax = -float("inf")
for i in tabela:
    if(scoremax < max(i)):
        scoremax = max(i)

# Seleção sobre qual alinhamento
g = int(input())

# Back Tracing
bt1 = ""
bt2 = ""
if(g == 1):
    x = len(seq1)-1
    y = len(seq2)-1
    while(True):
        if((x != 0) and (y!=0)):
            aux = max(tabela[x-1][y-1], tabela[x-1][y], tabela[x][y-1])
            if(aux == tabela[x-1][y-1]):
                bt1 += (seq1[x])
                bt2 += (seq2[y])
                x = x-1
                y = y-1
            elif(aux == tabela[x-1][y]):
                bt1 += (seq1[x])
                bt2 += "-"
                x = x-1
            elif(aux == tabela[x][y-1]):
                bt1 += "-"
                bt2 += (seq2[y])
                y = y-1
        elif((x == 0) and (y != 0)):
            val = match if sequencia2[0][y] == sequencia2[0][x] else mismatch
            aux = max(sequencia2[1][y-1] + val, tabela[x][y-1] + gap, sequencia2[1][y]+gap)
            if(aux == sequencia2[1][y-1] + val):
                bt1 += (seq1[x])
                bt2 += (seq2[y])
                y = y-1
                while(y >= 0):
                    bt1 += "-"
                    bt2 += seq2[y]
                    y = y-1
                break
            elif(aux == sequencia2[1][y]+gap):
                bt2 += seq2[y]
                bt1 += "-"
                while(y < 0):
                    bt2 += seq2[y]
                    bt1 += "-"
                    y = y-1
                break
            elif(aux == tabela[x][y-1] + gap):
                bt1 += seq1[x]
                bt2 += "-"
                x = x-1
        elif((x != 0) and (y == 0)):
            val = match if sequencia1[0][x] == sequencia2[0][y] else mismatch
            aux = max(sequencia1[1][x-1] + val, tabela[x-1][y] + gap, sequencia1[1][x]+gap)
            if(aux == sequencia1[1][x-1] + val):
                bt1 += (seq1[x])
                bt2 += (seq2[y])
                x = x-1
                while(x >= 0):
                    bt1 += seq1[x]
                    bt2 += "-"
                    x = x-1
                break
            elif(aux == sequencia1[1][x]+gap):
                bt2 += seq2[y]
                bt1 += "-"
                while(x < 0):
                    bt1 += seq1[x]
                    bt2 += "-"
                    x = x-1
                break
            elif(aux == tabela[x-1][y] + gap):
                bt1 += seq1[x]
                bt2 += "-"
                x = x-1
        elif((x == 0) and (y == 0)):
            bt1 += (seq1[x])
            bt2 += (seq2[y])
            break
elif(g == 2):
    x=0
    y=0
    for u in range(len(seq1)):
        for v in range(len(seq2)):
            if(tabela[u][v] == scoremax):
                x = u
                y = v
    while(True):
        if((x != 0) and (y!=0)):
            aux = max(tabela[x-1][y-1], tabela[x-1][y], tabela[x][y-1])
            if(aux == tabela[x-1][y-1]):
                bt1 += (seq1[x])
                bt2 += (seq2[y])
                x = x-1     
                y = y-1     
            elif(aux == tabela[x-1][y]):
                bt1 += (seq1[x])
                bt2 += "-"
                x = x-1
            elif(aux == tabela[x][y-1]):
                bt1 += "-"
                bt2 += (seq2[y])
                y = y-1
        elif((x == 0) and (y != 0)):
            val = match if sequencia2[0][y] == sequencia2[0][x] else mismatch
            aux = max(sequencia2[1][y-1] + val, tabela[x][y-1] + gap, sequencia2[1][y]+gap)
            if(aux == sequencia2[1][y-1] + val):
                bt1 += (seq1[x])
                bt2 += (seq2[y])
                y = y-1
                while(y >= 0):
                    bt1 += "-"
                    bt2 += seq2[y]
                    y = y-1
                break
            elif(aux == sequencia2[1][y]+gap):
                bt2 += seq2[y]
                bt1 += "-"
                while(y < 0):
                    bt2 += seq2[y]
                    bt1 += "-"
                    y = y-1
                break
            elif(aux == tabela[x][y-1] + gap):
                bt1 += seq1[x]
                bt2 += "-"
                x = x-1
        elif((x != 0) and (y == 0)):
            val = match if sequencia1[0][x] == sequencia2[0][y] else mismatch
            aux = max(sequencia1[1][x-1] + val, tabela[x-1][y] + gap, sequencia1[1][x]+gap)
            if(aux == sequencia1[1][x-1] + val):
                bt1 += (seq1[x])
                bt2 += (seq2[y])
                x = x-1
                while(x >= 0):
                    bt1 += seq1[x]
                    bt2 += "-"
                    x = x-1
                break
            elif(aux == sequencia1[1][x]+gap):
                bt2 += seq2[y]
                bt1 += "-"
                while(x < 0):
                    bt1 += seq1[x]
                    bt2 += "-"
                    x = x-1
                break
            elif(aux == tabela[x-1][y] + gap):
                bt1 += seq1[x]
                bt2 += "-"
                x = x-1

        elif((x == 0) and (y == 0)):
            bt1 += (seq1[x])
            bt2 += (seq2[y])
            break

print("Sequencia 1:", reverseString(bt1))
print("Sequencia 2:", reverseString(bt2))
print("Score = ", scoremax) if g == 2 else print("Score = ", tabela[len(seq1)-1][len(seq2)-1])