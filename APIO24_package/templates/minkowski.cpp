struct point
{
    ll x, y;
    point operator + (const point & p) const 
    {
        return point{x+p.x, y+p.y};
    }
    point operator - (const point & p) const 
    {
        return point{x-p.x, y-p.y};
    }
    long long cross(const point & p) const 
    {
        return x*p.y - y*p.x;
    }
};

void reorder_polygon(vector <point> & P)
{
    ll pos=0;
    for(ll i=1; i<P.size(); i++)
        if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
            pos = i;
    rotate(P.begin(), P.begin() + pos, P.end());
}

vector <point> minkowski(vector<point> P, vector<point> Q)
{
    // the first vertex must be the lowest
    reorder_polygon(P);
    reorder_polygon(Q);
    // we must ensure cyclic indexing
    P.push_back(P[0]);
    P.push_back(P[1]);
    Q.push_back(Q[0]);
    Q.push_back(Q[1]);
    // main part
    vector<point> result;
    ll i=0, j=0;
    while(i<P.size()-2 || j<Q.size()-2)
    {
        result.push_back(P[i]+Q[j]);
        auto cross=(P[i+1]-P[i]).cross(Q[j+1]-Q[j]);
        if(cross>=0 && i<P.size()-2) i++;
        if(cross<=0 && j<Q.size()-2) j++;
    }
    return result;
}