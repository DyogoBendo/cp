#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    // setIO("promote");

    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;

        vector<int> logs;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            logs.push_back(x);
        }

        int soma = 0;
        for (auto x: logs)
        {
            soma += x;
        }

        int ans = n + 1;

        if(soma == 0){
            ans = 0;
        } else{
            vector<int> divisores;

            for (int i = 1; i <= soma; i++)
            {
                if(soma % i == 0) divisores.push_back(i);
            }

            for (auto d : divisores)
            {
                int current = 0;
                int actions = 0;                
                for (int i = 0 ; i< n; i++)
                {

                    current += logs[i];                    
                    if(logs[i] == 0){
                        actions ++;
                    }
                    else if(current > d){
                        actions = n + 1;
                        break;
                    } else{
                        actions ++;
                        if(current == d){
                            current = 0;
                            actions --;
                        } 
                    }                    
                }

                ans = min(ans, actions);
                
            }
               
        }
        
        cout << ans << endl;
    }
}