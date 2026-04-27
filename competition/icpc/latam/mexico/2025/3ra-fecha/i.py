import sys
input_data = sys.stdin.read().split()

n = int(input_data[0])
m = int(input_data[1])


A = [0] * (n + 1)

idx = 2
for i in range(1, n + 1):
    A[i] = int(input_data[idx])
    idx += 1
    
B = [0] * (m + 1)
for j in range(1, m + 1):
    B[j] = int(input_data[idx])
    idx += 1    

sum_b = 0
for i in range(1, m+1):
    sum_b += B[i]

ans = 0
prefA = [0] * (n + 1)
for i in range(1, n+1):
    prefA[i] = prefA[i-1] + A[i]
    ans += i*A[i] * sum_b

for i in range(1, m+1):
    curr_sum = 0
    for j in range(1, n+1):
        l = j*i
        r = (j + 1)*i - 1

        if(l > n):
            break
        
        r = min(r, n)    
        curr_sum += j*(prefA[r] - prefA[l-1])            
    ans -= i*B[i]*curr_sum

print(ans) 

