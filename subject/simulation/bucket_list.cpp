#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("blist");

    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> cows;    
    for (int i = 0; i < n; i++)
    {
        int si, ti, bi;
        cin >> si >> ti >> bi;                
        tuple<int, int, int> t = tie(si, ti, bi);        
        cows.push_back(t);    
    }

    int ans = 0;
    for (int i = 1; i <= 1000; i++)
    {
        int buckets = 0;
        for (int j = 0; j < n; j++)
        {
            auto cow = cows[j];
            if(get<0>(cow) <= i && i <= get<1>(cow) ){                
                buckets += get<2>(cow);
            }
        }
        

        ans = max(ans, buckets);
        
    }

    cout << ans << endl;
    
    
}