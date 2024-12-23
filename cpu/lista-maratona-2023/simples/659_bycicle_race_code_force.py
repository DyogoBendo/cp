if __name__ == "__main__":
    n = int(input())
    x_anterior = None
    y_anterior = None
    sentido_atual = None
    curvas_perigosas = 0
    for i in range(n + 1):
        x, y = map(int, input().split())

        if x_anterior is None:
            x_anterior = x
            y_anterior = y
            continue

        diferenca_x = x - x_anterior
        diferenca_y = y - y_anterior

        if diferenca_y < 0: 
            if sentido_atual == 'O':
                curvas_perigosas += 1
            sentido_atual = 'S'
        elif diferenca_y > 0:
            if sentido_atual == 'L':
                curvas_perigosas += 1
            sentido_atual = 'N' 
        elif diferenca_x < 0:
            if sentido_atual == 'N':
                curvas_perigosas += 1
            sentido_atual = 'O'
        elif diferenca_x > 0:
            if sentido_atual == 'S':
                curvas_perigosas += 1
            sentido_atual = 'L'
        x_anterior = x
        y_anterior = y
    
    print(curvas_perigosas)
