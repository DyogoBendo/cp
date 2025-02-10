#include <bits/stdc++.h>

using namespace std;

int t, n, q, m;
int le [100000];
int ri [100000]; 
int queries [100000];

int check(int x){    
    vector<int> current (n, 0);
    vector<int> cumulative_sum(n + 1, 0);
        
    for (int i = 0; i <= x; i++)
    {                
        current[queries[i]] = 1;        
    }
    

    for (int i = 1; i <= n; i++)
    {
        cumulative_sum[i] = cumulative_sum[i - 1] + current[i - 1];
    }
    
    bool s = 0;    
    for (int i = 0; i < m; i++)
    {                
        s = max(s, (ri[i] - le[i] + 1) / 2 < cumulative_sum[ri[i] + 1] - cumulative_sum[le[i]]);            
    }    
    
    return s;
    
}

int main(){
    cin >> t;

    while(t){
        t --;
        cin >> n >> m;          

        for (int i = 0; i < m; i++)
        {
            int l, r;
            cin >> l >> r;
            le[i] = l - 1;
            ri[i] = r - 1;                 
        }

        cin >> q;                
        for (int j = 0; j < q; j++)
        {
            int x;
            cin >> x;
            queries[j] = x - 1;   
        }
        
        // lets do a binary search !

        int lb = 0, rb = q;        
        while(lb < rb){
            int mid = (lb + rb) / 2;            
            if(check(mid)){                                
                rb = mid;
            } else{                
                lb = mid + 1;
            }
        }
        
        if(lb >= q){
            cout << -1 << endl;
        } else{
            cout << lb + 1 << endl;
        }
    }
}