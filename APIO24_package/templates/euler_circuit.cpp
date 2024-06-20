#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
using namespace std;

ll deg[1000005], check[1000005];
vector <ll> euler_cycle;
vector <pll> A[1000005];

void dfs(ll u)
{
    for (pll child:A[u])
    {
        ll idx=child.se, v=child.fi;
        if (!check[idx])
        {
            check[idx]=1;
            dfs(v);
        }
    }
    euler_cycle.pb(u);
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin >> u >> v;
        A[u].pb({v, i}); A[v].pb({u, i});
        deg[u]++; deg[v]++;
    }
    bool ok=1;
    for (ll i=1; i<=n; i++)
        if (deg[i]%2)
        {
            ok=0;
            break;
        }
    if (!ok)
    {
        cout << "NO\n";
        exit(0);
    }
    dfs(1); 
    for (ll i:euler_cycle)
        cout << i << " ";
}
