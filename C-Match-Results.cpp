#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define K first
#define V second
#define N 1000010

ll ca[N], cb[N];

int main() {
    G(tc) while(tc--) {
        G(n) GS(s) vl va, vb, ans;
        F(i, 0, n) {
            ca[i] = (i ? ca[i - 1] : 0) + (s[i] == 'A');
            cb[i] = (i ? cb[i - 1] : 0) + (s[i] == 'B');
            if(s[i] == 'A') va.push_back(i);
            else vb.push_back(i);
        }
        F(k, 1, n + 1) {
            ll cura = 0, curb = 0;
            while(1) {
                ll ia = cura + k > va.size() ? 1e9 : va[cura + k - 1];
                ll ib = curb + k > vb.size() ? 1e9 : vb[curb + k - 1];
                ll i = min(ia, ib);
                if(i >= n) break;
                if(i == n - 1) ans.push_back(k);
                cura = ca[i], curb = cb[i];
            }
        }
        cout << ans.size() << '\n';
        for(ll x : ans) cout << x << ' ';
        cout << '\n';
    }    
}
