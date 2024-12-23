from math import inf

if __name__ == "__main__":
    n = int(input())
    quadrados = list(map(int, input().split()))
    base = []

    for i in range(n):
        if quadrados[i] == 0:
            base.append(i)
    
    current = 0
    distancias = []
    for i in range(n):
        distancia_current = abs(base[current] - i)
        distancia_next = inf
        if current < len(base) - 1:
            distancia_next = abs(base[current + 1] - i)

        if distancia_next < distancia_current:
            current += 1
            distancia_current = distancia_next
        distancias.append(min(distancia_current, 9))
    
    for i in range(n):
        if i < n - 1:
            print(distancias[i], end=" ")
        else:
            print(distancias[i])
