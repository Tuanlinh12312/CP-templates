struct Aho
{
    struct Node
    {
        bool leaf=0;
        ll len=0, link=0, exit=0, go[26]={};
    };

    vector <Node> t;
    Aho(){t.emplace_back();}

    void addstring(string s)
    {
        ll p=0;
        for (char c:s)
        {
            c-='a';
            if (t[p].go[c]==0)
            {
                t[p].go[c]=t.size();
                t.emplace_back();
                t.back().len=t[p].len+1;
            }
            p=t[p].go[c];
        }
        t[p].leaf=1;
    }

    void build()
    {
        queue <ll> q;
        for (ll i=0; i<26; i++)
            if (t[0].go[i])
                q.push(t[0].go[i]);
        while (q.size())
        {
            ll u=q.front(); q.pop();
            if (t[u].leaf) t[u].exit=u;
            else t[u].exit=t[t[u].link].exit;
            for (ll i=0; i<26; i++)
            {
                if (t[u].go[i]) t[t[u].go[i]].link=t[t[u].link].go[i], q.push(t[u].go[i]);
                else t[u].go[i]=t[t[u].link].go[i];
            }
        }
    }
};