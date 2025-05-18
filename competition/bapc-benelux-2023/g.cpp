#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

int calc_sz_sq(pair<int, int> vt){
    int ans=vt.first * vt.first + vt.second * vt.second;     
    return ans;
}

int is90(pair<int, int> v1, pair<int, int> v2){
    return v1.first *v2.first + v1.second * v2.second == 0;
}

int is_parallel(pair<int, int> v1, pair<int, int> v2){
    return v1.first * v2.second == v1.second * v2.first;
}

signed main(){
    vector<pair<int, int>> points(4);
    
    for (int i = 0; i < 4; i++)
    {
        cin >> points[i].first >> points[i].second;
    }
    
    vector<pair<int, int>> v;

    for (int i = 0; i < 4; i++)
    {
        int p = (i+1)%4;
        v.push_back({points[i].first - points[p].first, points[i].second - points[p].second});
    }

    bool has90 = true;
    int qtd_equal_sz = 0;        
    for (int i = 0; i < 3; i++)
    {
        has90 &= is90(v[i], v[(i+1)]);        
        qtd_equal_sz += calc_sz_sq(v[i]) == calc_sz_sq(v[(i+1)]);
    }
    int parallel_side = 0;
    int adj_sz1 = 0, adj_sz2 = 0;
    for (int i = 0; i < 2; i++)
    {
        parallel_side += is_parallel(v[i], v[i+2]);
        adj_sz1 += calc_sz_sq(v[2*i]) == calc_sz_sq(v[2*i+1]);
        adj_sz2 += calc_sz_sq(v[2*i]) == calc_sz_sq(v[(2*i+ 4 - 1) % 4]);
    }        
    
    if(has90 && qtd_equal_sz == 3){
        cout << "square" << endl;
    } else if(has90){
        cout << "rectangle" << endl;
    } else if(qtd_equal_sz == 3){        
        cout << "rhombus" << endl;
    } else if(parallel_side == 2){
        cout << "parallelogram" << endl;
    } else if(parallel_side == 1){
        cout << "trapezium" << endl; 
    } else if(adj_sz1 == 2 or adj_sz2 == 2){
        cout << "kite" << endl;
    } else{                
        cout << "none" << endl;
    }
    
}