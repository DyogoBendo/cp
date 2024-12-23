if __name__ == "__main__":
    n = int(input())
    pares = [0 for _ in range(30, 60 + 1)]
    total = 0
    for i in range(n):
        numero, pe = input().split()
        numero = int(numero) - 30

        if pe == 'D':
            pares[numero] += 1
            if pares[numero] <= 0:
                total += 1
        if pe == 'E':
            pares[numero] -= 1
            if pares[numero] >= 0:
                total += 1
    
    print(total)

