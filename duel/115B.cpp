#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v; 

    for (int i = 0; i < n; i++)
    {
        int first = m + 1;
        int last = -1;
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            if(c == 'W'){
                first = min(first, j);
                last = max(last, j);
            }
        }
        v.push_back({first, last});
    }


    int start = 0;
    int direction = 1;
    int ans = 0;

    for (int i = 0; i < n; )
    {
        int first = v[i].first, last = v[i].second;

        if(last == -1){ // significa que não temos nada aqui
            bool found = false;
            for(int j = i + 1; j < n; j++){
                ans ++;
                if(v[j].second != -1){
                    if(i % 2 != j % 2){
                        if(direction == 1){
                            ans += max(0, (v[j].second - start));
                            start = max(start, v[j].second);
                        } else{
                            ans += max(0, start - v[j].first);
                            start = min(start, v[j].first);
                        }
                        direction *= -1;
                    } else{
                        if(direction == 1){
                            ans += max(0, start - v[j].first);
                            start = min(start, v[j].first);
                        } else{
                            ans += max(0, (v[j].second - start));
                            start = max(start, v[j].second);
                        }
                    }
                    i = j;
                    found = true;
                    break;
                }
            } 
            if(found == false){
                ans -= (n - i - 1);
                break;
            } 
        } else{
            bool found = false;
            if(direction == 1){
                ans += (last - start);
                start = last;
            } else{
                ans += (start - first);
                start = first;
            }

            for (int j = i + 1; j < n; j++)
            {
                ans ++;
                if(v[j].second != -1){
                     if(i % 2 != j % 2){
                        if(direction == 1){
                            ans += max(0, (v[j].second - start));
                            start = max(start, v[j].second);
                        } else{
                            ans += max(0, start - v[j].first);
                            start = min(start, v[j].first);
                        }
                        direction *= -1;
                    } else{
                        if(direction == 1){
                            if(v[j].first >= start){
                                ans += (v[j].first - start);
                                start = v[j].first;
                            } else{
                                ans += max(0, start - v[j].first);
                                start = min(start, v[j].first);
                            }
                        } else{
                            if(v[j].second <= start){
                                ans += (start - v[j].second);
                                start = v[j].second;
                            } else{
                                ans += max(0, (v[j].second - start));
                                start = max(start, v[j].second);
                            }
                        }
                    }
                    i = j;
                    found = true;
                    break;
                }
            }
            if(!found){
                ans -= (n - i - 1);
                break;
            }
        }
    }

    cout << ans << endl;
    
    
}