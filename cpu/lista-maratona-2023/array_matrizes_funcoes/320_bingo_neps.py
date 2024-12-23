if __name__ == "__main__":
    while True:
        n, b = map(int, input().split())
        if n == 0:
            break
        bolas = list(map(int, input().split()))
        possiveis = [0 for _ in range(n + 1)]
        
        for i in range(b):
            for j in range(i, b):
                diferenca = abs(bolas[i] - bolas[j])
                possiveis[diferenca] = 1
        
        total_possibilidades = sum(possiveis)

        if total_possibilidades == n + 1:
            print('Y')
        else:
            print('N')

