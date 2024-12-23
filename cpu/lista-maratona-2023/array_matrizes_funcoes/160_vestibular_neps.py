if __name__ == "__main__":
    n = int (input())
    l1 = input()
    l2 = input()

    certas = 0
    for i in range(n):
        r1 = l1[i]
        r2 = l2[i]

        if r1 == r2:
            certas += 1
    
    print(certas)
