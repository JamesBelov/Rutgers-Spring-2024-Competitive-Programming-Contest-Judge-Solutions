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
        G(x) for(ll p10 = 10;; p10 *= 10) {
            ll y = x / __gcd(p10 + 1, x);
            if(y < p10) {
                y *= (p10 / 10 + y - 1) / y;
                cout << y << y << '\n';
                break;
            }
        }
    }
}
