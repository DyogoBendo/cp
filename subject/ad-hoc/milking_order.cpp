#include <bits/stdc++.h>

using namespace std;
int n, m, k;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

bool check(vector<int> milking_position, vector<int> defined_order){
    vector<int> cow_pos(n + 1, -1);
    
    for (int i = 0; i < n; i++)
    {
        if(milking_position[i]) cow_pos[milking_position[i]] = i;
    }

    int h_idx = 0;

    for (int i = 0; i < n && h_idx < m; i++)
    {                
        if(cow_pos[defined_order[h_idx]] != -1){                        
            if(i > cow_pos[defined_order[h_idx]]){                
                return false;                
            }             
            i = cow_pos[defined_order[h_idx]];
            h_idx ++;
        } else{            
            while(i < n && milking_position[i]) i++;
        
            if(i == n) return false;            

            milking_position[i] = defined_order[h_idx];
            cow_pos[defined_order[h_idx]] = i;
            h_idx ++;
        }
    }

    return true;
    
}

int main(){
    setIO("milkorder");

    cin >> n >> m >> k;
    
    vector<int> defined_order(m);    
    vector<int> milking_position(n, 0);    

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        defined_order[i] = x;        
    }
    

    for (int i = 0; i < k; i++)
    {
        int x, p;
        cin >> x >> p;        
        p --;
        milking_position[p] = x;        
    }

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if(milking_position[i] == 1){
            ans = i;
            break;
        }
    }

    if(ans== -1){
        for (int i = 0; i < n; i++)
        {            
            if(milking_position[i]) continue;
            milking_position[i] = 1;
            if(check(milking_position, defined_order)){
                ans = i;
                break;
            }            
            milking_position[i] = 0;
        }
        
    }
    cout << ans + 1 << endl;
}