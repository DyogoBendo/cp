from math import factorial

def calculate_combinations(n):
    if n < 2:
        return 0
    combinations = 0
    for i in range(2, n + 1):
        r = factorial(n) // (factorial(i) * factorial(n - i))
        combinations += r
    return combinations


if __name__ == "__main__":
    n, m = map(int, input().split())

    matriz = []
    for i in range(n):
        matriz.append(list(map(int, input().split())))
    
    somas_linhas = [0 for _ in range(n)]
    somas_colunas = [0 for _ in range(m)]

    for i in range(n):
        for j in range(m):
            c = matriz[i][j]
            somas_linhas[i] += c
            somas_colunas[j] += c
    
    possibilidades = n * m

    for i in range(n):
        num_0 = m - somas_linhas[i]
        num_1 = somas_linhas[i]

        possibilidades += calculate_combinations(num_0)
        possibilidades += calculate_combinations(num_1)
    for i in range(m):
        num_0 = n - somas_colunas[i]
        num_1 = somas_colunas[i]

        possibilidades += calculate_combinations(num_0)
        possibilidades += calculate_combinations(num_1)
    
    print(possibilidades)

    