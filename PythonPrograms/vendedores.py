def retorna_menor_e_maior_valor_de_vendas(tickets):
    valor_minimo = 5000
    valor_maximo = 20
    for i in tickets:
      if i:
        while min(i) < 20:
            i.remove(min(i))
            if not i:
                break
        if i:
            while max(i) > 500:
                i.remove(max(i))
                if not i:
                    break
        if i:    
            if min(i) <= valor_minimo:
                valor_minimo = min(i)
            
            if max(i) <= 500:    
                if max(i) >= valor_maximo:
                    valor_maximo = max(i)
    return [valor_minimo, valor_maximo]
          

print(retorna_menor_e_maior_valor_de_vendas([[100,10,130,350],[400,500,20,99],[600],[]]))


i = [10,20,30,40,50,60]
