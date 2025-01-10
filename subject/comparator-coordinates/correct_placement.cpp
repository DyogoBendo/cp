    // https://codeforces.com/problemset/problem/1472/E

    #include <bits/stdc++.h>

    using namespace std;

    class Person{
        public:
            int w, h, id;    
        Person(){
            w = 1e9 + 1;
            h = 1e9 + 1;
            id = 1e9 + 1;
        }
    };

    void solve(){
        int n;
        cin >> n;
        
        vector<Person> v;

        for (int i = 0; i < n; i++)
        {        
            Person p;
            p.id = i;
            cin >> p.h >> p.w;
            v.push_back(p);        
        }        
        vector<Person> sortedHeight = v;    

        sort(sortedHeight.begin(), sortedHeight.end(), [](const Person &p1, const Person &p2){
            if(p1.h == p2.h) return p1.w < p2.w;
            return p1.h < p2.h;
        });

        vector<int> ans(n, -1);    
        vector<Person> prefixMin;        

        Person defaultPerson;        
        prefixMin.push_back(defaultPerson);

        for (int i = 0; i < n; i++)
        {
            Person minPerson = prefixMin[i];
            if(sortedHeight[i].w < minPerson.w) minPerson = sortedHeight[i];
            prefixMin.push_back(minPerson);            
        }

        for (int i = 0; i <n; i++ )
        {              
            Person p = v[i];
            int k1 = lower_bound(
                sortedHeight.begin(), sortedHeight.end(), p.h, [](const Person &p, int value){return p.h < value;}
            ) - sortedHeight.begin();


            Person minP1 = prefixMin[k1];
            if(minP1.w < p.w){
                ans[p.id] = minP1.id + 1;
            }

            int k2 = lower_bound(
                sortedHeight.begin(), sortedHeight.end(), p.w, [](const Person &p, int value){return p.h < value;}
            ) - sortedHeight.begin();

            
            Person minP2 = prefixMin[k2];
            if(minP2.w < p.h){
                ans[p.id] = minP2.id + 1;
            }
            /*
            cout << "p: " << p.id << endl;
            cout << "k1: " << k1 << " k2: " << k2 << endl;
            cout << "min 1: " << minP1.id  << " min2: " << minP2.id << endl;
            cout << endl;
            */
        }
        
        
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    int main(){
        int t;
        cin >> t;
        while(t--) solve();
    }
