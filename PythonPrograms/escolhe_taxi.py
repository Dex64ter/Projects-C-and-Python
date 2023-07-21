def escolhe_taxi(tf1,vqr1,tf2,vqr2):
    tf1 = float(tf1.replace(',','.'))
    tf2 = float(tf2.replace(',','.'))
    vqr1 = float(vqr1.replace(',','.'))
    vqr2 = float(vqr2.replace(',','.'))
    
    if tf1 == tf2 and vqr1 == vqr2:
        return "Tanto faz"

    if (tf1 <= tf2 and vqr1 < vqr2) or (tf1 < tf2 and vqr1 <= vqr2):
        return "Empresa 1"
    elif (tf1 >= tf2 and vqr1 > vqr2) or (tf1 > tf2 and vqr1 >= vqr2):
        return "Empresa 2"
    elif (tf1 > tf2 and vqr1 < vqr2):
        val_fixo = tf1 - tf2
        val_km = vqr2 - vqr1
        N = val_fixo/val_km
        N = round(N, 1)
        return "Empresa 2 quando a distância < "+str(N)+", Tanto faz quando a distância = "+str(N)+", Empresa 1 quando a distância > "+str(N)

    elif(tf1 < tf2 and vqr1 > vqr2):
        val_fixo = tf2 - tf1
        val_km = vqr1 - vqr2
        N = val_fixo/val_km
        N = round(N, 2)
        return "Empresa 1 quando a distância < "+str(N)+", Tanto faz quando a distância = "+str(N)+", Empresa 2 quando a distância > "+str(N)    

print(escolhe_taxi('2,50', '0,10', '2,00', '0,70'))