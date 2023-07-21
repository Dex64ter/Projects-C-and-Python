def ultima_parada(combustivel,consumo,postos_de_gasolina):
    distancia_percorrida_max = consumo * combustivel
    mais_distante = -1
    for i in postos_de_gasolina:
      if i <= distancia_percorrida_max:
        if i > mais_distante:
          mais_distante = i
    return mais_distante


print(ultima_parada(2,8,[2,15,22,11]))