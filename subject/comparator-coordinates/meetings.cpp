// https://usaco.org/index.php?page=viewproblem2&cpid=967

#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

class Cow{
    public:
        int w, x, d;
      
};

bool check_range(int r, int l, int e){
    return (r > l) && (r - 2 * e <= l);
}

int main(){
    setIO("meetings");
    int n, l;
    cin >> n >> l;

    int total_weight = 0;
    vector<Cow> cows(n);
    for (Cow &cow : cows)
    {
        cin >> cow.w >> cow.x >> cow.d;
        total_weight += cow.w;
    }
    int half_weight = (total_weight / 2) + (total_weight % 2);
    
    sort(cows.begin(), cows.end(), [&](Cow &c1, Cow &c2 ){return c1.x < c2.x;});

    vector<Cow> leftCows; // cows that are directed to left
    vector<Cow> rightCows; // cows that are directed to right

    for (Cow &cow: cows)
    {
        if(cow.d == 1){
            rightCows.push_back(cow);
        } else{
            leftCows.push_back(cow);
        }
    }
    
    
    vector<pair<int, int>> weights_time;

    for (int i = 0; i < n; i++)
    {
        Cow cow = cows[i];
        int x;
        if(i < leftCows.size()){
            x = leftCows[i].x;
        } else{
            x = l - rightCows[i - leftCows.size()].x;            
        }        
        weights_time.push_back({x, cow.w});
    }
    
    sort(weights_time.begin(), weights_time.end());

    int endtime;
    int curr_weight = 0;

    for (auto wt : weights_time)
    {  
        int time = wt.first;
        int weight = wt.second;
        
        curr_weight += weight;
        endtime = time;
        if(curr_weight >= half_weight){
            break;
        }
    }
    
    queue<int> q;
    int lst_right = 0;
    int ans = 0;    
    for (Cow &left_cow : leftCows)
    {
        while(!q.empty()){
            int r = q.front();
            if(check_range(left_cow.x, r, endtime)) break;
            q.pop();
        }

        for (int i = lst_right; i < rightCows.size(); i++)
        {
            if(check_range(left_cow.x, rightCows[i].x, endtime)){
                q.push(rightCows[i].x);
                lst_right ++;
            } else{
                break;
            }
        }                

        ans += q.size();
    }
    
    cout << ans << endl;
}