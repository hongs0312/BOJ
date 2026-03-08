"""
하노이 탑 이동 순서
"""
def moving(x, f, t, r):
    if x > 0:
        moving(x-1, f, r, t)
        print(f"{f} {t}")
        moving(x-1, r, t, f)

n = int(input())
print(2**n-1)
moving(n, 1, 3, 2)