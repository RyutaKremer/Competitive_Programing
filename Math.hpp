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

vector<ll> prime_num;
//nまでの素数を取得
//10^3以上には使わない方が良い
void get_prime_nembers(ll n)
{
    FOR(i,2,n + 1) {
        bool flag = true;
        REPALL(j,prime_num) {
            if (i % prime_num[j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            prime_num.push_back(i);
        }
    }
}

vector<pair<ll, ll>> factorization_vector(ll n)
{
    vector<pair<ll, ll>> rtn;

    ll m = n;
    ll idx = 0;
    for (ll i = 2; i * i <= m; i++) {
        if (n % i != 0)
            continue;

        rtn.push_back({i,0});
        while (m % i == 0) {
            rtn[idx].second++;
            m /= i;
        }
        idx++;
    }
    if (m != 1) {
        rtn.push_back({m,1});
    }

    return rtn;
}

map<ll, ll> factorization_map(ll n)
{
    map<ll, ll> rtn;

    ll m = n;
    for (ll i = 2; i * i <= m; i++) {
        while (m % i == 0) {
            rtn[i]++;
            m /= i;
        }
    }
    if (m != 1) {
        rtn[m]++;
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
    REP(i,n) {
        fac[i+1] = fac[i] * (i + 1) % MOD;
    }
    ifac[n] = mypow(fac[n], MOD - 2) % MOD;
    RREP(i,n) {
        ifac[i] = ifac[i+1] * (i + 1) % MOD;
    }
}

ll Combination(ll a, ll b)
{
    if(a == 0 && b == 0) return 1;
    if(a < b || a < 0) return 0;
    ll r = ifac[a-b] * ifac[b] % MOD;
    return r * fac[a] % MOD;
}