if __name__ == "__main__":
    n = int(input())
    matriz = []
    soma = 0
    isMagico = True
    for i in range(n):
        linha = list(map(int, input().split()))
        matriz.append(linha)
    soma = sum(matriz[0])

    # verificar linhas
    for i in range(n):
        soma_linha = sum(matriz[i])
        if soma_linha != soma:
            isMagico = False
    
    # verificar colunas

    for i in range(n):
        soma_coluna = 0
        for j in range(n):
            soma_coluna += matriz[j][i]
        
        if soma_coluna != soma:
            isMagico = False
    
    #verificar diagonal principal

    soma_diagonal = 0
    for i in range(n):
        soma_diagonal += matriz[i][i]
    
    if soma_diagonal != soma:
        isMagico = False
    
    # verificar diagonal secundária
    soma_diagonal = 0
    for i in range(n):
        soma_diagonal += matriz[i][n - i - 1]
    
    if soma_diagonal != soma:
        isMagico = False

    if isMagico:
        print(soma)
    else:
        print(-1)