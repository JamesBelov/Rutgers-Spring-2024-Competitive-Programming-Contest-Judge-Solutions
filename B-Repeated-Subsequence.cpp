#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        vector<vector<int>> p(26);
        for(int i = 0; i < n; i++){
            p[s[i]-'a'].push_back(i);
        }

        int mx = 0;
        for(auto &v : p){
            mx = max(mx, (int)v.size());
        }

        if(mx<2){
            cout << -1 << '\n'; continue;
        }

        int ans = -1;
        int p1=0,p2=0;
        for(auto &v : p){
            for(int i = 1; i < v.size(); i++){
                if(n - (v[i]-v[i-1]) > ans){
                    ans = n - (v[i]-v[i-1]);
                    p1 = v[i-1];
                    p2 = v[i];
                }
            }
        }
        cout << s.substr(0,p1) << s.substr(p2,string::npos) << '\n';
    }
}
