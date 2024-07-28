#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define K first
#define V second
#define M 998244353
#define N 1010

ll n, k, dp[N];

ll r(ll i) {
    if(~dp[i]) return dp[i];
    if(!i) return 1;
    dp[i] = 0;
    F(j, 0, i) if((j + 1) * (i - j) <= k)
        dp[i] = (dp[i] + r(j) * r(i - 1 - j)) % M;
    return dp[i];
}

int main() {
    G(tc) while(tc--) {
        cin >> n >> k;
        fill_n(dp, n + 1, -1);
        cout << r(n) << '\n';
    }
}
