#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<ll> a (n);
    vector<int> b(n);

    ll soma = 0;

    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        soma += a[i];
        b[i] = a[i];
    }

    int k = 0;


    while(k < n){
        int current = 0;
        int qtd = k;
        vector<int> numbers(n + 1, 0);

        int count_zeros = k;        

        for (int i = k; i < n; i++)
        {            
            numbers[b[i]] ++;
            if(numbers[b[i]] > qtd && numbers[b[i]] > 1){                      
                qtd ++;
                current = b[i];
            } else if(numbers[b[i]] == qtd && b[i] > current && qtd > 1){                
                current = b[i];
            }            
            if(current == 0) count_zeros ++;
            b[i] = current;
            soma += current;
        }        
        k = count_zeros;        
    }    
    
    cout << soma << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}