#include <bits/stdc++.h>

using namespace std;

int n, q; //회사의 수, 메뉴 입력의 개수
long long m; //보유중인 현금

typedef int group_num; //그룹 번호
typedef int price; //주식 가격

map<string, int> my_stock; //내가 가지고 있는 주식의 수
map<string, pair<group_num, price>> stock_price; //주식의 가격과 그룹 번호

void buy_stock(string name, int count);
void sell_stock(string name, int count);
void change_price(string name, int price);
void change_group_price(group_num num, int price);
void change_group_price_percent(group_num num, int price);
void menu6();
void menu7();

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> q;

    string name;
    int price, group;

    for (int i = 0; i < n; i++) {
        cin >> group >> name >> price;

        stock_price[name] = {group, price};
        my_stock[name] = 0;
    }

    int menu, num;
    for(int i = 0; i < q; i++) {
        cin >> menu;

        switch (menu) {
        case 1:
            cin >> name >> num;
            buy_stock(name, num);
            break;
        case 2:
            cin >> name >> num;
            sell_stock(name, num);
            break;
        case 3:
            cin >> name >> num;
            change_price(name, num);
            break;
        case 4:
            cin >> group >> num;
            change_group_price(group, num);
            break;
        case 5:
            cin >> group >> num;
            change_group_price_percent(group, num);
            break;
        case 6:
            menu6();
            break;
        case 7:
            menu7();
            break;
        }
    }

    return 0;
}

//name 회사의 주식을 count주 만큼 산다
void buy_stock(string name, int count) {
    long long price = stock_price[name].second;
    long long need = price*count;

    //돈이 충분하지 않으면 한 주도 사지 않는다
    if (need > m)
        return;
    
    m -= need;
    my_stock[name] += count;
}

//name 회사의 주식을 count주 만큼 판다
void sell_stock(string name, int count) {
    long long get, price = stock_price[name].second;
    if(my_stock[name] < count) {
        get = price * my_stock[name];

        my_stock[name] = 0;
    }
    else {
        get = price * count;

        my_stock[name] -= count;
    }

    m += get;
}

//name 회사의 주식 가격을 price만큼 바꾼다
void change_price(string name, int price) {
    stock_price[name].second += price;
}

//그룹 번호가 num인 회사들의 주식 가격을 price만큼 바꾼다
void change_group_price(group_num num, int price) {
    for(auto it = stock_price.begin(); it != stock_price.end(); it++) {
        if(it->second.first == num) {
            change_price(it->first, price);
        }
    }
}

//그룹 번호가 num인 회사들의 주식 가격을 현재 가격의 percent만큼 바꾼다
void change_group_price_percent(group_num num, int percent) {
    int change;
    for(auto it = stock_price.begin(); it != stock_price.end(); it++) {
        if(it->second.first == num) {
            change = it->second.second * (percent+100) / 100;
            change -= change % 10;

            stock_price[it->first].second = change;
        }
    }
}

//내가 가지고 있는 현금의 양 출력
void menu6() {
    cout << m << '\n';
}

//내가 가지고 있는 주식의 가치 + 현금 출력
void menu7() {
    long long sum = m;

    for(auto it = my_stock.begin(); it != my_stock.end(); it++) {
        sum += stock_price[it->first].second * it->second;
    }

    cout << sum << '\n';
}