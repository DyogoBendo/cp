#include <bits/stdc++.h>

using namespace std;

struct Trie{
    Trie* children[2] = {};
    int cnt = 0;
};

void add(Trie* root, int x){
    Trie* cur = root;
    for (int i = 30; i >= 0; i--)
    {
        bool has_bit = x & (1 << i);
        if(cur->children[has_bit] == NULL){
            cur->children[has_bit] = new Trie;
        }
        cur = cur->children[has_bit];
        cur->cnt++;
    }
    
}

void remove(Trie* root, int x){
    Trie *cur = root;
    for (int i = 30; i >= 0; i--)
    {
        bool has_bit = x & (1 << i);
        cur = cur->children[has_bit];
        cur->cnt --;
    }
}

int query(Trie *root, int x){
    Trie* cur = root;
    int res = 0;
    for (int i = 30; i >= 0; i--)
    {
        bool has_bit = x & (1 << i);
        if(cur->children[has_bit] != NULL && cur->children[has_bit]->cnt > 0){
            cur = cur->children[has_bit];
        } else{
            cur = cur->children[!has_bit];
            res += 1 << i;
        }
    }

    return res;
}


int main(){
    Trie tr;
    int q;
    cin >> q;
    set<int> s;
    for(int qry = 0; qry < q; qry++){
        int t, x;
        cin >> t >> x;
        if(t == 0){
            if(!s.count(x)){
                s.insert(x);
                add(&tr, x);
            }
        } else if(t == 1){
            if(s.count(x)){
                s.erase(x);
                remove(&tr, x);
            } 
        } else{
            cout << query(&tr, x) << endl;
        }
    }
}