if __name__ == "__main__":
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    discharged = set()

    subtract = 0
    for x in a:
        if x not in discharged:
            y = x * k
            discharged.add(y)
        else:
            subtract += 1
    
    print(len(a) - subtract)
