struct Dinic
{
    struct flowedge
    {
        ll u, v, cap, flow=0;
        flowedge(){}
        flowedge(ll u, ll v, ll cap): u(u), v(v), cap(cap){}
    };

    ll n, m=0, s, t;
    queue <ll> q;
    vector <ll> level, ptr;
    vector <flowedge> edge;
    vector <vector <ll>> A;
    Dinic(ll n, ll s, ll t): n(n), s(s), t(t){A.resize(n);}

    void addedge(ll u, ll v, ll cap)
    {
        A[u].pb(m), A[v].pb(m+1), m+=2;
        edge.emplace_back(u, v, cap);
        edge.emplace_back(v, u, 0);
    }

    bool bfs()
    {
        level.assign(n, -1);
        q.push(s), level[s]=0;
        while (!q.empty())
        {
            ll u=q.front(); q.pop();
            for (ll i:A[u])
            {
                ll v=edge[i].v, cap=edge[i].cap, flow=edge[i].flow;
                if (level[v]!=-1 || flow==cap) continue;
                level[v]=level[u]+1, q.push(v);
            }
        }
        return level[t]!=-1;
    }

    ll dfs(ll u, ll pushed=INT_MAX)
    {
        if (pushed==0 || u==t) return pushed;
        for (ll &i=ptr[u]; i<A[u].size(); i++)
        {
            ll idx=A[u][i], v=edge[idx].v, cap=edge[idx].cap, flow=edge[idx].flow;
            if (level[v]!=level[u]+1 || flow==cap) continue;
            ll val=dfs(v, min(pushed, cap-flow));
            if (val==0) continue;
            edge[idx].flow+=val, edge[idx^1].flow-=val;
            return val;
        }
        return 0;
    }

    ll flow()
    {
        ll ans=0;
        while (bfs())
        {
            ptr.assign(n, 0);
            while (ll f=dfs(s)) ans+=f;
        }
        return ans;
    }
};