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

vector<vector<ll>> comb(111111, vector<ll>(100, -1));
ll Combination(ll a, ll b)
{
    if (comb[a][b] != -1) {
        return comb[a][b];
    }

    if (b > a / 2) {
        return Combination(a, a - b);
    }

    if (a == b || b == 0) {
        return 1;
    }

    if (comb[a-1][b-1] == -1) {
        comb[a-1][b-1] = Combination(a-1, b-1);
    }

    if (comb[a-1][b] == -1) {
        comb[a-1][b] = Combination(a-1, b);
    }

    comb[a][b] = (comb[a-1][b-1] + comb[a-1][b]) % MOD;

    return comb[a][b];
}
