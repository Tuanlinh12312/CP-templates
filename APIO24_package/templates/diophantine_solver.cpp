ll gcd(ll a, ll b, ll& x, ll& y) 
{
    if (b==0) 
    {
        x=1, y=0;
        return a;
    }
    ll x1, y1, d=gcd(b, a%b, x1, y1);
    x=y1, y=x1-y1*(a/b);
    return d;
}

// ax + by = c -> x = x0 + k*(b/g), y = y0 - k*(a/g)
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) 
{
    g=gcd(abs(a), abs(b), x0, y0);
    if (c%g) return 0;
    x0*=c/g, y0*=c/g;
    if (a<0) x0=-x0;
    if (b<0) y0=-y0;
    return 1;
}