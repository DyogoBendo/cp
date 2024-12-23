if __name__ == "__main__":
    PESO_1 = 2
    PESO_2 = 3
    PESO_3 = 4
    PESO_4 = 1

    MENSAGEM_REPROVADO = 'Aluno reprovado.'
    MENSAGEM_APROVADO = 'Aluno aprovado.'
    MENSAGEM_EXAME = 'Aluno em exame.'

    n1, n2, n3, n4 = map(float, input().split())

    media = (n1 * PESO_1 + n2 * PESO_2 + n3 * PESO_3 + n4 * PESO_4) / (PESO_1 + PESO_2 + PESO_3 + PESO_4)
    print(f'Media: {media:.1f}')
    if(media >= 7):
        print(MENSAGEM_APROVADO)
    elif (media >= 5.0):
        print(MENSAGEM_EXAME)
        nota_exame = float(input())
        print(f'Nota do exame: {nota_exame:.1f}')
        nova_media = (media + nota_exame) / 2

        if(nova_media >= 5):
            print(MENSAGEM_APROVADO)
        else:
            print(MENSAGEM_REPROVADO)
        print(f'Media final: {nova_media:.1f}')
    else:
        print(MENSAGEM_REPROVADO)


    
