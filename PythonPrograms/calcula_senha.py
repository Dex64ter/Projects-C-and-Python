def binToDecimal(number):
    valor = 0
    interavel = 0
    for i in range(len(number)-1,-1,-1):
        if number[i] == '1':
            valor += 2**interavel
        interavel += 1 
    return valor

def calcula_numero_da_senha(senha):
    i = 0
    colunas = []
    column = []
    while i < 10:
        for j in senha:
            column.append(j[i])
        # print(column)
        um = column.count('1')
        zero = column.count('0')

        if um >= zero:
            colunas.append('1')
        else:
            colunas.append('0')
        
        column.clear()
        i+=1
    
    numero = binToDecimal(''.join(colunas))
    
    
    return numero


print(calcula_numero_da_senha(["0110100000","1001011111","1110001010","0111010101","0011100110","1010011001","1101100100","1011010100","1001100111","1000011000"]))