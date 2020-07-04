//蟻本，螺旋本参考
//DisjointSet
//整数配列に対応
class UnionFindTree {
public:
    int size;
    vector<int> rank, p;

    UnionFindTree() {}

    UnionFindTree(int num) {
        size = num;
        rank.resize(size, 0);
        p.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            makeSet(i);
        }
    }

    void makeSet(int x)
    {
        p[x] = x;
        rank[x] = 0;
    }

    bool same(int x, int y)
    {
        return findSet(x) == findSet(y);
    }

    void unite(int x, int y)
    {
        link(findSet(x), findSet(y));
    }

    void link(int x, int y)
    {
        if (rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    int findSet(int x)
    {
        if (x != p[x]) {
            p[x] = findSet(p[x]);
        }
        return p[x];
    }

    int maxUnion()
    {
        int r = 0;
        map<int, int> mp;
        REP(i,size) {
            mp[findSet(i)]++;
        }
        REPITR(itr,mp) {
            r = CHMAX(r, itr->e2);
        }
        return r;
    }
};