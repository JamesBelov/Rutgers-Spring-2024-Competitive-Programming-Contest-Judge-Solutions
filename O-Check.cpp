#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll tt;
    cin >> tt;
    while (tt--) {
        string s[8];
        for (int i = 0; i < 8; i++)
            cin >> s[i];
        bool ans = false;
        map<char, vector<pair<ll, ll>>> m;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                m[s[i][j]].push_back({i, j});
        ll x = m['K'][0].first;
        ll y = m['K'][0].second;
        vector<ll> dx, dy;
        // ROOK, QUEEN
        dx = {1, -1, 0, 0};
        dy = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            string t = "";
            ll xx = x;
            ll yy = y;
            for (int j = 0; j < 8; j++) {
                if (0 <= xx && xx < 8 && 0 <= y && y < 8)
                    t += s[xx][yy];
                xx += dx[i];
                yy += dy[i];
            }
            reverse(t.begin(), t.end());
            t.pop_back();
            while (!t.empty() && t.back() == '.')
                t.pop_back();
            if (!t.empty()) {
                ans |= t.back() == 'r';
                ans |= t.back() == 'q';
            }
        }
        // BISHOP, QUEEN
        dx = {1, 1, -1, -1};
        dy = {1, -1, 1, -1};
        for (int i = 0; i < 4; i++) {
            string t = "";
            ll xx = x;
            ll yy = y;
            for (int j = 0; j < 8; j++) {
                if (0 <= xx && xx < 8 && 0 <= y && y < 8)
                    t += s[xx][yy];
                xx += dx[i];
                yy += dy[i];
            }
            reverse(t.begin(), t.end());
            t.pop_back();
            while (!t.empty() && t.back() == '.')
                t.pop_back();
            if (!t.empty()) {
                ans |= t.back() == 'b';
                ans |= t.back() == 'q';
            }
        }
        // PAWN
        for (auto p : m['p']) {
            ans |= abs(y - p.second) == 1 && x == p.first + 1;
        }
        // KNIGHT
        for (auto p : m['n']) {
            ans |= abs(x - p.first) == 1 && abs(y - p.second) == 2;
            ans |= abs(x - p.first) == 2 && abs(y - p.second) == 1;
        }
        if (ans)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}
