#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        int t, n;
        cin >> n >> t;
    
        vector<int> a;
        vector<int> b;
        vector<pair<int, int>> videos;

        for (int i = 0; i < n; i++)
        {
            int x; 
            cin >> x;
            a.push_back(x + i);
        }
        
        for (int i = 0; i < n; i++)
        {
            int x; 
            cin >> x;
            videos.push_back({a[i], x});
        }        
        
        int r = 0;
        int answer = -1;
        for (int i = 0; i < n; i++)
        {
            auto v = videos[i];
            if(v.first <=t && v.second > r){
                r = v.second;
                answer = i + 1;
            }
        }
        
        cout << answer << endl;
    }
}