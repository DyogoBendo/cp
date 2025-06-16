from math import sqrt

n, k = map(int, input().split())
pos = int(2*n - sqrt(k) + 1)
for a in range(pos+1, 2*n+1):
    if abs(a*a - k) % (2*n+1) == 0 and a*a - k != 0:
        pos = a

print(pos*pos)