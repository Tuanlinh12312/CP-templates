using cd=complex<double>;
const double PI=acosl(-1);

void fft(vector <cd> &a, bool invert) 
{
    ll n=sz(a);
    for (ll i=1, j=0; i<n; i++) 
    {
        ll bit=n>>1;
        for (bit; j&bit; bit>>=1) 
            j^=bit; j^=bit;
        if (i<j) swap(a[i], a[j]);
    }
    for (ll len=2; len<=n; len<<=1) 
    {
        double ang=2*PI/len*(invert?-1:1);
        cd wlen(cos(ang), sin(ang)), w(1);
        for (ll i=0; i<n; i+=len, w=cd(1)) 
            for (ll j=0; j<len/2; j++) 
            {
                cd u=a[i+j], v=a[i+j+len/2]*w;
                tie(a[i+j], a[i+j+len/2])=mp(u+v, u-v), w*=wlen;
            }
    }
    if (invert) for (cd &x:a) x/=n;
}

vector <ll> mul(vector <ll> const &a, vector <ll> const &b)
{
    vector <ll> res(sz(a)+sz(b)-1);
    vector <cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll l=32-__builtin_clz(sz(res)), n=1<<l;
    fa.resize(n), fft(fa, 0), fb.resize(n), fft(fb, 0);
    for (ll i=0; i<n; i++) fa[i]*=fb[i]; fft(fa, 1);
    for (ll i=0; i<sz(res); i++) res[i]=round(fa[i].real());
    return res;
}