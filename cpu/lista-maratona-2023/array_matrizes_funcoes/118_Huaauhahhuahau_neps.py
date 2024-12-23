if __name__ == "__main__":
    # avaliar se as vogais formam um palindromo
    risada = input()

    risada_vogais = ""

    for c in risada:
        if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
            risada_vogais += c
    
    is_engracada = True
    risadas_vogais_esquerda = []
    risadas_vogais_direita = []
    if len(risada_vogais) % 2 == 1:
        risadas_vogais_esquerda = risada_vogais[:len(risada_vogais) // 2]
        risadas_vogais_direita = risada_vogais[(len(risada_vogais) // 2) + 1:]
    else:
        risadas_vogais_esquerda = risada_vogais[:len(risada_vogais) // 2]
        risadas_vogais_direita = risada_vogais[(len(risada_vogais) // 2):]
    
    for i in range(len(risadas_vogais_esquerda)):
        if risadas_vogais_esquerda[i] != risadas_vogais_direita[-(i + 1)]:
            is_engracada = False
        
    if is_engracada:
        print('S')
    else:
        print('N')