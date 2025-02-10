#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.end());

    int pos_diferente = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        if(a[i] != b[i]){
            pos_diferente = i + 1;
            break;
        }
    }

    long double nao_acontece = 1;
    for (int i = 0; i < m; i++)
    {
        long double p;
        int r;
        cin >> r >> p;

        if(r >= pos_diferente){
            nao_acontece *=(1 - p);
        }
    }
    long double ans = 1-nao_acontece;
    if(pos_diferente == -1){
        ans = 1;   
    }

    printf("%.11Lf\n", ans);
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}