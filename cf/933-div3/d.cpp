#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> current(n, 0);
    vector<int> changes(n, 0);
    current[--x] = 1;


    for (int i = 0; i < m; i++)
    {
        int r;
        char c;
        cin >> r >> c;
        for (int j = 0; j < n; j++)
        {
            if(current[j]){                
                
                int clockwise = (j + r) % n;

                int sub = j - r;                
                if(sub < 0){
                    int mul = (abs(j - r) / n) + 1; 
                    sub = sub + (n * mul);
                }                
                int counterclockwise = sub % n;                

                if(c == '0' || c == '?'){
                    changes[clockwise] = 1;
                }
                if(c == '1' || c == '?'){
                    changes[counterclockwise] = 1;
                }                          
            }
        }

        for (int i = 0; i < n; i++)
        {
            current[i] = changes[i];    
            changes[i] = 0;        
        }                        
    }

    int marked = 0;
    for (int i = 0; i < n; i++)
    {
        if(current[i]) marked ++;
    }

    cout << marked << endl;
    
    for (int i = 0; i < n; i++)
    {
        if(current[i]) cout << i + 1 << " ";
    }
    cout << endl;
    

}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}