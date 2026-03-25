/*
18185
라면 사기 (Small)
*/
#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

vector<int> factories;

int buy(int idx, int count);
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);
    
    int n;
    cin >> n;

    factories.resize(n+2);

    int input;
    for(int i = 0; i < n; i++)
        cin >> factories[i];
    
    int tmp, result = 0;
    for(int i = 0; i < n; i++){
        if(factories[i+1] > factories[i+2]) {
            tmp = min(factories[i], factories[i+1]-factories[i+2]);
            factories[i] -= tmp;
            factories[i+1] -= tmp;
            result += tmp*5;

            result += buy(i, 3);
            result += buy(i, 1);

            continue;
        }
        result += buy(i, 3);
        result += buy(i, 2);
        result += buy(i, 1);
    }
    cout << result;
    
    return 0;
}
int buy(int idx, int count) {
    auto b = factories.begin()+idx;

    int m = *min_element(b, b+count);
    
    for(int i = idx; i < idx+count; i++)
        factories[i] -= m;

    int price;
    switch (count)
    {
    case 1:
        price = 3;
        break;
    case 2:
        price = 5;
        break;
    case 3:
        price = 7;
        break;
    default:
        price = 0;
        break;
    }

    return price*m;
}