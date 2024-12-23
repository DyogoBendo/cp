#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    long long answer = 0;
    vector<long long> v;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }

    vector<long long> heap_power;

    for (int i = 0; i < n; i++)
    {
        if(v[i] == 0){        
            auto biggest = heap_power.size() ? heap_power[0] : 0;
            answer += biggest;
            if(heap_power.size())    {
                pop_heap(heap_power.begin(), heap_power.end());
                heap_power.pop_back();            
            }
            
        } else{
            heap_power.push_back(v[i]);
            push_heap(heap_power.begin(), heap_power.end());
        }
    }
    
    cout << answer << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}