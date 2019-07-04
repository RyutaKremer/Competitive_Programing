//最大公約数
ll GCD(ll a, ll b)
{
    if (a == b || b == 0) {
        return a;
    } else if (a < b) {
        return GCD(b, a);
    } else {
        return GCD(b, a % b);
    }
}

//最小公倍数
ll LCM(ll a, ll b)
{
    return a * b / GCD(a, b);
}

vector<ll> primenum;
void get_prime_nembers(ll n)
{
    ll m = n;
    FOR(i,2,m+1) {
        bool flag = true;
        REPALL(j,primenum) {
            if (i % primenum[j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            primenum.push_back(i);
            while (m % i == 0) {
                m /= i;
            }
        }
        if (i > sqrt(n)+1) {
            primenum.push_back(m);
            break;
        }
    }
}

vector<pair<int, int>> prime_factorization(ll n)
{
    if (primenum.empty())
        get_prime_nembers(n);

    vector<pair<int, int>> rtn;
    REPALL(i,primenum) {
        int num = 0;
        ll tmpn = n;
        while(tmpn % primenum[i] == 0) {
            num++;
            tmpn /= primenum[i];
        }
        if (num > 0)
            rtn.push_back(make_pair(primenum[i],num));
    }
    return rtn;
}

ll mypow(ll a, ll b)
{
    ll r = 1ll;
    while(b != 0){
        if(b&1) r = r * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return r;
}

vector<ll> fac;
vector<ll> ifac;

void factorial_init(ll n)
{
    fac.resize(n+1);
    ifac.resize(n+1);
    fac[0] = 1;
    ifac[0] = 1;
    REP(i,n) {
        fac[i+1] = fac[i] * (i + 1) % MOD;
        ifac[i+1] = ifac[i] * mypow(i + 1, MOD - 2) % MOD;
    }
}

ll Combination(ll a, ll b)
{
    if(a == 0 && b == 0) return 1;
    if(a < b || a < 0) return 0;
    ll r = ifac[a-b] * ifac[b] % MOD;
    return r * fac[a] % MOD;
}