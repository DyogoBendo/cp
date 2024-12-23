if __name__ == "__main__":
    n = int(input())
    cenouras = [ list(map(int, input().split())) for _ in range(n) ]

    q = int(input())

    total_cenouras = 0

    for _ in range(q):
        li, ci, lf, cf = map(int, input().split())
        for i in range(li - 1, lf):
            for j in range(ci - 1, cf):
                total_cenouras += cenouras[i][j]
                cenouras[i][j] = 0
    
    print(total_cenouras)


    # daria para pensar em como fazer com que ele sequer entrasse no loop para campos que já estão vazios