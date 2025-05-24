#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long


signed main(){
    //darvem;
    int h, w;
    cin >> h >> w;    
    vector<vector<int>> v(h, vector<int>(w));
    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> v[i][j];
        }        
    }

    int bst = 0;    
    vector<int> visited(2097152 + 10);
    
    function<void(int)> calc = [&](int x){
        if(visited[x])return;        
        visited[x]=1;        
        
        int curr = 0;        
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int p1 = i*w + j + 1;
                
                if(x & (1<< p1)) continue;
                curr ^= v[i][j];
                int p2 = (i+1)*w + j + 1;                    
                int p3 = (i)*w + j + 2;                    
                
                if(i < h-1 && !(x & (1<< p2))){                    
                    calc(x + (1 << p1) + (1 << p2));                    
                }
                if(j < w-1 && !(x & (1<< p3))){                    
                    calc(x + (1 << p1) + (1 << p3));                    
                }
            }            
        }        
        bst = max(bst, curr);
    };

    calc(0);

    cout << bst << endl;
    
}