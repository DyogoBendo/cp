#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
int n, m;
int segtree[4 * N];
int lazy[4 * N];
int ans[N];

void update(int k, int a, int b, int l = 0, int r = n, int pos = 1){
    if(l > r) return;
    if(b < l) return;
    if(a > r) return;    
    if(lazy[pos]){        
        lazy[2*pos] = lazy[pos];
        lazy[2*pos + 1] = lazy[pos];
        lazy[pos] = 0;
    }     
    if(l >= a && r <= b){ // temos um intervalo definido        
        lazy[pos] = k;        
        return;
    }    

    int mid = (l + r) / 2;
    
    update(k, a, b, l, mid, 2*pos); // atualizar a esquerda
    update(k, a, b, mid + 1, r, 2*pos + 1); // atualizar a direita
}

void propagate(int l = 0, int r = n, int pos = 1){
    if(l > r) return;    
    if(l == r){        
        ans[l] = lazy[pos];
        lazy[pos] = 0;
        return;
    }
    int left = 2*pos;
    int right = 2*pos + 1;
    int value = lazy[pos];    
    int mid = (l + r) / 2;
    if(value){
        lazy[left] = value;
        lazy[right] = value;
    }
    propagate(l, mid, left);
    propagate(mid + 1, r, right);        
    
    lazy[pos] = 0;

}

int main(){
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int p, d;
        cin >> p >> d;

        int k = i % 2 ? -1 : 1;
        

        update(k, p, p + d - 1);
    }

    propagate();

    int soma = 0;

    for (int i = 0; i < n; i++)
    {        
        soma += ans[i];
    }    

    if(soma < 0){
        cout << "Guilherme" << endl;
    } else if(soma == 0){
        cout << "Empate" << endl;
    } else{
        cout << "Gabriela" << endl;
    }
    
    
}