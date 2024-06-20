void dfs(ll u)
{
    st.push(u);
    lo[u]=tin[u]=++Time;
    for (ll v:A[u])
    {
        if (!tin[v])
        {
            dfs(v);
            lo[u]=min(lo[u], lo[v]);
            if (lo[v]==tin[u])
            {
                crr++;
                while (st.top()!=v)
                {
                    ll un=st.top(); st.pop();
                    T[crr].pb(un); T[un].pb(crr);
                }
                T[st.top()].pb(crr); T[crr].pb(st.top()); st.pop();
                T[u].pb(crr); T[crr].pb(u);
            }
        }
        else lo[u]=min(lo[u], tin[v]);
    }
}