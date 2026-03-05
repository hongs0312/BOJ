/*
14626
ISBN
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);
    
    int n = 0, mult, r;
    char c;
    for(int i = 0; i < 13; i++) {
        c = getchar();

        if(i%2 == 0) 
            mult = 1;
        else
            mult = 3;
        
        if(c == '*') {
            r = mult;
            continue;
        }
        
        n += (c-'0')*mult;
    }

    int ans;
    for(int i = 0; i < 10; i++) {
        if((n+i*r)%10 == 0) {
            cout << i;
            break;
        }
    }

    return 0;
}