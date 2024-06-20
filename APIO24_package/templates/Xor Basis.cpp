struct XorBasis
{
    ll n;
    vector <ll> b;

    XorBasis (ll n): n(n)
    {
        b.assign(n+1, 0);
    }

    void addnum(ll mask)
    {
        for (ll i=n; i>=0; i--)
        {
            if ((mask&1<<i)==0)
                continue;
            if (b[i]==0)
            {
                b[i]=mask;
                return;
            }
            mask^=b[i];
        }
    }
};
