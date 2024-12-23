if __name__ == "__main__":
    dias = int (input())
    anos, dias_restantes = divmod(dias, 365)
    meses, dias_restantes = divmod(dias_restantes, 30)

    print(f'{anos} ano(s)')
    print(f'{meses} mes(es)')
    print(f'{dias_restantes} dia(s)')

