#include <bits/stdc++.h>

/*
    A ideia é que um numero até 1e9 nao possui mais do que 12 fatores primos diferentes
    então podemos encontrar todos os primos até 1e9 em 1e5 e encontrar os fatores primos de cada numero e montar uma segtree 
    a operação de merge de dois ranges é pegar todos os fatores que pertencem a ambos intervalos
    quando atualizamos um numero precisamos atualizar a segtree de baixo para cima, atualizando quais fatores primos pertencem a regiao
    como existem logn niveis isso passa de boa
*/

using namespace std;

const int MAX_VALUE = 1e5;
const int N = 4e5;
set<int> segtree[N];

int numeros[N];
int n;
set<int> primos;
int visited[MAX_VALUE];

set<int> decompor(int k){
    set<int> fatores;
    for (auto p : primos)
    {
        if(p > k) break;
        if(k % p == 0) fatores.insert(p);
        while(k % p == 0){
            k /= p;
        }
    }
    
    if(k != 1) fatores.insert(k);
}

set<int> merge(set<int> a, set<int> b){
    set<int> x;
    for (auto p : a)
    {
        if(b.count(p)){
            x.insert(p);
        }
    }

    return x;
}

set<int> init(int p = 1, int l = 0, int r = n - 1){
    if(l > r) return primos;
    if(l == r){
        return segtree[p] = decompor(numeros[l]);
    }

    int mid = (r - l) / 2 + l;
    return segtree[p] = merge(
        init(2 * p,  l, mid), 
        init(2 * p + 1, mid + 1, r)
    );
}

set<int> query(int p = 1, int i, int j, int l, int r){    
    if(r < i) return primos;
    if(l > j) return primos;
    if(l > r) return primos;

    // se o intervalo está contido
    if(l >= i && j <= r){
        return segtree[p];
    }

    int mid = (r - l) / 2 + l;

    set<int> left = query(2 * p, i, j, l, mid);
    set<int> right = query(2 * p + 1, i, j, mid + 1, r);    

    return merge(left,  right);
}

set<int> update(int p = 1, int i, int x, int l, int r){
    if(l > r) return primos;
    if(l > i) return segtree[p];
    if(r < i) return segtree[p];
    if(l == r && l == i){
        return segtree[p] = decompor(x);
    }

    int mid = (r - l) / 2 + l;
    return segtree[p] = merge(
        init(2 * p,  l, mid), 
        init(2 * p + 1, mid + 1, r)
    );
}

void achar_primos(){    
    for (int i = 2; i <= MAX_VALUE; i+= 2)
    {
        visited[i] = 1;
    }
    
    primos.insert(2);

    for (int i = 3; i <= MAX_VALUE; i+=2)
    {
        if(!visited[i]){
            primos.insert(i);
            visited[i] = 1;

            for (int j = i + i; j <= MAX_VALUE; j+= i)
            {
                visited[j] = 1;
            }
            
        }        
    }
    
}

int main(){
    int m;
    cin >> n >> m;

    achar_primos();
    for (int i = 0; i < n; i++)
    {
        cin >> numeros[i];
    }
    
    init();

    for (int i = 0; i < m; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;

        if(t == 2){
            set<int> gcd = query(--a, --b);
            if()
        }
    }
    
}