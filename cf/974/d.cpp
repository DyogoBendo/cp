#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> vi(n, 0);
    vector<int> ve(n, 0);

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;

        vi[--a]++;
        ve[--b]--;
    }

    int i = 0;
    int j = 0;

    int x = 0;
    while(j < d){
        x += vi[j];
        j ++;
    }

    int mi = x, pi = 0;
    int ma = x, pa = 0;

    x += ve[i];

    while(j < n){
        i ++;
        x += vi[j];

        if(x > ma){
            ma = x;
            pa = i;
        }
        if(x < mi){
            mi = x;
            pi = i;
        }

        x += ve[i];
        j ++;
    } 
    
    cout << pa + 1<< " " << pi + 1 << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}