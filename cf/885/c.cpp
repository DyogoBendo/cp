#include <bits/stdc++.h>

using namespace std;

int calc(int &a, int &b){
    int total_moves = 0;
    if(a < b){
        total_moves = 2;        
        int moves = b / a;
        moves --;

        if(b % a == 0) moves --;
        total_moves += moves + ((moves) / 2);
        if(moves % 2){
            if(b % a) b = b % a;
            else{
                b = a;                
            }
        } else{
            if( b % a){
                int c;
                c = a;
                a = b % c;
                b = c;
            } else{
                b = a;                
            }
            
        }
        return total_moves;
    } else{
        int moves = a / b;                

        if(a % b == 0) moves --;
        total_moves = moves +( (moves) / 2);

        if(moves % 2){
            if(a % b){
                int c = a;
                a = b;
                b = c % b;
            } 
            else{
                b = a;
            }
        } else{
            if( a % b){
                a = b % a;
            } else{
                b = a;
            }
            
        }
        return total_moves;
    }    
    if(a == b) return 1;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }

    vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        int ca, cb;
        ca = a[i];
        cb = b[i];

        int c = 0;    
        if(ca == cb) continue;
        if(ca == 0){
            answer.push_back(1); continue;
        } 
            
        if(cb == 0){
            answer.push_back(2); continue;
        } 

        while(ca != cb){   
            int k = calc(ca, cb);            
            c += k;            
        }          
        answer.push_back(c);       
    }
    
    int possible[3] = {0, 0, 0};
    int check = 0;
    for(auto v: answer){     
        possible[v%3] = 1;
    }
    for(int i = 0; i < 3; i++) check += possible[i];
    
    if(check >  1) cout << "NO" << endl;
    else cout << "YES" << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}