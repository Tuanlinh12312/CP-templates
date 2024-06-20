const ld eps=1e-9;
const ll inf=2;

ll gaussian_elimination(vector <vector <ld>> a, vector <ld> &ans)
{
    ll n=a.size(), m=a[0].size()-1;
    vector <ll> where(m, -1);
    for (ll col=0, row=0; col<m && row<n; col++)
    {
        ll sel=row;
        for (ll i=row; i<n; i++)
            if (abs(a[i][col])>abs(a[sel][col]))
                sel=i;
        if (abs(a[sel][col])<eps)
            continue;
        for (ll i=col; i<=m; i++)
            swap(a[sel][i], a[row][i]);
        where[col]=row;
        for (ll i=0; i<n; i++)
            if (i!=row)
            {
                ld c=a[i][col]/a[row][col];
                for (ll j=col; j<=m; j++)
                    a[i][j]-=a[row][j]*c;
            }
        row++;
    }
    ans.assign(m, 0);
    for (ll i=0; i<m; i++)
        if (where[i]!=-1)
            ans[i]=a[where[i]][m]/a[where[i]][i];
    for (ll i=0; i<n; i++) {
        ld sum=0;
        for (ll j=0; j<m; j++)
            sum+=ans[j]*a[i][j];
        if (abs(sum-a[i][m])>eps)
            return 0;
    }
    for (ll i=0; i<m; i++)
        if (where[i]==-1)
            return inf;
    return 1;
}
