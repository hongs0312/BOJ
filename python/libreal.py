n = int(input())

ans = 0
s = set()
for i in range(n):
    a = input()
    
    if a == "ENTER":
        ans += len(s)
        s.clear()

        continue

    s.add(a)

if len(s) != 0:
    ans += len(s)

print(ans)