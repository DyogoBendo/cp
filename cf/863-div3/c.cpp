#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> values;
        for (int i = 0; i < n - 1; i++)
        {
            int x;
            cin >> x;
            values.push_back(x);
        }

        vector<int> answer;

        int i = 0;
        int j = 0;        

        answer.push_back(values[0]);

        for (int i = 1; i < n - 1; i++)
        {            
            int m = min(values[i], values[i - 1]);            
            answer.push_back(m);
        }
        
        answer.push_back(values[n - 2]);          

        for (int k = 0; k < n; k++)
        {
            cout << answer[k] << " ";
        }
        cout << endl;        
        
    }
}