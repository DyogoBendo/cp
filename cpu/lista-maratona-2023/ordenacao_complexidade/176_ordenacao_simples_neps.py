from math import inf

def selection_sort(lista, i, j):
    if i < j - 1:
        metade = (i + j) // 2
        le = selection_sort(lista, i, metade)  # esquerdo
        ld = selection_sort(lista, metade, j) # direito

        nova_lista = []
        posicao_esquerda = 0
        posicao_direita = 0
        while len(le) != posicao_esquerda or len(ld) != posicao_direita:
            e = le[posicao_esquerda] if posicao_esquerda < len(le) else inf
            d = ld[posicao_direita] if posicao_direita < len(ld) else inf
            if e <= d:
                nova_lista.append(e)
                posicao_esquerda += 1
            else:
                nova_lista.append(d)
                posicao_direita += 1
        return nova_lista
    else:
        nova_lista = [lista[i]]
        return nova_lista
    
if __name__ == "__main__":
    n = int(input())
    lista = list(map(int, input().split()))

    ordenado = selection_sort(lista, 0, n)

    for i in range(n):
        if i < n - 1:
            print(ordenado[i], end=' ')
        else:
            print(ordenado[i])