#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX = 400005;

ll difference_array[MAX];
int widths[MAX];
ll interval_value[MAX];
ll prefix_sums[MAX];
vector<int> indices;

int getCompressedIndex(int a){
    return lower_bound(indices.begin(), indices.end(), a) - indices.begin();
}

int main(){
    int n, q;
    cin >> n >> q;

    vector<tuple<int, int, int>> updates;  
    vector<pair<int, int>> queries;      
    
    for (int i = 0; i < n; i++)
    {
        int l, r, v;
        cin >> l >> r >> v;       
        indices.push_back(l);
        indices.push_back(r); 
        updates.push_back({l, r, v});        
    }
    
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        indices.push_back(l);
        indices.push_back(r);
        queries.push_back({l, r});
    }

    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());

    for (int i = 0; i < n; i++)
    {
        auto a = updates[i];

        difference_array[getCompressedIndex(get<0>(a) + 1)] += get<2>(a);
        difference_array[getCompressedIndex(get<1>(a) + 1)] -= get<2>(a);
    }

    for (int i = 0; i < indices.size() - 1; i++)
    {
        widths[i + 1] = indices[i + 1] - indices[i];
    }
    
    for (int i = 1; i < indices.size(); i++)
    {
        interval_value[i] = interval_value[i - 1] + difference_array[i];
    }

    for (int i = 1; i < indices.size(); i++)
    {
        prefix_sums[i] = prefix_sums[i - 1] + interval_value[i] * widths[i];
    }

    for (int i = 0; i < q; i++)
    {
        cout << prefix_sums[getCompressedIndex(queries[i].second)] - prefix_sums[getCompressedIndex(queries[i].first)] << "\n";
    }
    
    
    
    
}