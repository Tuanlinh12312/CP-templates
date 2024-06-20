#include<bits/stdc++.h>
#define ll int
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define sz(a) ((ll)(a).size())
using namespace std;

const ll maxn=100005, blsz=1;
vector <ll> A[maxn];
ll u[maxn], v[maxn], w[maxn], wn[maxn];
vector <vector <pair<pll, pll>>> batch;
ll answer[maxn], check[maxn];
vector <pll> edge[maxn];

namespace DSU
{
    ll pa[maxn], Rank[maxn], sz[maxn];
    void reset(ll n) {for (ll i=1; i<=n; i++) pa[i]=i, Rank[i]=0, sz[i]=1;}
    ll Find(ll i) {return pa[i]==i?i:pa[i]=Find(pa[i]);}

    void Union(ll a, ll b)
    {
        a=Find(a), b=Find(b);
        if (a==b) return;
        if (Rank[a]<Rank[b]) swap(a, b);
        if (Rank[a]==Rank[b]) Rank[a]++;
        pa[b]=a, sz[a]+=sz[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    set <pll> s;
    ll n, m; cin >> n >> m;
    for (ll i=1; i<=m; i++) cin >> u[i] >> v[i] >> w[i], w[i]=-w[i], s.insert({w[i], i});
    ll q; cin >> q;
    for (ll i=0; i<q; i++)
    {
        if (i%blsz==0) batch.emplace_back();
        ll t, a, b; cin >> t >> a >> b;
        if (t==1) answer[i]=-1;
        batch.back().pb({{-b, t}, {a, i}});
    }
    for (ll i=0; i<sz(batch); i++)
    {
        DSU::reset(n);
        for (ll j=1; j<=m; j++) wn[j]=w[j];
        vector <ll> sus;
        vector <pair<ll, pll>> Q;
        for (pair<pll, pll> j:batch[i])
            if (j.fi.se==1) sus.pb(j.se.fi);
        for (pair<pll, pll> j:batch[i])
        {
            ll we=j.fi.fi, t=j.fi.se, p=j.se.fi, id=j.se.se;
            if (t==1) wn[p]=we;
            else if (t==2)
            {
                for (ll k:sus) cout << k << " "; cout << "\n";
                Q.pb({we, {p, id}});
                for (ll x:sus) if (wn[x]<=we) edge[id].pb({u[x], v[x]});
            } 
        }
        for (ll i:sus) s.erase(mp(w[i], i));
        auto ptr=s.begin();
        sort(Q.begin(), Q.end());
        for (pair<ll, pll> j:Q)
        {
            ll we=j.fi, p=j.se.fi, id=j.se.se;
            for (; ptr!=s.end() && (*ptr).fi<=we; ptr++)
                DSU::Union(u[(*ptr).se], v[(*ptr).se]);
            for (auto &[u, v]:edge[id])
            {
                u=DSU::Find(u), v=DSU::Find(v);
                A[u].pb(v), A[v].pb(u);
            }
            vector <ll> node;
            queue <ll> q; p=DSU::Find(p), q.push(p), check[p]=1;
            while (sz(q))
            {
                ll u=q.front(); q.pop();
                node.pb(u), answer[id]+=DSU::sz[u];
                for (ll v:A[u])
                    if (!check[v])
                        check[v]=1, q.push(v);
            }
            for (ll u:node) check[u]=0;
            for (auto [u, v]:edge[id])
            {
                while (sz(A[u])) A[u].pop_back();
                while (sz(A[v])) A[v].pop_back();
            }
        }
        for (ll i:sus) s.insert(mp(wn[i], i)), w[i]=wn[i];
    }
    for (ll i=0; i<q; i++)
        if (answer[i]>=0)
            cout << answer[i] << " ";
}   
