from math import inf

if __name__ == "__main__":
    lista = map(int, input().split())

    maior = -inf
    for n in lista:
        if n > maior:
            maior = n

    print(maior)
