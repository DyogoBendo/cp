if __name__ == "__main__":
    x, y = map(int, input().split())
    for i in range(1, y + 1, x):
        for j in range(i, i + x): 
            if (j < i + x - 1):
                print(j, end=' ')
            else:
                print(j)
