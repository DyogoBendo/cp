def find_posicion(lista, valor):
    i = 0
    j = len(lista)
    while i < j:
        mid = (i + j) // 2

        v = lista[mid]
        if v == valor:
            return mid
        if valor > v:
            i = mid
        if valor < v:
            j = mid
    
        if mid == j - 1:
            return mid
        if mid == 0:
            return -1
        
    return j


if __name__ == "__main__":
    n, m = map(int, input().split())
    faixas = list(map(int, input().split()))
    premios = list(map(int, input().split()))
    ogros = list(map(int, input().split()))

    resultados = []
    for o in ogros:
        p = find_posicion(faixas, o) + 1

        premio = premios[p]
        resultados.append(premio)
    
    print(" ".join(list(map(str,resultados))))
