if __name__ == "__main__":
    k = int(input())
    painel = []
    for i in range(4):
        linha = input()
        painel.append(linha)
    
    quantidade_tempo = [0 for _ in range(9)]
    for i in range(4):
        for j in range(4):
            tempo = painel[i][j]    
            if tempo != '.':
                quantidade_tempo[int(tempo) - 1] += 1
    
    maior = 0
    for q in quantidade_tempo:
        if q > maior:
            maior = q
    if k * 2 >= maior:
        print('YES')
    else:
        print('NO')
    