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
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        if (n == 2 || n == 3) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = n; i >= 5; i--)
            if (i % 2 == 1)
                cout << i << " ";
        cout << 2 << " ";
        cout << 4 << " ";
        cout << 1 << " ";
        cout << 3 << " ";
        for (int i = 6; i <= n; i++)
            if (i % 2 == 0)
                cout << i << " ";
        cout << "\n";
    }
}
