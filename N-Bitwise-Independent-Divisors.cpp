#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll ans = 1;
        while (n % 2 == 0) {
            ans += 1;
            n /= 2;
        }
        cout << ans << "\n";
        for (ll i = 0; i < ans; i++)
            cout << (1ll << i) << " ";
        cout << "\n";
    }
}
