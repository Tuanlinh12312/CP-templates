void FST(vector <ll> &a, bool inv) 
{
	for (ll n=a.size(), step=1; step<n; step*=2) 
		for (ll i=0; i<n; i+=2*step)
            for (ll j=i; j<i+step; j++)
            {
                ll &u=a[j], &v=a[j+step]; 
                tie(u, v)=pll(u+v, u-v);
	    }
    if (inv) for (ll& x : a) x/=a.size(); 
}

vector <ll> conv(vector <ll> a, vector <ll> b) 
{
	FST(a, 0); FST(b, 0);
	for (ll i=0; i<a.size(); i++) 
        a[i]*=b[i];
	FST(a, 1); return a;
}