vector <pair<point, ll>> CVH(vector <pair<point, ll>> a)
{
    ll n=a.size();
    if (n<=2) return a;
    sort(a.begin(), a.end());
    vector <pair<point, ll>> cvh; 
    cvh.pb(a[0]); cvh.pb(a[1]);
    for (ll i=2; i<n; i++)
    {
        while (cvh.size()>1 && !ccw(cvh[cvh.size()-2].fi, cvh[cvh.size()-1].fi, a[i].fi))
                cvh.pop_back();
        cvh.pb(a[i]);
    }  
    for (ll i=n-2; i>=0; i--)
    {
        if (a[i].se==cvh[cvh.size()-2].se || a[i].se==cvh.back().se)
            continue;
        while (cvh.size()>1 && !ccw(cvh[cvh.size()-2].fi, cvh[cvh.size()-1].fi, a[i].fi))
                cvh.pop_back();
        cvh.pb(a[i]);
    }    
    cvh.pop_back();
    return cvh;
}