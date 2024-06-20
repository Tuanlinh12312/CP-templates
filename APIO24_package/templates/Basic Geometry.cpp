struct point{
    ld x, y;
    point(){};
    point(ll x, ll y): x(x), y(y) {}
};

struct line{
    ld a, b, c;
    line(){}
    line(ll a, ll b, ll c): a(a), b(b), c(c) {}
    line(point A, point B)
    {
        a=B.y-A.y; b=A.x-B.x;
        c=A.y*B.x-B.y*A.x;
    }
};

struct seg{
    ld x1, y1, x2, y2, a, b, c;
    seg (ll x1, ll y1, ll x2, ll y2): x1(x1), y1(y1), x2(x2), y2(y2)
    {
        a=y2-y1; b=x1-x2;
        c=y1*x2-y2*x1;
    }
};

struct vect{
    ll x, y;

    vect (point A, point B)
    {
        x=B.x-A.x;
        y=B.y-A.y;
    }

    ll dot(const vect &A)
    {
        return x*A.x+y*A.y;
    }

    ll cross(const vect &A)
    {
        return x*A.y-A.x*y;
    }
};

ld dist_pp(point a, point b)
{
    return (ld) sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

ld dist_pl(point a, line b)
{
    ld k=(ld) sqrt(b.a*b.a+b.b*b.b);
    return (ld) abs(b.a*a.x+b.b*a.y+b.c)/k;
}

ld dist_ps(point A, seg b)
{
    point B(b.x1, b.y1), C(b.x2, b.y2);
    line D(B, C);
    vect BA(B, A), BC(B, C), CA(C, A), CB(C, B);
    ld dis=dist_pl(A, D);
    if (BA.dot(BC)<0)
        return dist_pp(A, B);
    if (CA.dot(CB)<0)
        return dist_pp(A, C);
    return dis;
}

ld dist_pa(point A, seg b)
{
    point B(b.x1, b.y1), C(b.x2, b.y2);
    line D(B, C);
    vect BA(B, A), BC(B, C);
    ld dis=dist_pl(A, D);
    if (BA.dot(BC)<0)
        return dist_pp(A, B);
    return dis;
}

point intersect (line a, line b)
{
    point ans;
    ll a1=a.a, b1=a.b, c1=a.c, a2=b.a, b2=b.b, c2=b.c;
    if (a2*b1-a1*b2==0)
    {
        ans.x=-INT_MAX;
        ans.y=-INT_MAX;
        return ans;
    }
    ans.y=((ld) -c1*a2+a1*c2)/((ld) a2*b1-a1*b2);
    if (a1==0)
        ans.x=(-c2-b2*ans.y)/((ld)a2);
    else
        ans.x=(-c1-b1*ans.y)/((ld)a1);
    return ans;
}

bool middle (point A, point B, point C)
{
    return ((B.x-A.x)*(B.x-C.x)<=0 && (B.y-A.y)*(B.y-C.y)<=0);
}

line parallel(point A, line b)
{
    line ans;
    ans.a=b.a; ans.b=b.b;
    ans.c=-A.x*b.a-A.y*b.b;
    return ans;
}
