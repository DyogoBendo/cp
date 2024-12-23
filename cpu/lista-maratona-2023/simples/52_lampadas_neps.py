if __name__ == "__main__":
    n = int(input())
    comandos = map(int, input().split())
    a = 0
    b = 0
    for c in comandos:
        if c == 1:
            a = (a + 1) % 2
        if c == 2:
            a = (a + 1) % 2
            b = (b + 1) % 2
    print(a)
    print(b)
    