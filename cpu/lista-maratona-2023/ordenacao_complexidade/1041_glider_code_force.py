if __name__ == "__main__": 
    n, h = map(int, input().split())
    sections = []
    cost = []
    previous = 0
    for i in range(n):
        a, b = map(int, input().split())
        section_size = b - a
        sections.append(section_size)
        if i > 0:
            cost_value = a - previous
            cost.append(cost_value)
        previous = b
    

    sections_sum = []
    cost_sum = []

    total = 0
    for i in range(n):
        s = sections[i]
        total += s
        sections_sum.append(total)
    
    total = 0
    for i in range(n - 1):
        c = cost[i]
        total += c
        cost_sum.append(total)

    max_sum = 0
    j = 0

    for i in range(n):
        j = max(i, j)
        initial_section = sections_sum[i - 1] if i > 0 else 0
        final_section = sections_sum[j]
        initial_cost = cost_sum[i - 1] if i > 0  else 0
        final_cost = cost_sum[j - 1] if j > 0 else 0
        current_cost = final_cost - initial_cost
        current_sum = (final_section - initial_section) + current_cost
        
        to_spend = h - current_cost


        while j < n and to_spend > 0:
            if j < n - 1:
                next_cost = cost[j]
                if next_cost > to_spend:
                    current_sum += to_spend
                    to_spend = 0
                else:
                    j += 1
                    current_sum += next_cost
                    to_spend -= next_cost

                    if to_spend > 0:
                        current_sum += sections[j]
                
            else:
                current_sum += to_spend
                to_spend = 0
        if current_sum > max_sum:
            max_sum = current_sum
    
    print(max_sum)