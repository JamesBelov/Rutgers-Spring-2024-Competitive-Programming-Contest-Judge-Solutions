#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define K first
#define V second
#define N 10010

bool b[N];

bool query(ll i, ll j) {
    cout << "? " << i << ' ' << j << endl;
    G(res) return res;
}

int main() {
    G(n) vl stk;
    F(i, 1, n + 1)
        if(stk.empty()) stk.push_back(i);
        else if(query(stk.back(), i)) {
            b[stk.back()] = b[i] = true;
            stk.pop_back();
        } else stk.push_back(i);
    ll lst = 0; pl best = {-1, -1};
    F(i, 1, n + 1)
        if(b[i]) {
            if(i - lst > best.V - best.K + 1) best = {lst + 1, i};
        } else lst = i;
    if(!~best.K) cout << "! none\n";
    else cout << "! " << best.K << ' ' << best.V << endl;
}
