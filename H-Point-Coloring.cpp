#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define K first
#define V second

int main() {
    G(tc) while(tc--) {
        G(x) G(y) ll z = 1 + x + y;
        cout << (__builtin_popcountll(z) == 1 ? __builtin_ctzll(z) : -1) << '\n';
    }
}
