# O código pode ser executado com: 
    "py SmithWaterman.py < teste.txt > saida.txt" no Windows execução no cmd ou bash
    "python3 SmithWaterman.py" no Linux
    "python SmithWaterman.py" no MAC OS
        *
        *
        *
# O código em questão que referência ao cálculo do alinhamento por Smith Waterman, segue o passo a passo recebendo os valores dados pelo usuário:
    1º -> Recebe as duas sequências que estarão no cálculo do Smith Waterman, logo em seguida recebe também os valores para o cálculo do score, que seria no caso o Gap, o Mismatch e o Match, respectivamente.

    2º -> Criou-se uma função que retorna o inverso de uma string que será utilizado no final do código

    3º -> Em seguida, as duas sequências recebidas são colocadas em matrizes com 2 linhas para que cada elemento da sequência receba um valor relacionado ao valor de gap

    4º -> É feita uma tabela, comparando os valores ao redor de cada célula e no final cada célula da tabela terá um dos scores, em seguida a tabela é imprimida para que o usuário tenha uma visualização de cada score, junto disso é calculado o maior dos scores

    5º -> É dado ao usuário duas opções para a impressão do alinhamento global em relação a todos os scores da tebala ou com o maior score, escolhido a opção é feita uma lógica programacional, com exceções que utilizam valores do score máximo e dos antigos valores ao redor de cada célula para fazer o cálculo para no final possuir duas sequências de trás para frente do resultado do nosso alinhamento global.

    6º -> No final usamos a função "reverseString" para reverter os dois resultados e obtermos os valores do alinhamento global. Junto com o valor do score relacionado a escolha do usuário.