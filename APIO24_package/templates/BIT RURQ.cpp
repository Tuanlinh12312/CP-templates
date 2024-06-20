struct BIT_rurq
{
    ll n;
    vector <ll> b1, b2;

    BIT_rurq(ll n): n(n)
    {
        b1.assign(n+1, 0);
        b2.assign(n+1, 0);
    }

    void add(ll i, ll val, vector <ll> &b)
    {
        for (i; i<=n; i+=i&(-i))
            b[i]+=val;
    }

    void update(ll l, ll r, ll val)
    {
        add(l, val, b1);
        add(r+1, -val, b1);
        add(l, val*(l-1), b2);
        add(r+1, -val*r, b2);
    }

    ll sum(ll i, vector <ll> &b)
    {
        ll ans=0;
        for (i; i>0; i-=i&(-i))
            ans+=b[i];
        return ans;
    }

    ll prefix_sum(ll i)
    {
        return sum(i, b1)*i-sum(i, b2);
    }

    ll query(ll l, ll r)
    {
        return prefix_sum(r)-prefix_sum(l-1);
    }
};
