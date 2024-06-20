const ll maxn=200005;
vector <ll> A[maxn], B[maxn];
ll Time, crr, lo[maxn], num[maxn], comp[maxn];
stack <ll> st;

void dfs(ll u, ll pa)
{
    st.push(u);
    lo[u]=num[u]=++Time;
    for (ll v:A[u])
    {
        if (v==pa) continue;
        if (num[v]) lo[u]=min(lo[u], num[v]);
        else dfs(v, u), lo[u]=min(lo[u], lo[v]);
    }
    if (lo[u]==num[u])
    {
        crr++;
        while (st.top()!=u)
            comp[st.top()]=crr, st.pop();
        comp[st.top()]=crr, st.pop();
    }
}

void build(ll n)
{
    map <pll, bool> Map;
    for (ll i=1; i<=n; i++)
        for (ll j:A[i])
        {
            ll ci=comp[i], cj=comp[j];
            if (Map[{ci, cj}] || Map[{cj, ci}])
                continue;
            B[ci].pb(cj); B[cj].pb(ci);
            Map[{ci, cj}]=1;
        }

}