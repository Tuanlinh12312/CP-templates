struct Dinic
{
    struct flowedge
    {
        ll u, v, cap, flow=0;

        flowedge(){}
        flowedge(ll u, ll v, ll cap): u(u), v(v), cap(cap){}
    };

    ll n, m=0, s, t;
    vector <flowedge> edge;
    vector <vector <ll>> A;
    vector <ll> ptr, level;
    queue <ll> q;

    vector <ll> in_sum, out_sum;
    vector <pair<pll, ll>> edgen;

    Dinic(ll n, ll s, ll t): n(n), s(s), t(t)
    {
        in_sum.assign(n, 0);
        out_sum.assign(n, 0);
    }

    void addedge(ll u, ll v, ll low, ll cap)
    {
        in_sum[v]+=low; out_sum[u]+=low;
        edgen.pb({{u, v}, cap-low});
    }

    void build_demands()
    {
        A.resize(n+2);
        ptr.resize(n+2);
        level.resize(n+2);
        for (ll i=0; i<n; i++)
        {
            addedge(n, i, in_sum[i]);
            addedge(i, n+1, out_sum[i]);
        }
        for (pair<pll, ll> i:edgen)
            addedge(i.fi.fi, i.fi.se, i.se);
        addedge(t, s, 1e9);
        s=n, t=n+1; n+=2;
    }

    void addedge(ll u, ll v, ll cap)
    {
        if (cap==0) return;
        edge.emplace_back(u, v, cap);
        edge.emplace_back(v, u, 0);
        A[u].pb(m); A[v].pb(m+1); m+=2;
    }

    bool bfs()
    {
        q.push(s); level[s]=0;
        while (!q.empty())
        {
            ll u=q.front(); q.pop();
            for (ll idx:A[u])
            {
                flowedge crr=edge[idx];
                ll v=crr.v, flow=crr.flow, cap=crr.cap;
                if (level[v]!=-1 || flow>=cap)
                    continue;
                level[v]=level[u]+1;
                q.push(v);
            }
        }
        return level[t]!=-1;
    }

    ll dfs(ll u, ll pushed)
    {
        if (u==t || pushed==0)
            return pushed;
        for (ll& i=ptr[u]; i<A[u].size(); i++)
        {
            flowedge crr=edge[A[u][i]];
            ll v=crr.v, flow=crr.flow, cap=crr.cap;
            if (level[v]!=level[u]+1 || flow>=cap)
                continue;
            ll val=dfs(v, min(cap-flow, pushed));
            if (val==0) continue;
            edge[A[u][i]].flow+=val;
            edge[A[u][i]^1].flow-=val;
            return val;
        }
        return 0;
    }

    ll flow()
    {
        ll ans=0;
        while (1)
        {
            fill(level.begin(), level.end(), -1);
            if (!bfs()) break;

            fill(ptr.begin(), ptr.end(), 0);
            while (ll f=dfs(s, INT_MAX))
                ans+=f;
        }
        return ans;
    }
};