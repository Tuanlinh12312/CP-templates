struct Line
{
    mutable long long k, m, p, idx;
    bool operator < (const Line &o) const{return k<o.k;}
    bool operator < (long long o) const {return p<o;} 
};
 
struct CHT
{
    int csz = 0;
    vector <Line> data;
    long long floordiv(long long a, long long b){return a/b-(((a^b)<0) && (a%b));}
    long long isect(Line x, Line y) {
        if (x.k == y.k) return (x.m > y.m ? inf : -inf);
        return floordiv(x.m - y.m, y.k - x.k);
    }
    void add(long long k, long long m, ll idx)
    {
        k = -k, m = -m;
        Line L = {k, m, inf, idx};
        while (csz >= 2 and isect(data[csz - 2], data[csz - 1]) >= isect(data[csz - 1], L)) {
            --csz; data.pop_back();
            if (csz >= 2) data[csz - 2].p = isect(data[csz - 2], data[csz - 1]);
        }
        if (csz) data.back().p = isect(data.back(), L);
        ++csz; data.push_back(L);
    }
    pair<long long, ll> query(ll x)
    {
        auto L = *lower_bound(data.begin(), data.end(), x);
        return {-L.k*x-L.m, L.idx};
    }
};