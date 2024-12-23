if __name__ == "__main__":
    x = float(input()) # distancia percorrida
    y = float(input()) # total de combustivel gasto

    consumo_medio = float(x / y )
    print(f'{consumo_medio:.3f} km/l')