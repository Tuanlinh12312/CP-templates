// a is concave
// c_k=max(a_i+b_j) for all i+j=k
const ll inf=1e18;
vector <ll> max_plus_convolution(const vector <ll> &a, const vector <ll> &b)
{
    auto eval=[&](ll idx, ll x) {if (idx<0) return -inf; return b[idx]+a[x-idx];};
    struct Node 
    {
        ll idx, l, r;
        Node(ll idx): idx(idx), l(-1), r(-1){}
    }; 
    vector <Node> t; t.emplace_back(-1);
    function <void(ll, ll, ll, ll)> update=[&](ll i, ll Start, ll End, ll idx)
    {
        ll l=idx, r=idx+sz(a)-1;
        if (Start>=l && End<=r)
        {
            while (Start<=End)
            {
                ll mid=(Start+End)/2;
                bool s=eval(idx, Start)>eval(t[i].idx, Start);
                bool m=eval(idx, mid)>eval(t[i].idx, mid);
                if (m) swap(idx, t[i].idx);
                if (Start==End) return;
                if (s!=m)
                {
                    if (t[i].l==-1) {t[i].l=sz(t), t.emplace_back(idx); return;}
                    End=mid, i=t[i].l;
                }
                else
                {
                    if (t[i].r==-1) {t[i].r=sz(t), t.emplace_back(idx); return;}
                    Start=mid+1, i=t[i].r;
                }
            }
            return;
        }
        ll mid=(Start+End)/2;
        if (mid>=l)
        {
            if (t[i].l==-1) t[i].l=sz(t), t.emplace_back(-1);
            update(t[i].l, Start, mid, idx);
        }
        if (mid+1<=r)
        {
            if (t[i].r==-1) t[i].r=sz(t), t.emplace_back(-1);
            update(t[i].r, mid+1, End, idx);
        }
    };
    for (ll i=0; i<sz(b); i++) update(0, 0, sz(a)+sz(b)-2, i);
    vector <ll> res(sz(a)+sz(b)-1, -inf);
    for (ll x=0; x<sz(res); x++)
    {
        ll Start=0, End=sz(a)+sz(b)-2, ans=-inf, i=0;
        while (Start<=End && i!=-1)
        {
            ans=max(ans, eval(t[i].idx, x));
            ll mid=(Start+End)/2;
            if (x<=mid) End=mid, i=t[i].l;
            else Start=mid+1, i=t[i].r;
        }
        res[x]=ans;
    }
    return res;
}