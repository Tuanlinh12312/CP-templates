struct Lichao
{
    static const ll maxv=1e5, inf=1e18;
    ll div(ll x) {return (x-!!(x%2))/2;}
    
    struct Node
    {
        ll l=-1, r=-1, a, b;
        Node (ll a, ll b): a(a), b(b){}
        ll eval(ll x) {return a*x+b;}
    };
    vector <Node> t;
 
    void insert(ll a, ll b)
    {
        Node L(a, b);
        if (!t.size()) {t.pb(L); return;}
        ll id=0, Start=0, End=maxv;
        while (Start<=End)
        {
            ll mid=div(Start+End);
            bool s=L.eval(Start)>t[id].eval(Start);
            bool m=L.eval(mid)>t[id].eval(mid);
            if (m) swap(L.a, t[id].a), swap(L.b, t[id].b);
            if (Start==End) return;
            if (s!=m)
            {
                if (t[id].l==-1) {t[id].l=t.size(), t.pb(L); return;}
                End=mid, id=t[id].l;
            }
            else
            {
                if (t[id].r==-1) {t[id].r=t.size(), t.pb(L); return;}
                Start=mid+1, id=t[id].r;
            }
        }
    }
 
    ll query(ll x)
    {
        ll Start=0, End=maxv, ans=-inf, id=0;
        if (!t.size()) return 0ll;
        while (Start<=End && id!=-1)
        {
            ans=max(ans, t[id].eval(x));
            ll mid=div(Start+End);
            if (x<=mid) End=mid, id=t[id].l;
            else Start=mid+1, id=t[id].r;
        }
        return ans;
    }
};