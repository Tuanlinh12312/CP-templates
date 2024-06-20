struct point
{
    ll x, y;
    point(){}
};

point p0;

ll orientation (point a, point b, point c)
{
    ll v=(b.y-a.y)*(c.x-b.x)-(c.y-b.y)*(b.x-a.x);
    if (v<0) return -1; // cw
    if (v>0) return 1; // ccw
    return 0;
}

ld polar_ang(point a)
{
    return atan2(a.y-p0.y, a.x-p0.x);
}

struct cmp{
    bool operator()(point a, point b)
    {
        return polar_ang(a)<polar_ang(b);
    }
};

struct CVH
{
    set <point, cmp> CV;

    void ins(point a)
    {
        if (CV.size()<=2)
        {
            CV.insert(a);
            return;
        }
        set<point>::iterator ptr=CV.lower_bound(a), ba, fr;
        if (ptr==CV.begin()) ba=CV.end();
        else ba=ptr;
        ba--;
        if (ptr==CV.end()) fr=CV.begin();
        else fr=ptr;
        if (orientation(*ba, a, *fr)>=0)
            return;
        set<point>::iterator baba=ba, frfr=fr;
        if (baba==CV.begin())
            baba=CV.end();
        baba--; frfr++;
        if (frfr==CV.end())
            frfr=CV.begin();
        while (CV.size()>2 && orientation(*ba, a, *baba)>=0)
        {
            CV.erase(ba); ba=baba;
            if (baba==CV.begin())
                baba=CV.end();
            baba--;
            if (CV.size()<=2)
                break;
        }
        if (ptr==CV.end()) fr=CV.begin();
        else fr=ptr;
        frfr=fr; frfr++;
        if (frfr==CV.end())
            frfr=CV.begin();
        while (CV.size()>2 && orientation(*fr, a, *frfr)<=0)
        {
            CV.erase(fr); fr=frfr;
            frfr++;
            if (frfr==CV.end())
                frfr=CV.begin();
            if (CV.size()<=2)
                break;
        }
        CV.insert(a);
    }

    bool query(point a)
    {
        set<point>::iterator ptr=CV.lower_bound(a), ba, fr;
        if (ptr==CV.begin()) ba=CV.end();
        else ba=ptr;
        ba--;
        if (ptr==CV.end()) fr=CV.begin();
        else fr=ptr;
        if (orientation(*ba, a, *fr)>=0)
            return 1;
        return 0;
    }

    void debug()
    {
        for (set<point>::iterator ptr=CV.begin(); ptr!=CV.end(); ptr++)
        {
            point ptr1=*ptr;
            cout << ptr1.x << " " << ptr1.y << "\n";
        }
    }
};
