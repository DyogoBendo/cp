if __name__ == "__main__":
    while True:
        n = int(input())
        if n == 0:
            break
        
        a = 0
        b = 1
        total = 0
        for i in range (n, 0, -1):
            total = a + b
            a = b
            b = total

        print(total)