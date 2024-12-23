if __name__ == "__main__":
    n = int(input())
    l = list(map(int, input().split()))

    j = n - 1
    soma_total = 0

    for i in range(n - 1, -1, -1):
        soma_atual = max(min(0, max(0, i - j) - l[i]), -j, -i)
        j = min(j + soma_atual, i + soma_atual)
        soma_total += abs(soma_atual)
    print(n - soma_total)
