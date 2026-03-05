/*
28702
FizzBuzz
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);
    
    int i, num;
    string s;
    for(i = 0; i < 3; i++) {
        cin >> s;

        if(s == "Fizz")
            continue;
        if(s == "Buzz")
            continue;
        if(s == "FizzBuzz")
            continue;
        
        break;
    }
    num = stoi(s) + 3 - i;

    if(num%3 == 0 && num%5 == 0) cout << "FizzBuzz";
    else if(num%3 == 0) cout << "Fizz";
    else if(num%5 == 0) cout << "Buzz";
    else cout << num;

    return 0;
}