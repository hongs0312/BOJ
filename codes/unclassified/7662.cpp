/*
7662 
이중 우선순위 큐
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> heap;

vector<int> init_heap();
int get_level(int idx);
bool min_max_comp(int element, int comp_elem, bool is_min_level);
int get_cand_idx(vector<int> candis, bool is_min_level);
void push_up(int idx);
void push_down(int idx);
int get_max();
void push(int element);
void pop_min();
void pop_max();
int main() {
    // freopen("IO_files/in.txt", "r", stdin);
    // freopen("IO_files/out.txt", "w", stdout);
    
    int t;
    cin >> t;

    while(t-- > 0) {
        heap = init_heap();

        int k;
        cin >> k;
        
        char c;
        int n;
        for(int i = 0; i < k; i++) {
            cin >> c >> n;

            if(c == 'I') {
                push(n);
            }
            else if(c == 'D') {
                if(n == -1) pop_min();
                else if(n == 1) pop_max();
            }
        }

        if(heap.size() == 1) {
            cout << "EMPTY\n";
        }
        else {
            cout << heap[get_max()] << " " << heap[1] << "\n";
        }

    }
    return 0;
}
vector<int> init_heap() {
    vector<int> tmp;
    tmp.push_back(0);

    return tmp;
}
int get_level(int idx) {
    int level = 0;
    
    while(idx > 0) {
        level++;

        idx = idx >> 1;
    }

    return level;
}
//return different compare equation by min-max level
bool min_max_comp(int element, int comp_elem, bool is_min_level) {
    if(is_min_level)
        return element < comp_elem;
    else 
        return element > comp_elem;
}
int get_cand_idx(vector<int> candis, bool is_min_level) {
    if(candis[0] >= heap.size()) return -1;

    int tmp = candis[0];
    for(int cand_idx:candis) {
        if(cand_idx >= heap.size())
            continue;
        
        if(min_max_comp(heap[tmp], heap[cand_idx], is_min_level))
            tmp = cand_idx;
    }
    return tmp;
}
void push_up(int idx) {
    int level = get_level(idx);
    bool is_min_level = level%2;   //true == min, false == max

    int parent = idx/2;
    if(parent == 0) return;

    if(min_max_comp(heap[idx], heap[parent], !is_min_level)) {
        swap(heap[idx], heap[parent]);

        idx = parent;

        is_min_level = !is_min_level;
    }

    while(idx/4 > 0) {
        if(min_max_comp(heap[idx], heap[idx/4], is_min_level)) {
            swap(heap[idx], heap[idx/4]);

            idx = idx/4;
        }
        else break;
    }
}
void push_down(int idx) {
    int level = get_level(idx);
    bool is_min_level = level%2;   //true == min, false == max

    vector<int> sons = {idx*2, idx*2+1};
    vector<int> grandsons ={idx*4, idx*4+1, idx*4+2, idx*4+3};

    int cand_son, cand_grandson, selected;
    while(idx < heap.size()) {
        cand_son = get_cand_idx(sons, is_min_level);
        cand_grandson = get_cand_idx(grandsons, is_min_level);

        if(cand_son == -1) break;
        else if(cand_grandson == -1) {
            swap(heap[idx], heap[cand_son]);
            
            break;
        }
        else if(min_max_comp(heap[cand_son], heap[cand_grandson], is_min_level)) {
            swap(heap[idx], heap[cand_son]);

            break;
        }
        else {
            swap(heap[idx], heap[cand_grandson]);

            idx = cand_grandson;
        }
    }
}
int get_max() {
    if(heap.size() < 3) return heap.size()-1;

    if(heap[2] > heap[3]) return 2;
    else return 3;
}
void push(int element) {
    heap.push_back(element);

    push_up(heap.size()-1);
}
void pop_min() {
    if(heap.size() == 1) return;
    
    heap.erase(heap.begin()+1);

    push_down(1);
}
void pop_max() {
    if(heap.size() == 1) return;

    heap.erase(heap.begin()+get_max());

    push_down(1);
}