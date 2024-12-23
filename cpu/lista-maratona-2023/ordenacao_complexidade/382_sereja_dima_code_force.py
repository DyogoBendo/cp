if __name__ == "__main__":
    n = int(input())
    cards = list(map(int, input().split()))

    s = 0
    d = 0
    i = 0
    j = n - 1
    for r in range(n):
        c1 = cards[i]
        c2 = cards[j]
        c = 0
        if c1 > c2:
            c = c1
            i += 1
        else:
            c = c2
            j -= 1

        if r % 2 == 0:
            s += c
        else:
            d += c
    
    print(f'{s} {d}')