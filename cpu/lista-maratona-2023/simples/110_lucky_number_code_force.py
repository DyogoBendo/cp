if __name__ == "__main__":
    number = input()
    quantity_lucky_digit = 0
    for n in number:
        n = int(n)
        if n == 7 or n == 4:
            quantity_lucky_digit += 1
    digits_quantity_lucky_digit = str(quantity_lucky_digit)

    is_lucky = True
    for n in digits_quantity_lucky_digit:
        n = int(n)
        if n != 4 and n != 7:
            is_lucky = False
        
    if is_lucky:
        print('YES')
    else:
        print('NO')
    