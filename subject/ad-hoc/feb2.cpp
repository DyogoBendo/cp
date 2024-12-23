#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("feb");
    int n;
    cin >> n;
    string s;
    cin >> s;

    int odd = 0;
    int cnt = 0;
    int free = 0;

    int sequence = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'F'){
            sequence ++;
        } else{
            if(i - sequence == 0){
                free += sequence;
            } else{
                if(sequence == 0) continue;
                if(s[i] != s[i - sequence - 1]){
                    if(sequence % 2 == 1){                        
                        odd ++; 
                    } 
                } else{                    
                    if(sequence % 2 == 0){                                                                        
                        odd++;
                    } else{
                        sequence ++;
                    } 
                }
                cnt += sequence / 2;
            }
            sequence = 0;
        }
    }


    for (int i = 1; i < n; i++)
    {
        if(s[i - 1] == s[i] && s[i] != 'F') odd++;
    }
    

    free += sequence;
    if(free == n){
        cout << n - 1 << endl;
        return 0;
    }

    set<int> ans;            

    for (int i = 0; i <= cnt; i++)
    {
        int x = odd + 2 * i;
        ans.insert(x);

        if(free) ans.insert(x + 1);
    }    

    int mx = odd + 2 * cnt;    

    for (int i =2; i <= free; i++)
    {
        ans.insert(mx + i);
    }

    cout << ans.size() << endl;
    for (auto a : ans)
    {
        cout << a << endl;
    }
    
       
}