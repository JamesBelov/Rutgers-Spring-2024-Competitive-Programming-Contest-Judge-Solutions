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
        G(n) G(m) ll ct = 0;
        while(n--) {
            string s; cin >> s;
            ct += count(s.begin(), s.end(), 'W');
        }
        cout << (ct % 2 ? "Alice\n" : "Bob\n");
    }
}
