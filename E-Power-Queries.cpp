#include<bits/stdc++.h>
#include<math.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
#define FD(i, r, l) for(ll i = r; i > (l); --i)

#define K first
#define V second
#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define F(i, l, r) for (ll i = l; i < (r); ++i)

//#define NN 200000
#define M 1000000007 // 998244353

ll inv(ll a, ll b) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } // inv a mod b


const ll NN = 201024;
vl answer(NN);
vector<vector<int>> children(NN);
vector<vector<int>> queriesAtVertex(NN);
vector<int> deltaNumQueriesByDepth(NN);

void dfs(int vertex, int depth, ll cumulativeAns, ll numActiveQueries){

    depth++;

    for(int power : queriesAtVertex[vertex]){
        cumulativeAns += power;
        deltaNumQueriesByDepth[depth+1]++;
        if(depth+1+power < NN) deltaNumQueriesByDepth[depth+1+power]--;
    }

    numActiveQueries += deltaNumQueriesByDepth[depth];
    cumulativeAns -= numActiveQueries;
    answer[vertex] = cumulativeAns;

    for(int child : children[vertex]){
        dfs(child, depth, cumulativeAns, numActiveQueries);
    }

    for(int power : queriesAtVertex[vertex]){
        deltaNumQueriesByDepth[depth+1]--;
        if(depth+1+power < NN) deltaNumQueriesByDepth[depth+1+power]++;
    }
    
}

int main(){    
    int n,q; cin >> n >> q;

    for(int i = 2; i <= n; i++){
        int parent; cin >> parent;
        children[parent].push_back(i);
    }

    for(int i = 0; i < q; i++){
        int vertex, power; cin >> vertex >> power;
        queriesAtVertex[vertex].push_back(power);
    }

    dfs(1, -1, 0, 0);
    for(int i = 1; i <= n; i++){
        cout << answer[i] << " \n"[i==n];
    }

    return 0;

}
