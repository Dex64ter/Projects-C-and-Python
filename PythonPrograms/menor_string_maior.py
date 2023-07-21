def menor_string_maior(name):
    if name != "":
        k = len(name)-1
        nome = list(name)
        maior_letra = max(nome)
        if maior_letra == nome[0]:
            return "sem resposta"

print(menor_string_maior("zdcba"))