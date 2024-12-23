if __name__ == "__main__":
    tempo_viagem = int(input())
    velocidade_media = int(input())

    distancia_percorrida = tempo_viagem * velocidade_media
    gasto = distancia_percorrida / 12

    print(f'{gasto:.3f}')