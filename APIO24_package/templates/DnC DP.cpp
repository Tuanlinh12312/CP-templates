ll Cost(ll k, ll j)
{
    //calculates cost of a segment
}

void DnC(ll l, ll r, ll optl, ll optr)
{
    if (r<l)
        return;
    ll mid=(l+r)/2, opt=0;
    dp[mid]=INT_MAX;
    for (ll i=optl; i<=min(mid, optr); i++)
        if (ndp[i-1]+Cost(i, mid)
            <dp[mid])
            dp[mid]=ndp[i-1]+Cost(i, mid), opt=i;
    DnC(l, mid-1, optl, opt);
    DnC(mid+1, r, opt, optr);
}
