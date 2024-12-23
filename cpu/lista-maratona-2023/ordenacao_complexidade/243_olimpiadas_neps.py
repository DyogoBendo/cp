from math import inf

def compare_arrays(a, b):
    if a == -inf:
        return False
    if b == -inf:
        return True
    if a[0] > b[0]:
        return True
    elif a[0] < b[0]:
        return False
    else:
        if a[1] > b[1]:
            return True
        elif a[1] < b[1]:
            return False
        else:
            if a[2] > b[2]:
                return True
            elif a[2] < b[2]:
                return False
            else:
                return True

def sort(lista, i, j):
    if i >= j - 1:
        v = lista[i]
        return [v]
    metade = (i  + j ) // 2
    le = sort(lista, i, metade)
    ld = sort(lista, metade, j)

    resultado = []

    e = 0
    d = 0

    while e < len(le) or d < len(ld):
        ve = le[e] if e < len(le) else -inf
        vd = ld[d] if d < len(ld) else -inf

        if compare_arrays(ve, vd):
            e += 1
            resultado.append(ve)
        else:
            d += 1
            resultado.append(vd)

    return resultado


if __name__ == "__main__":
    n, m = map(int, input().split())


    paises = [[0, 0, 0, i + 1] for i in range(n)]
    for i in range(m):
        o, p, b = map(int, input().split())
        paises[o - 1][0] += 1
        paises[p - 1][1] += 1
        paises[b - 1][2] += 1
    
    numeros = [1, 2, 3, 4, 5]
    resultado = sort(paises, 0, n)
    
    for i in range(n):
        if i < n - 1:
            print(resultado[i][-1], end=" ")
        else:
            print(resultado[i][-1])
            
