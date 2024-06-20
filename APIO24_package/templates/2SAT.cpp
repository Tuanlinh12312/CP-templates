ll n, k, a[maxn];
vector <ll> A[maxver], At[maxver];
vector <bool> used;
vector <ll> order, comp;

void dfs1(ll u)
{
    used[u]=1;
    for (ll v:A[u])
        if (!used[v])
            dfs1(v);
    order.pb(u);
}

void dfs2(ll u, ll idx)
{
    comp[u]=idx;
    for (ll v:At[u])
        if (comp[v]==-1)
            dfs2(v, idx);
}

bool solve_2sat()
{
    order.clear();
    used.assign(n, 0);
    for (ll i=1; i<n; i++)
        if (!used[i])
            dfs1(i);
    comp.assign(n, -1);
    for (ll i=0, j=0; i<n; i++)
    {
        ll u=order[n-i-1];
        if (comp[u]==-1)
            dfs2(u, ++j);
    }
    for (ll i=0; i<n; i+=2)
        if (comp[i]==comp[i+1])
            return false;
    return true;
}
