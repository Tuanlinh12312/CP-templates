struct BIT2D
{
    ll n;
    vector <vector <ll>> pos, bit;
    BIT2D(ll n): n(n) {bit.resize(n+1), pos.resize(n+1);}

    void fupdate(ll x, ll y)
    {
        for (; x<=n; x+=x&(-x))
            pos[x].pb(y);
    }

    void build()
    {
        for (ll i=1; i<=n; i++)
        {
            pos[i].pb(0), sort(pos[i].begin(), pos[i].end());
            pos[i].resize(unique(pos[i].begin(), pos[i].end())-pos[i].begin());
            bit[i].assign(sz(pos[i]), 0);
        }
    }

    void update(ll x, ll y, ll val)
    {
        for (; x<=n; x+=x&(-x))
            for (ll j=lower_bound(pos[x].begin(), pos[x].end(), y)-pos[x].begin(); j<sz(pos[x]); j+=j&(-j))
                bit[x][j]+=val;
    }

    ll query(ll x, ll y)
    {
        ll ans=0;
        for (; x; x-=x&(-x))
            for (ll j=upper_bound(pos[x].begin(), pos[x].end(), y)-pos[x].begin()-1; j; j-=j&(-j))
                ans+=bit[x][j];
        return ans;
    }
};