#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const int MAX = 1e4 + 10;
signed main(){
    //darvem;

    int n;
    cin >> n;

    vector<int> v(n);

    int soma = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        soma += v[i];
    }

    if(soma % 2){
        cout << -1 << endl;
        return 0;
    }

    vector<int> values(MAX);    
    vector<int> used(MAX);    
    values[0] = 1;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {        
        int x = v[i];
        curr += x;
        for (int j = MAX-1; j >= 0; j--)
        {            
            if(values[j] && j + x < MAX && !values[j+x]){
                values[j+x] = 1;                
                used[j+x] = i;
            }
        }        
        if(values[soma/2]) break;
    }

    if(!values[soma/2]){
        cout << -1 << endl;
        return 0;
    }    

    vector<int> alice, bob;

    vector<int> vx;
    int total = 0, idx;

    while(total < soma/2){
        idx = used[soma/2 - total];
        total += v[idx];
        vx.push_back(idx);
    }

    for (int i = 0; i < n; i++)
    {
        bool isa = false;
        for (auto x : vx)
        {            
            if(x == i) isa = true;
        }
        
        if(isa){
            alice.push_back(v[i]);            
        } 
        else{
            bob.push_back(v[i]);            
        } 
    }

    int a= 0, b = 0, curra = 0, currb = 0;

    for (int i = 0; i < n; i++)
    {
        if(curra <= currb){
            cout << alice[a] << " ";
            curra += alice[a];
            a++;
        } else{
            cout << bob[b] << ' ';
            currb += bob[b];
            b++; 
        }
    }
    cout << endl;
    
}