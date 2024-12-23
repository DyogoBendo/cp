#include <bits/stdc++.h>


using namespace std;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int solve(int k){
    int x;
    cin >> x;

    int time = 0;
    int traveled = 0;
    
    for (int speed = 1;; speed++)
    {
        traveled += speed;
        time ++;

        if(traveled >= k ){
            return time;
        }

        if(speed >= x){
            traveled += speed;
            time ++;

            if(traveled >= k) return time;
        }

    }
    

}

int main(){
    setIO("race");
    int k, n;
    cin >> k >> n;

    for (int i = 0; i < n; i++)
    {
        cout << solve(k) << endl;
    }
    
}