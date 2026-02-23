#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

string arr;

// adcebgf
vector<int> order = {0, 4, 2, 1, 3, 6, 5};

// 1 if greater
bool cmp(char a, char b){
    cout << "? " << a << a << b << endl;
    int ans;
    cin >> ans;
    return ans;
}

bool cmptest(char a, char b){
    cout << "query: " << a << a << a << b << '\n';
    return order[a-'a'] > order[b-'a'];
}


void merge(int l, int r, int a, int b){
    string merged="";
    cout << "merging ";
    for (int i=l; i<=r; i++) cout << arr[i];
    cout << " and ";
    for (int i=a; i<=b; i++) cout << arr[i];
    cout << " = \n";

    int i=l, j=a;


    while (i<=r && j<=b){
        if (cmptest(arr[i], arr[j])) merged += arr[j++];
        else merged += arr[i++];
    }
    while (i<=r) merged += arr[i++];
    while (j<=b) merged += arr[j++];

    cout << merged << '\n';

    for (int k=l; k<=b; k++) arr[k] = merged[k-l];
}


void solve(){
    arr = "abcdefg";

    merge(0, 0, 1, 1);
    merge(2, 2, 3, 3);
    merge(4, 4, 5, 5);

    merge(0, 1, 2, 3);
    merge(4, 5, 6, 6);

    merge(0, 3, 4, 6);

    reverse(all(arr));
    cout << "! " << arr << endl;
}

signed main(){
    //cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++) solve();
}