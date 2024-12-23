#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("tracing");
    int n, t;    
    cin >> n >> t;
    string cows_state;
    cin >> cows_state;
    vector<tuple<int, int, int>> records;
    for (int i = 0; i < t; i++)
    {        
        int ti, x, y;
        cin >> ti >> x >> y;
        records.push_back(make_tuple(ti, --x, --y));
    }    

    sort(records.begin(), records.end());

    int mi = 252;
    int ma = 0;
    int total = 0;

    for (int i = 0; i < n; i ++)
    {
        char cow = cows_state[i];
        if(cow == '0') continue;

        int p = 0;
        for (int k = 0; k <= t; k++)
        {
            vector<int> infected(n, 0);
            int first = 1;
            for (auto r : records)
            {
                int ti, x, y;
                tie(ti, x, y) = r;

                if(first && (x == i || y == i)){
                    first = 0;
                    infected[i] = 1;

                    if(k > 0){
                        int p = x == i ? y : x;
                        infected[p] = 1;
                    }
                } else{
                    if(infected[x] || infected[y]){
                        if(infected[y] == 0 && infected[x] <= k){                            
                            infected[y] ++;
                            infected[x] ++;
                        } else if(infected[x] == 0 && infected[y] <= k){
                            infected[y] ++;
                            infected[x] ++;                            
                        } else if(infected[x] && infected[y]){
                            infected[y] ++;
                            infected[x] ++;                            
                        }
                    }
                }
            }

            int equal = 1;
            for (int j = 0; j < n; j ++)
            {                
                if((!infected[j] && cows_state[j] == '1') || (infected[j] && cows_state[j] == '0')){                    
                    equal = 0;
                }                
            }
            
            if(equal){                
                mi = min(mi, k);
                ma = max(ma, k);
                p = 1;
            }            
        }
        if(p) total ++;        
        
    }

    string max_ans = ma == t ? "Infinity" : to_string(ma);
    cout << total << " " << mi << " " << max_ans << endl;
    
}