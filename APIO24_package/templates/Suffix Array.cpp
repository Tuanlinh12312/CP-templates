const ll alp=256;

vector <ll> SA(string& s)
{
    s+='$'; ll n=s.size();

    vector <ll> p(n), c(n), cnt(max(alp, n));
    for (ll i=0; i<n; i++)
        cnt[s[i]]++;
    for (ll i=1; i<alp; i++)
        cnt[i]+=cnt[i-1];
    for (ll i=0; i<n; i++)
        p[--cnt[s[i]]]=i;
    c[p[0]]=0;
    ll classes=1;
    for (ll i=1; i<n; i++)
    {
        if (s[p[i]]!=s[p[i-1]]) classes++;
        c[p[i]]=classes-1;
    }

    vector <ll> pn(n), cn(n);
    for (ll h=0; (1<<h)<n; h++)
    {
        for (ll i=0; i<n; i++)
        {
            pn[i]=p[i]-(1<<h);
            if (pn[i]<0) pn[i]+=n;
        }
        fill(cnt.begin(), cnt.begin()+classes, 0);
        for (ll i=0; i<n; i++)
            cnt[c[i]]++;
        for (ll i=1; i<classes; i++)
            cnt[i]+=cnt[i-1];
        for (ll i=n-1; i>=0; i--)
            p[--cnt[c[pn[i]]]]=pn[i];
        cn[p[0]]=0; classes=1;
        for (ll i=1; i<n; i++)
        {
            pll cur={c[p[i]], c[(p[i]+(1<<h))%n]};
            pll prev={c[p[i-1]], c[(p[i-1]+(1<<h))%n]};
            if (cur!=prev) classes++;
            cn[p[i]]=classes-1;
        }
        c.swap(cn);
    }
    s.pop_back();
    p.erase(p.begin());
    return p;
}

vector <ll> LCP(vector <ll> &p, string &s)
{
    ll n=s.size();
    vector <ll> rank(n), lcp(n-1);
    for (ll i=0; i<n; i++)
        rank[p[i]]=i;
    ll k=0;
    for (ll i=0; i<n; i++)
    {
        if (rank[i]==n-1)
        {
            k=0;
            continue;
        }
        ll j=p[rank[i]+1];
        while (j+k<n && i+k<n && s[j+k]==s[i+k])
            k++;
        lcp[rank[i]]=k;
        if (k) k--;
    }
    return lcp;
}
