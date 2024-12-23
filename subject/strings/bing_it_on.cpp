#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    node * children[26];
    int count;
    bool is_end;

    node(){
        memset(children, 0, sizeof(children));
        count = 0;
        is_end = false;
    }
} node ;

void insert(node* nd, char *s){
    nd->count++;
    if(*s){
        if(!nd->children[*s - 'a']) nd->children[*s - 'a'] = new node();
        insert(nd->children[*s - 'a'], s + 1);
    } else{
        nd->is_end = true;
    }
}

int find (node * nd, char * s){
    if(*s){
        if(!nd->children[*s - 'a']){
            return 0;
        }
        return find(nd->children[*s - 'a'], s + 1);
    } else{
        return nd->count;
    }
}


int main(){
    int n;
    cin >> n;

    char s[35];

    node *nd = new node();

    for (int i = 0; i < n; i++)
    {
        cin >> s;

        cout << find(nd, s) << endl;
        insert(nd, s);
    }
    
}