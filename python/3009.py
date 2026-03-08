'''
3009
네번째 점
'''

x = [0] * 1001
y = [0] * 1001

for i in range(3):
    a, b = map(int, input().split())

    x[a] += 1
    y[b] += 1

for i in range(1001):
    if x[i]%2 == 1:
        c = i
    
    if y[i]%2 == 1:
        d = i

print(c, d)