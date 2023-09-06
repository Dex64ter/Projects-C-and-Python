dia1 = int(input().replace('Dia ', ''))
(hora1, minuto1, segundo1) = map(int, input().split(' : '))

dia2 = int(input().replace('Dia ', ''))
(hora2, minuto2, segundo2) = map(int, input().split(' : '))

def horasA(hora1, hora2, dia1, dia2):
  horas, dias = 0, 0
  if hora2 < hora1:
    horas = 24 - hora1 + hora2
    dias = dia2 - dia1 - 1
  else:
    horas = hora2 - hora1
    dias = dia2 - dia1
  
  return [horas, dias]


def horasT(hora1, hora2, dia1, dia2):
  horas, dias = 0, 0
  if hora2 == 0:
      hora2 = 23
  else:
    hora2 -= 1
  
  if hora2 < hora1:
    horas = 24 - hora1 + hora2
    dias = dia2 - dia1 - 1
  else:
    horas = hora2 - hora1
    dias = dia2 - dia1
  
  return [horas, dias]

def minutosA(minuto1, minuto2, hora1, hora2, dia1, dia2):
  horas, dias = 0, 0
  if minuto2 < minuto1:
    minutos = 60 - minuto1 + minuto2
    horas, dias = horasT(hora1, hora2, dia1, dia2)

  else:
    minutos = minuto2 - minuto1
    horas, dias = horasA(hora1, hora2, dia1, dia2)

  return [minutos, horas, dias]

def minutosT(minuto1, minuto2, hora1, hora2, dia1, dia2):
  horas, dias = 0, 0
  if minuto2 == 0:
    minuto2 = 59
  else:
    minuto2 -= 1

  if minuto2 < minuto1:
    minutos = 60 - minuto1 + minuto2
    horas, dias = horasT(hora1, hora2, dia1, dia2)

  else:
    minutos = minuto2 - minuto1
    horas, dias = horasA(hora1, hora2, dia1, dia2)

  return [minutos, horas, dias]

if segundo2 < segundo1:
  segundos = 60 - segundo1 + segundo2
  minutos, horas, dias = minutosT(minuto1, minuto2, hora1, hora2, dia1, dia2)

else:
  segundos = segundo2 - segundo1
  minutos, horas, dias = minutosA(minuto1, minuto2, hora1, hora2, dia1, dia2)

print(dias,'dia(s)')
print(horas,'hora(s)')
print(minutos,'minuto(s)')
print(segundos,'segundo(s)')