if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        f = input().split("_")

        last_word = f[-1]

        last_letters = last_word[-5:]

        if 'po' in last_letters:
            print('FILIPINO')
        elif 'desu' in last_letters or 'masu' in last_letters:
            print('JAPANESE')
        else:
            print('KOREAN')

