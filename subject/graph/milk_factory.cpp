#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("factory");
    int n;
    cin >> n;

    vector<int> entering(n, 0);
    vector<int> leaving(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        leaving[--a] ++;
    }
    
    int current = -2;
    for (int i = 0; i < n; i++)
    {

        if(!leaving[i]){
            if(current != -2){
                current = -2;
                break;
            } else{
                current = i;
            }
        }
    }
    
    cout << current + 1 << endl;
    
}
