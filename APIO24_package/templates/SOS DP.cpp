struct SOS
{
    ll n;
    vector <ll> a, f;

    SOS (ll n): n(n)
    {
        a.assign(1<<n, 0);
        f.assign(1<<n, 0);
    }

    void init()
    {
        for (ll i=0; i<1<<n; i++)
            f[i]+=a[i];
        for (ll i=0; i<n; i++)
            for (ll mask=0; mask<1<<n; mask++)
                if (mask&(1<<i))
                    f[mask]+=f[mask^(1<<i)];
    }
};
