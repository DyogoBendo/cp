def calcula_numero_pecas(n:int) -> int:
    return ((n + 1) *  (n + 2)) // 2 # posso afirmar que é sempre inteiro, já que temos um número ímpar multiplicado por um número par, o que é sempre par, então sua divisão por 2 será um número inteiro


if __name__ == "__main__":
    n = int(input())
    numero_pecas = calcula_numero_pecas(n)
    print(numero_pecas)
