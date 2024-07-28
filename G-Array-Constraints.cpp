#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define K first
#define V second
#define N 200010

ll a[N], dep[N], sumw[N];
bool used[N];
vector<pl> graph[N];

void dfs2(ll i, ll v) {
    a[i] = v;
    used[i] = true;
    for(pl p : graph[i]) if(!used[p.K]) dfs2(p.K, p.V - v);
}

ll dfs1(ll i, ll d, ll v, ll sm) {
    if(used[i]) return 0;
    dep[i] = d;
    sumw[i] = sm;
    ll minv = v;
    for(pl p : graph[i]) if(!dep[p.K])
        minv = min(minv, dfs1(p.K, d + 1, p.V - v, sm + (d % 2 ? 1 : -1) * p.V));
    else if(!used[i] && dep[p.K] % 2 == d % 2) {
        ll ai = ((sm - sumw[p.K]) * (d % 2 ? -1 : 1) + p.V) / 2;
        dfs2(i, ai);
    }
    return minv;
}

int main() {
    G(n) G(k)
    while(k--) {
        G(u) G(v) G(w)
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    fill_n(a, n + 1, -1);
    F(i, 1, n + 1) if(!dep[i]) {
        ll mn = dfs1(i, 1, 0, 0);
        if(!used[i]) dfs2(i, -mn);
    }
    bool ok = true;
    if(*min_element(a + 1, a + n + 1) < 0) ok = false;
    F(i, 1, n + 1) for(pl p : graph[i]) if(a[i] + a[p.K] != p.V) ok = false;
    if(!ok) cout << "-1\n";
    else {
        F(i, 1, n + 1) cout << a[i] << ' ';
        cout << '\n';
    }
}
