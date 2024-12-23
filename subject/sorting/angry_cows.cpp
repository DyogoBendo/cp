#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
     setIO("angry");

    int n;
    cin >> n;

    vector<int> cows;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cows.push_back(x);
    }
    

    sort(cows.begin(), cows.end());

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int current_position = cows[i];
        int latest_position = current_position;
        int range = 1;
        // check right
        int count = 0;
        for (int j = i + 1; j < n; j++)
        {            
            if(cows[j] - current_position <= range){
                latest_position = cows[j];
                count ++;
            } else{                
                if(current_position == latest_position) break;
                current_position = latest_position;
                range ++;

                j --;                
            }
        }
        range = 1;
        current_position = cows[i];
        latest_position = current_position;
        for (int j = i - 1; j >= 0; j--)
        {
            if(current_position - cows[j] <= range){
                latest_position = cows[j];
                count ++;                
            } else{
                if(current_position == latest_position) break;
                current_position = latest_position;
                range ++;

                j ++;             
            }
        }        
        ans = max(count, ans);
        
    }
    
    cout << ans + 1 << endl;

}