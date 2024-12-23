#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    
    map<int, int> end;
    map<int, int> qtd;


    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;       
        v[i] = x;

        end[x] = i;
        qtd[x] ++;        
    }

    map<int, bool> appeared;

    int l = -1, r = -1, t = 0, ans =0;
    for (int i = 0; i < n; i++)
    {
        int x = v[i];

        if(!appeared[x]){
            appeared[x] = true;
            if(l == -1){
                l = i;
                r = end[x];                
                t = qtd[x];
            } else{
                t = max(t, qtd[x]);
                r = max(r, end[x]);
            }
        }        

        if(i == r){            
            ans += (r - t - l + 1);
            l = r = -1;
        }
    }
    
    cout << ans << endl;
}