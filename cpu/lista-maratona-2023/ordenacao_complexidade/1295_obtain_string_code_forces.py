from bisect import bisect_right

if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        s = input()
        t = input()

        letters = dict()

        for i in range(len(s)):
            letter = s[i]

            if letter in letters:
                letters[letter].append(i)
            else:
                letters[letter] = [i]
        

        operations = 1
        current_position = -1
        k = ""
        for letter in t:            
            k += letter
            if letter not in letters:
                operations = -1
                break
            letter_index_list = letters[letter]            
            if current_position >= letter_index_list[-1]:
                current_position = letter_index_list[0]
                operations += 1            
            else:
                new_position = bisect_right(letter_index_list, current_position)
                current_position = letter_index_list[new_position]
            
        print(operations)