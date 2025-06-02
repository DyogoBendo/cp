#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, m, t, c1, c2, ct;
    cin >> n >> m;
    
    int sz = (1 << n);
    vector<int> line(sz);
    iota(line.begin(), line.end(), 0);

    for (int i = 0; i < m; i++)
    {
        cin >> t;
        if(t == 1){
            cin >> c1 >> ct;
            c2 = c1;
        } else{
            cin >> c1 >> c2 >> ct;
        }

        vector<int> column(sz);
        // para cada linha, quero saber qual coluna fica ativa

        for (int i = 0; i < sz; i++)
        {
            if((i &(1<<c1)) && (i &(1<<c2))) column[i] = i ^ (1<<ct);
            else column[i] = i;            
        }

        vector<int> tmp(sz);
        for (int i = 0; i < sz; i++)
        {
            tmp[i] = column[line[i]];
        }        
        for (int i = 0; i < sz; i++)
        {
            line[i] = tmp[i];
        }                        
    }

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            cout << (line[i] == j); 
        }
        cout << endl;
    }

}