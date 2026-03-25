"""
전화번호 수수께끼 (small)
"""
from string import ascii_uppercase

numlist = [
    ['Z', 'ZERO', '0'],
    ['W', 'TWO', '2'],
    ['U', 'FOUR', '4'],
    ['X', 'SIX', '6'],
    ['G', 'EIGHT', '8'],
    ['O', 'ONE', '1'],
    ['R', 'THREE', '3'],
    ['F', 'FIVE', '5'],
    ['S', 'SEVEN', '7'],
    ['I', 'NINE', '9']]
cnt = {j : 0 for j in ascii_uppercase}

t = int(input())
for i in range(t):
    result = []
    string = input()

    for j in ascii_uppercase:
        cnt[j] = string.count(j)
    
    for j in numlist:
        acnt = cnt[j[0]]

        if acnt != 0:
            result += [j[2]]*acnt

            for k in j[1]:
                cnt[k] -= acnt
    
    result.sort()
    
    print(f'Case #{i+1}: '+''.join(result))