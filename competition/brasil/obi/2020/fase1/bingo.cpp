#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, u;

    cin >> n >> k >> u;

    vector<vector<int>> values (u, vector<int>());
    vector<int> sizes(n, k);

    for (int i = 0; i < n; i++)
    {        
        for (int j = 0; j < k; j++)
        {
             int tmp;
             cin >> tmp;
             values[tmp - 1].push_back(i);             
        }        
    }
    

    vector<int> w;
    int bola;
    for (int i = 0; i < u; i++)
    {
        cin >> bola;

        if(w.empty()){
            for(auto a : values[bola - 1]){
                sizes[a] --;

                if(sizes[a] == 0) w.push_back(a + 1);
            }
        }                        
        
    }        


    for(auto a: w){
        cout << a << " ";
    }
    cout << endl;
    
    
}