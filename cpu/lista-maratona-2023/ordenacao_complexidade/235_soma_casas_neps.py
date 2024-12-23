def find(lista, elemento):
    i = 0
    j = len(lista)
    while True:
        metade = (j + i) // 2
        if lista[metade] == elemento:
            return metade
        if i == metade == j - 1:
            return -1
        if lista[metade] < elemento:
            i = metade
        else:
            j = metade

if __name__ == "__main__":
    n = int(input())
    lista = []
    for _ in range(n):
        lista.append(int(input()))
    k = int(input())

    resposta = ''
    for casa in lista:
        achei = find(lista, k - casa)
        if achei != - 1:
            resposta = f'{casa} {k - casa}'
            break
    
    print(resposta)
