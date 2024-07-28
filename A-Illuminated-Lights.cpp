#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename T, typename U> using pb_map = gp_hash_table<T, U, chash>;
template<typename T> using pb_set = gp_hash_table<T, null_type, chash>;
#define endl '\n'
#define K first
#define V second

typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

constexpr ll NN = 2e5;
constexpr ll M = 1000000007;



void run()
{
    int n; cin >> n;
    string s; cin >> s;
    cout << (s[0] == 'R' || s[n-1] == 'L' ? 1 : 2) << endl;
}

int main()
{
    //KING OF THE WORLD...... U.W.T.B
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
    int t; cin>>t; while(t--) run();
}
