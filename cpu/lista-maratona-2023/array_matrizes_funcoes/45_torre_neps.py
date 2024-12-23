if __name__ == "__main__":
    n = int(input())
    matriz = []
    for i in range(n):
        linha = list(map(int, input().split()))

        matriz.append(linha)

    soma_linhas = [0 for _ in range(n)]
    soma_colunas = [0 for _ in range(n)]

    for i in range(n):
        for j in range(n):
            m = matriz[i][j]
            soma_linhas[i] += m
            soma_colunas[j] += m

    maior_soma = 0
    for i in range(n):
        for j in range(n):
            peso = soma_linhas[i] + soma_colunas[j] - (2 * matriz[i][j])
            if peso > maior_soma:
                maior_soma = peso

    print(maior_soma)
