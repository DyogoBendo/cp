if __name__ == "__main__":
    n, l = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()

    max_distance = 0
    for i in range(1, n):
        previous = a[i - 1]
        current = a[i]

        distance = (current - previous) / 2

        if distance > max_distance:
            max_distance = distance
    
    # DISTANCE FROM THE INITIAL POINT OF THE STREET
    initial_distance = a[0]

    end_distance = l - a[-1]

    max_distance = max(max_distance, initial_distance, end_distance)

    print(f'{max_distance:.10f}')


