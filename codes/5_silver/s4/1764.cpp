/*
1764
듣보잡
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> hash_map;
int bucket_num = 31;

void init_map();
int hash_str(string str);
bool find_element(string str);
void push_map(string str);

int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);

    init_map();

    int n, m;
    cin >> n >> m;

    string input;
    for(int i = 0; i < n; i++) {
        cin >> input;

        push_map(input);
    }

    vector<string> ans;
    for(int i = 0; i < m; i++) {
        cin >> input;

        if(find_element(input) == true) {
            ans.push_back(input);
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
void init_map() {
    hash_map.resize(bucket_num);
}
int hash_str(string str) {
    const int p = 31;
    const int mod = 10e7 + 7;

    int hash_val = 0;
    int pow_p = 1;

    for(int i = 0; i < str.length(); i++) {
        hash_val = (hash_val + (str[i]-'a'+1)*pow_p) % mod;
        pow_p = (pow_p*p)%mod;
    }
    return hash_val;
}
bool find_element(string str) {
    int b = hash_str(str)%bucket_num;

    for(int i = 0; i < hash_map[b].size(); i++) {
        if(str == hash_map[b][i])
            return true;
    }
    return false;
}
void push_map(string str) {
    if(find_element(str) == true) return;

    int b = hash_str(str)%bucket_num;

    hash_map[b].push_back(str);
}