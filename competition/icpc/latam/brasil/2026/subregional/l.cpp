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



const int MAX = 100;
char grid[MAX][MAX];

signed main(){
    darvem;

    // *...
    grid[0][0] = '*';
    grid[0][1] = '.';
    grid[0][2] = '.';
    grid[0][3] = '.';

    //#.##
    grid[1][0] = '#';
    grid[1][1] = '.';
    grid[1][2] = '#';
    grid[1][3] = '#';

    // .\.#
    grid[2][0] = '.';
    grid[2][1] = '\\';
    grid[2][2] = '.';
    grid[2][3] = '#';

    // X#.#
    grid[3][0] = 'X';
    grid[3][1] = '#';
    grid[3][2] = '.';
    grid[3][3] = '#';

    int i = 4;
    for(int cnt_keys = 1; cnt_keys < 9; cnt_keys++){        
        //#..#
        grid[i][0] = '#';
        grid[i][1] = '.';
        grid[i][2] = '.';
        grid[i][3] = '#';
        i++;

        // #.##
        grid[i][0] = '#';
        grid[i][1] = '.';
        grid[i][2] = '#';
        grid[i][3] = '#';
        i++;

        //.\.#
        grid[i][0] = '.';
        grid[i][1] = '\\';
        grid[i][2] = '.';
        grid[i][3] = '#';
        i++;

        // X#.#
        grid[i][0] = 'X';
        grid[i][1] = '#';
        grid[i][2] = '.';
        grid[i][3] = '#';
        i++;
    }

    while(i < MAX - 1){
        // ##.#
        grid[i][0] = '#';
        grid[i][1] = '#';
        grid[i][2] = '.';
        grid[i][3] = '#';
        i++;
    }

    //F\.#
    grid[i][0] = 'F';
    grid[i][1] = '.';
    grid[i][2] = '\\';
    grid[i][3] = '#';

    /*
        *....#...#...
        #.##.#.#.#.#.
        .\.#.#.#.#.#.
        X#.#.#.#.#.#.
        #..#.#.#.#.#.
        #.##.#.#.#.#.
        .\.#.#.#.#.#.
        X#.#.#.#.#.#.
        #..#.#.#.#.#.
        #.##.#.#.#.#.
        ./.#.#.#.#.#.
        X#.#...#...#X
    */
    for(int j = 4; j < MAX; j++){
        for(int k = 0; k < MAX; k++){
            if(j & 1){
                if(j % 4 == 1 and k == MAX - 1) grid[k][j] = '.';
                else if(j % 4 == 3 and k == 0) grid[k][j] = '.';
                else grid[k][j] = '#';
            } 
            else grid[k][j] = '.';
        }
    }
    grid[0][MAX-1] = 'X';

    cout << MAX << " " << MAX << endl;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++) cout << grid[i][j];
        cout << endl;
    }
}