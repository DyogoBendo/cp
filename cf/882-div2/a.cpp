#include <bits/stdc++.h>

using namespace std;

// union-find

int find(int x, vector<int> &grouped){
    if(grouped[x] == x) return x;
    grouped[x] = find(grouped[x], grouped);
    return grouped[x];
}

int group(int x, int y, vector<int> &grouped){
    if(find(x, grouped) == find(y, grouped)){
        return -1;
    }

    if(find(x, grouped) > find(y, grouped)){
        grouped[y] = grouped[x];
    } else{
        grouped[x] = grouped[y];
    }
    return 1;

}


void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> values;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        values.push_back(x);
    }

    int total = 0;

    vector<int> grouped(n);

    for (int i = 0; i < n; i++)
    {
        grouped[i] = i;
    }    
    
    for (int i = n; i > k; i--)
    {        
        int smallest_difference = 10000;
        int position = -1;
        for (int j = 0; j < n - 1; j++)
        {            
            if(abs( values[j] - values[j + 1]) < smallest_difference && (find(grouped[j], grouped) != find(grouped[j + 1], grouped))){
                smallest_difference = abs( values[j] - values[j + 1]);
                position = j;
            }
        }
        if(position == -1) continue;
        group(position, position + 1, grouped);
        total += smallest_difference;        
    }
    
    cout << total << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}