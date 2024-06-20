ll ok, sz, pa[300005], w[300005], Rank[300005];

struct rollback
{
    ll t, u, val, idx;
    rollback(){}
    rollback(ll t, ll u, ll val, ll idx): t(t), u(u), val(val), idx(idx){}  
    void act()
    {
        if (t==0) ok=val;
        if (t==1) sz=val;
        if (t==2) pa[u]=val;
        if (t==3) w[u]=val;
        if (t==4) Rank[u]=val;
    }
};
stack <rollback> st;
pll edge[300005];

pll Find(ll i)
{
    if (pa[i]!=i)
    {
        pll ans=Find(pa[i]);
        ans.se^=w[i];
        return ans;
    }
    return {i, 0};
}

void Union(ll a, ll b, ll val, ll idx)
{
    ll Pa, wa, Pb, wb;
    tie(Pa, wa)=Find(a); tie(Pb, wb)=Find(b);
    if (Pa==Pb)
    {
        if ((wa^wb)==val)
            return;
        st.push(rollback(0, 0, ok, idx)); 
        ok=0;
        return;
    }
    if (Rank[Pa]<Rank[Pb])
        swap(Pa, Pb), swap(wa, wb);
    if (Rank[Pa]==Rank[Pb])
    {
        st.push(rollback(4, Pa, Rank[Pa], idx));
        Rank[Pa]++;
    }
    st.push(rollback(2, Pb, pa[Pb], idx));
    pa[Pb]=Pa;
    st.push(rollback(3, Pb, w[Pb], idx));
    w[Pb]=wa^wb^val;
    st.push(rollback(1, 0, sz, idx));
    sz--;
}

void Roll(ll l, ll r)
{
    while (st.size() && st.top().idx>=l && st.top().idx<=r)
        st.top().act(), st.pop();
}

void Dsu(ll l, ll r, ll val)
{
    for (ll i=l; i<=r; i++)
    {
        ll u=edge[i].fi, v=edge[i].se;
        Union(u, v, val, i);
    }
}