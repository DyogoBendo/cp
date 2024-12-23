#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t){
        t --;
        cin >> n;
        vector<int> colors(n);

        for (int i = 0; i < n; i++)
        {
            cin >> colors[i];
        }
        
        sort(colors.begin(), colors.end());

        int result = 0;

        for (int i = 0; i < n/2; i++)
        {
            result += colors[ n - i - 1] - colors[i];
        }
        
        cout << result << endl;

    }
}