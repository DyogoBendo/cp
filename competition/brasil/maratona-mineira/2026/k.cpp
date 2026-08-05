#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

const int MAXN = 3e3 + 3;
int n, p;

int dp_win[MAXN][3]; 
int dp_win_tmp[MAXN][3]; 
int dp_loss[MAXN][2][2][5];
int dp_loss_tmp[MAXN][2][2][5];
int fat[MAXN];

int add(int x, int y){
    int tmp = x + y;
    if(tmp > p) tmp -= p;
    return tmp;
}

int mul(int x, int y){
    return (1LL * x * y) % p;
}

void clear(int lst){
    for(int i = 0; i < lst; i++) for(int j = 0; j < 3; j++) dp_win_tmp[i][j] = 0;
    for(int i = 0; i < lst; i++) 
        for(int j = 0; j < 2; j++) 
            for(int k = 0; k < 2; k++) 
                for(int l = 0; l < 5; l++) dp_loss_tmp[i][j][k][l] = 0;    
}

signed main(){
    darvem;
    cin >> n >> p;    

    fat[0] = 1;
    for(int i = 1; i < MAXN; i++) fat[i] = mul(fat[i-1], i);

    dp_win[0][0] = dp_loss[0][0][0][0] = 1;    

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k < 3; k++){
                int x = dp_win[j][k];
                // k = 0 -> last added was a bomb
                // k = 1 -> last added is an empty segment, but still uncliked
                // k = 2 -> last added is a clicked segment

                // add a bomb
                if(k == 0 or k == 2) dp_win_tmp[j][0] = add(dp_win_tmp[j][0], x);

                // create a new empty segment unclicked, augmenting the number of empty segments
                if(k == 0) dp_win_tmp[j+1][1] = add(dp_win_tmp[j+1][1], x);

                // expand an empty segment
                if(k == 1) dp_win_tmp[j][1] = add(dp_win_tmp[j][1], x);

                // click in a new created empty sequence
                if(k == 0) dp_win_tmp[j+1][2] = add(dp_win_tmp[j+1][2], x);

                // click in an already created empty sequence or expand
                if(k == 1 or k == 2) dp_win_tmp[j][2] = add(dp_win_tmp[j][2], x);                
            }            
        }

        for(int j = 0; j <= i; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    for(int m = 0; m < 5; m++){
                        int x = dp_loss[j][k][l][m];

                        // m = 0 -> last added a regular bomb
                        // m = 1 -> last added an empty segment, still to be clicked
                        // m = 2 -> last added an already clicked segment
                        // m = 3 -> added a segment that wont be clicked
                        // m = 4 -> added the clicked bomb
                        // k -> if there is already the clicked bomb
                        // l -> if there is already an empty segment

                        // add a regular bomb
                        if(m == 0 or m == 2 or m == 3 or m == 4) dp_loss_tmp[j][k][l][0] = add(dp_loss_tmp[j][k][l][0], x);
                        
                        // add a new empty segment still to be clicked
                        if(m == 0) dp_loss_tmp[j+1][k][l][1] = add(dp_loss_tmp[j+1][k][l][1], x);

                        // expand an empty segment still to be clicked
                        if(m == 1) dp_loss_tmp[j][k][l][1] = add(dp_loss_tmp[j][k][l][1], x);

                        // add a new clicked segment 
                        if(m == 0) dp_loss_tmp[j+1][k][l][2] = add(dp_loss_tmp[j+1][k][l][2], x);

                        // expand a clicked segment 
                        if(m == 1 or m == 2) dp_loss_tmp[j][k][l][2] = add(dp_loss_tmp[j][k][l][2], x);

                        // add a new empty segment that won't be clicked
                        if(m == 0 or m == 4) dp_loss_tmp[j][k][1][3] = add(dp_loss_tmp[j][k][1][3], x);

                        // expand an empty segment that won't be clicked
                        if(m == 3) dp_loss_tmp[j][k][1][3] = add(dp_loss_tmp[j][k][1][3], x);

                        // add a clicked bomb                        
                        if((m == 0 or m == 3) and k == 0) dp_loss_tmp[j][1][l][4] = add(dp_loss_tmp[j][1][l][4], x);
                    }
                }
            }
        }

        swap(dp_win, dp_win_tmp);
        swap(dp_loss, dp_loss_tmp);
        clear(i+1);
    }

    int ans = 0;

    // calculate wins
    for(int i = 0; i <= n; i++){        
        int curr = add(dp_win[i][0], dp_win[i][2]);
        ans = add(ans, mul(curr, fat[i]));
    }

    // calculate losses
    for(int i = 0; i <= n; i++){
        int curr = 0;
        for(int j = 0; j < 5; j++){
            if(j == 1) continue;
            curr = add(curr, dp_loss[i][1][1][j]);
        }

        ans = add(ans, mul(curr, fat[i]));
    }

    cout << ans << endl;
}