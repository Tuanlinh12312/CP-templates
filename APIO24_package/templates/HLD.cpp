void dfs(ll u)
{
    child[u]=1;
    for (ll v:A[u])
    {
        if (v==pa[u])
            continue;
        pa[v]=u; dep[v]=dep[u]+1; dfs(v);
        child[v]+=child[u];
        if (!big[u] || child[v]>child[big[u]])
            big[u]=v;
    }
}

void geth(ll u)
{
    tin[u]=++Time;
    if (big[pa[u]]==u)
        head[u]=head[pa[u]];
    else head[u]=u;
    if (big[u]) geth(big[u]);
    for (ll v:A[u])
        if (v!=pa[u] && v!=big[u])
            geth(v);
}

void update(ll u, ll v, ll val)
{
    for (; head[u]!=head[v]; u=pa[head[u]])
    {
        if (dep[head[u]]<dep[head[v]])
            swap(u, v);
        update(1, 1, n, tin[head[u]], tin[u], val);
    }
    if (dep[u]<dep[v]) swap(u, v);
    update(1, 1, n, tin[v], tin[u], val);
}

ll query(ll u, ll v)
{
    bool first=0; Node ans;
    for (; head[u]!=head[v]; u=pa[head[u]])
    {
        if (dep[head[u]]<dep[head[v]])
            swap(u, v);
        Node crr=query(1, 1, n, tin[head[u]], tin[u]);
        if (!first) ans=crr, first=1;
        else ans=ans+crr;
    }
    if (dep[u]<dep[v]) swap(u, v);
    Node crr=query(1, 1, n, tin[v], tin[u]);
    if (!first) ans=crr, first=1;
    else ans=ans+crr;
    return ans.ans;
}