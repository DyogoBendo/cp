#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

string arr;

bool query(char a, char b){
    cout << "? " << a << b << endl;
    int ans;
    cin >> ans;
    return ans;
}

// 1 if greater
bool cmp(char a, char b){
    cout << "? " << a << a << a << b << '\n';
    int ans;
    cin >> ans;
    return ans;
}


void merge(int l, int r, int a, int b){
    string merged="";

    int i=l, j=a;
    while (i<=r && j<=b){
        if (cmp(arr[i], arr[j])) merged += arr[j++];
        else merged += arr[i++];
    }
    while (i<=r) merged += arr[i++];
    while (j<=b) merged += arr[j++];

    for (int k=l; k<=b; k++) arr[k] = merged[k-l];
}


void solve(){

    string a = "";
    string b = "";
    for (int i=0; i<7; i++){
        char c = 'a'+i;
        if (query(c, c)) a += c;
        else b += c; 
    }

    arr = a;

    merge(0, 0, 1, 1);
    merge(2, 2, 3, 3);
    merge(0, 1, 2, 3);

    vector<int> cnt (3);
    if (query(b[0], b[1])) cnt[0]++;
    else cnt[1]++;

    if (query(b[0], b[2])) cnt[0]++;
    else cnt[2]++;

    if (query(b[1], b[2])) cnt[1]++;
    else cnt[2]++;

    vector<pair<int, char>> ans = {
        {2*cnt[0], b[0]}, {2*cnt[1], b[1]}, {2*cnt[2], b[2]},
        {-1, arr[0]}, {1, arr[1]}, {3, arr[2]}, {5, arr[3]}
    };
    
    sort(rall(ans));

    cout << "! ";
    for (int i=0; i<7; i++) cout << ans[i].second;
    cout << endl;
}

signed main(){
    //cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++) solve();
    return 0;
}