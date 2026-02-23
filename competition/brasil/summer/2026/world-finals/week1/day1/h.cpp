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

vector<int> qorder = {0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0};
int cur=0;

// 1 if greater
bool cmp(char a, char b){
    cout << "? " << a << a << a << b << '\n';
    cout << flush;
    int ans;
    cin >> ans;
    cout << '\n';
    cout << flush;
    if (cur == 2) assert(ans == qorder[cur]);
    cur++;
    return ans;
}

bool cmptest(char a, char b){
    return order[a-'a'] > order[b-'a'];
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
    arr = "abcdefg";

    merge(0, 0, 1, 1);
    merge(2, 2, 3, 3);
    merge(4, 4, 5, 5);

    merge(0, 1, 2, 3);
    merge(4, 5, 6, 6);

    merge(0, 3, 4, 6);

    cout << "! ";
    for (int i=6; i>=0; i--) cout << arr[i];
    cout << '\n';
    cout << flush;
}

signed main(){
    //cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    cin >> cases;
    cout << '\n';
    cout << flush;
    for (int i=0; i<cases; i++) solve();
    return 0;
}