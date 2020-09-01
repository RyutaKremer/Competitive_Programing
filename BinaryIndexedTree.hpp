//蟻本参考
//整数配列の和に対応
class BIT {
public:
    VLL bit;
    int num;

    BIT(int n) {
        num = n;
        bit.resize(n + 1);
    }

    ll sum(int i)
    {
        ll r = 0ll;
        while (i > 0) {
            r += bit[i];
            i -= i & -i;
        }
        return r;
    }

    void add(int i, ll x)
    {
        while (i <= num) {
            bit[i] += x;
            i += i & -i;
        }
    }

    void sub(int i, ll x)
    {
        add(i,-x);
    }
};