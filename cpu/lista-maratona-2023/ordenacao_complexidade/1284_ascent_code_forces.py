from math import inf
from bisect import bisect_left

if __name__ == "__main__":
    n = int(input())
    menores = []
    maiores = []
    sempre_ocorre = []

    total = 0
    pares_internos = 0
    for _ in range(n):
        entrada = list(map(int, input().split()))
        l = entrada[0]
        s = entrada[1:]

        menor = inf
        maior = -1
        anterior = s[0]
        par_interno = False
        for number in s:
            if number > maior:
                maior = number
            if number < menor:
                menor = number
            
            if anterior < number:
                par_interno = True
            anterior = number

        if par_interno:
            total += 2 * n - 1 - (2 * pares_internos)
            pares_internos += 1
        else:
            menores.append(menor)
            maiores.append(maior)

    menores.sort()
    for maior in maiores:
        possiveis = 0
        k = bisect_left(menores, maior)
        possiveis = k

        total += possiveis
    
    print(total)


