"""
다각형의 면적
"""
def area(a, b):
    return (a[0]*b[1] - a[1]*b[0])/2

dots = []
n = int(input())
for i in range(n):
    dots.append(list(map(int, input().split())))

sum = 0
post = dots[-1]
for i in dots:
    sum += area(post, i)
    post = i

print(round(abs(sum), 2))