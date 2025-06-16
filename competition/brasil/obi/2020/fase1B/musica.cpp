#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> musicaGosta(n);
    vector<int> musicasOdiada(m, -1);
    vector<int> musicasTocadas(m, 0);

    for (int i = 0; i < n; i++)
    {
        int a, d;
        cin >> a >> d;

        musicaGosta[i] = a - 1;
        if(musicasOdiada[d - 1] == -1)musicasOdiada[d - 1] = i;
    }
    

    int ans = 0;
    int current = c - 1;
    musicasTocadas[current] = 1;

    while(1){        
        if(musicasOdiada[current] == -1) break;
        ans++;
        current = musicaGosta[musicasOdiada[current]];
        if(musicasTocadas[current]){
            ans = -1;
            break;
        }
        musicasTocadas[current] = 1;
    } 

    cout << ans << endl;
}