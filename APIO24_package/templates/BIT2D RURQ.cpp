struct BIT2D_RURQ
{
    ll n;
    vector <vector <ll>> pos, A, B, C, D; // a[x][y], a[x][y]*x, a[x][y]*y, a[x][y]*x*y
    BIT2D_RURQ (ll n): n(n) {pos=A=B=C=D=vector <vector <ll>> (n+1);}

    void fupdate(ll x, ll y) {for (; x<=n; x+=x&(-x)) pos[x].pb(y);}
    void fupdate(ll x, ll y, ll l, ll r){fupdate(x, l), fupdate(x, r+1), fupdate(y+1, l), fupdate(y+1, r+1);}

    void build()
    {
        for (ll i=1; i<=n; i++)
        {
            pos[i].pb(0), sort(pos[i].begin(), pos[i].end());
            pos[i].resize(unique(pos[i].begin(), pos[i].end())-pos[i].begin());
            A[i]=B[i]=C[i]=D[i]=vector <ll> (sz(pos[i]), 0);
        }
    }

    void update(ll x, ll y, ll val)
    {
        for (ll i=x; i<=n; i+=i&(-i))
            for (ll j=lower_bound(pos[i].begin(), pos[i].end(), y)-pos[i].begin(); j<sz(pos[i]); j+=j&(-j))
                A[i][j]+=val, B[i][j]+=val*x, C[i][j]+=val*y, D[i][j]+=val*x*y;
    }
    void update(ll x, ll y, ll l, ll r, ll val) {update(x, l, val), update(x, r+1, -val), update(y+1, l, -val), update(y+1, r+1, val);}

    ll query(ll x, ll y)
    {
        ll a=0, b=0, c=0, d=0;
        for (ll i=x; i; i-=i&(-i))
            for (ll j=upper_bound(pos[i].begin(), pos[i].end(), y)-pos[i].begin()-1; j; j-=j&(-j))
                a+=A[i][j], b+=B[i][j], c+=C[i][j], d+=D[i][j];
        return a*(x+1)*(y+1)-b*(y+1)-c*(x+1)+d;
    }
};