from functools import cmp_to_key

d = {}

def cmp(a, b):
    if d[a] > d[b]:
        return -1
    elif d[a] < d[b]:
        return 1
    else:
        if len(a) > len(b):
            return -1
        elif len(a) < len(b):
            return 1
        else:
            if a < b:
                return -1
            else:
                return 1

n, m = map(int, input().split())

for i in range(n):
    word = input()

    if len(word) < m:
        continue

    d.setdefault(word, 0)
    d[word] += 1

ans = list(d.keys())
ans.sort(key=cmp_to_key(cmp))

for w in ans:
    print(w)