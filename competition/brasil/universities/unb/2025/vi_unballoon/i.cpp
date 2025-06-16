#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

struct trie {
	vector<vector<int>> to;
	vector<int> end;
	int sigma; char norm;
	trie(int sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
		to = {vector<int>(sigma)};
		end = {0};
	}
	void insert(string s) {
		int x = 0;
		for (auto c : s) {
			int &nxt = to[x][c-norm];
			if (!nxt) {
				nxt = to.size();
				to.push_back(vector<int>(sigma));
				end.push_back(0);
			}
			x = nxt;
		}
		end[x]++;
	}
	int find(string s) {
		int x = 0;
		for (auto c : s) {
			x = to[x][c-norm];
			if (!x) return -1;
		}
		return x;
	}
};
struct trie t; 
int n, k;
bool found = false;
string ans = "";

void dfs(int curr, int d){
    // cout << "s: " << ans << endl;
    if(d == k) return;
    if(found) return;
    for (int i = 0; i < 26; i++)
    {
        ans += 'a' + i;
        if(!found && !t.end[t.to[curr][i]]){
            cout << ans << endl;
            found = true;
        } else{
            dfs(t.to[curr][i], d+1);
            ans.pop_back();
        }
        if(found) break;
    }
}

signed main(){
    darvem;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        t.insert(s);
    }
    
    dfs(0, 0);
}