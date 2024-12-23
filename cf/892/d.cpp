#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> position;
    vector<pair<int, int>> portal;
    for (int i = 0; i < n; i++)
    {
        int l, r, a, b;
        cin >> l >> r >> a >> b;   
        position.push_back({l, r});
        portal.push_back({b, a}); // colocamos invertido  
    }

    sort(portal.begin(), portal.end());
    vector<int> biggest_distance_inverted;
    
    queue<int> current_begin;
    queue<int> current_end;

    biggest_distance_inverted.push_back(portal[n-1].first);
    current_begin.push(portal[n-1].second);
    current_end.push(portal[n-1].first);

    for (int i = n - 2; i > -1; i--)
    {
        current_begin.push(portal[i].second);
        current_end.push(portal[i].first);

        while(current_begin.front() > portal[i].first){
            current_begin.pop();
            current_end.pop();
        }
        biggest_distance_inverted.push_back(current_end.front());
    }
    vector<int> biggest_distance;
    for (int i = 0; i < n; i++)
    {
        biggest_distance.push_back(biggest_distance_inverted[n - i - 1]);
    }
    

    int q;
    cin >> q;
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        queries.push_back({x, i});
    }

    sort(queries.begin(), queries.end());
    vector<int> answers(q);

    int p = 0;

    sort(position.begin(), position.end());
    
    for (int i = 0; i < q; i++)
    {
        int x = queries[i].first;
        int max_d = x;
        while(p < n && position[p])
    }
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}