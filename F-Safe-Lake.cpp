#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define K first
#define V second
#define N 510

string s[N];
ll n;
bool used[N][N];

void dfs(ll i, ll j, char c) {
    if(min(i, j) < 0 || max(i, j) >= n || used[i][j] || (s[i][j] - '?' && s[i][j] - c)) return;
    s[i][j] = c;
    used[i][j] = true;
    dfs(i - 1, j, 'D');
    dfs(i + 1, j, 'U');
    dfs(i, j - 1, 'R');
    dfs(i, j + 1, 'L');
}

int main() {
    G(tc) while(tc--) {
        cin >> n;
        F(i, 0, n) fill_n(used[i], n, 0), cin >> s[i];
        F(i, 0, n) {
            dfs(0, i, 'U');
            dfs(n - 1, i, 'D');
            dfs(i, 0, 'L');
            dfs(i, n - 1, 'R');
        }
        bool ok = true;
        F(i, 0, n) F(j, 0, n) if(!used[i][j]) ok = false;
        if(ok) F(i, 0, n) cout << s[i] << '\n';
        else cout << "-1\n";
    }
}
