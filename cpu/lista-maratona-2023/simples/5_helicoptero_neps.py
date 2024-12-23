if __name__ == "__main__":
    h, p, f, d = map(int, input().split())

    diferenca_horario_fh = 0
    diferenca_anti_horario_fh = 0

    diferenca_horario_fp = 0
    diferenca_anti_horario_fp = 0
    if f > h:
        # nesse caso, podemos afirmar que o movimento de f para h no sentido horário, não irá passar pelo marco 0
        diferenca_horario_fh = f - h
        diferenca_anti_horario_fh = 16 - diferenca_horario_fh
    else:
        diferenca_anti_horario_fh = h - f
        diferenca_horario_fh = 16 - diferenca_anti_horario_fh
    if f > p:
        diferenca_horario_fp = f - p
        diferenca_anti_horario_fp = 16 - diferenca_horario_fp
    else:
        diferenca_anti_horario_fp = p - f
        diferenca_horario_fp = 16 - diferenca_anti_horario_fp
    
    sentido_correto = -1 if diferenca_horario_fh < diferenca_horario_fp else 1

    if sentido_correto == d:
        print('S')
    else:
        print('N')
    