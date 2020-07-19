//蟻本，螺旋本参考
//DisjointSet
//整数配列に対応
class UnionFindTree {
public:
    int size;
    vector<int> rank, p;
    map<int, int> frends;

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
        frends[x] = 1;
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
        if (x == y) {
            return;
        } else if (rank[x] > rank[y]) {
            frends[x] += frends[y];
            frends.erase(y);
            p[y] = x;
        } else {
            frends[y] += frends[x];
            frends.erase(x);
            p[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    int findSet(int x)
    {
        if (x != p[x]) {
            frends[p[x]] += frends[x];
            frends.erase(x);
            p[x] = findSet(p[x]);
        }
        return p[x];
    }

    int getFrendsNum(int x)
    {
        return frends[findSet(x)];
    }

    int maxUnion()
    {
        int r = 0;
        REPITR(itr,frends) {
            r = CHMAX(r, itr->e2);
        }
        return r;
    }
};