def find_max_value(main_sequence, secundary_sequence, main_sequence_is_even, main_sequence_sum, secundary_sequence_sum, k):
    max_value = 0
    j = 0
    for i in range(len(main_sequence)):
        start_value = 0
        final_value = 0
        j = max(i, j)
        if main_sequence_is_even:
            if i != 0:
                start_value = secundary_sequence_sum[i - 1]
            if j != 0:
                final_value = secundary_sequence_sum[j - 1]
        else:
            start_value = secundary_sequence_sum[i]
            final_value = secundary_sequence_sum[j]

        value_already_considered = final_value - start_value
        value_to_change = k - value_already_considered

        initial_current_value = 0 if i == 0 else main_sequence_sum[i - 1]
        final_current_value = main_sequence_sum[j] if j < len(main_sequence) else main_sequence_sum[j - 1]

        current_value = (final_current_value - initial_current_value) + value_already_considered
        while value_to_change > 0 and j < len(main_sequence):
                value_breaker = 0
                if main_sequence_is_even:
                    if j < len(secundary_sequence):
                        value_breaker = secundary_sequence[j]
                    else:
                        break
                else:
                    if j < len(secundary_sequence) - 1:
                        value_breaker = secundary_sequence[j + 1]
                    else:
                        break
                if value_breaker > value_to_change:
                    current_value += value_to_change
                    value_to_change = 0
                else:
                    value_to_change -= value_breaker
                    current_value += value_breaker
                    j += 1
                    if j < len(main_sequence):
                        current_value += main_sequence[j]
                    if i == 0 and j == len(main_sequence) - 1 and not main_sequence_is_even:
                        left_value = min(value_to_change, secundary_sequence[0])
                        value_to_change -= left_value
                        current_value += left_value
        if current_value > max_value:
            max_value = current_value
    return max_value

if __name__ == "__main__":
    n, k = map(int, input().split())
    string = input()
    sequence = []

    current_letter = string[0]
    currrent_value = 0
    for letter in string:
        if letter == current_letter:
            currrent_value += 1
        else:
            sequence.append(currrent_value)
            current_letter = letter
            currrent_value = 1
    sequence.append(currrent_value)
    sequence_even = []
    sequence_odd = []
    sequence_sum_even = []
    sequence_sum_odd = []

    value_even = 0
    value_odd = 0
    for i in range(len(sequence)):
        v = sequence[i]
        if i % 2 == 0:
            sequence_even.append(v)
            value_even += v
            sequence_sum_even.append(value_even)
        else:
            sequence_odd.append(v)
            value_odd += sequence[i]
            sequence_sum_odd.append(value_odd)
    
    i = 0
    j = 0 
    max_value_even = find_max_value(sequence_even, sequence_odd, True, sequence_sum_even, sequence_sum_odd, k)
    max_value_odd = find_max_value(sequence_odd, sequence_even, False, sequence_sum_odd, sequence_sum_even, k)

    print(max(max_value_even, max_value_odd))


    



