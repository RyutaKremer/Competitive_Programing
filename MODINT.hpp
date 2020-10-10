//ref: https://qiita.com/DaikiSuyama/items/2dcc49932f2489292e44 (2020/10/11)

template<ll mod> class modint{
public:
    ll val=0;

    modint(ll x=0){while(x<0)x+=mod;val=x%mod;}

    modint(const modint &r){val=r.val;}

    modint operator -(){return modint(-val);}

    modint &operator +=(const modint &r){
        val+=r.val;
        if(val>=mod)val-=mod;
        return *this;
    }
    modint &operator +=(const ll r){
        val+=r;
        if(val>=mod)val-=mod;
        return *this;
    }
    modint &operator -=(const modint &r){
        if(val<r.val)val+=mod;
        val-=r.val;
        return *this;
    }
    modint &operator -=(const ll r){
        if(val<r)val+=mod;
        val-=r;
        return *this;
    }
    modint &operator *=(const modint &r){
        val=val*r.val%mod;
        return *this;
    }
    modint &operator *=(const ll r){
        val=val*r%mod;
        return *this;
    }
    modint &operator /=(const modint &r){
        ll a=r.val,b=mod,u=1,v=0;
        while(b){
            ll t=a/b;
            a-=t*b;swap(a,b);
            u-=t*v;swap(u,v);
        }
        val=val*u%mod;
        if(val<0)val+=mod;
        return *this;
    }
    modint &operator /=(const ll r){
        ll a=r,b=mod,u=1,v=0;
        while(b){
            ll t=a/b;
            a-=t*b;swap(a,b);
            u-=t*v;swap(u,v);
        }
        val=val*u%mod;
        if(val<0)val+=mod;
        return *this;
    }

    bool operator ==(const modint& r){return this->val==r.val;}
    bool operator <(const modint& r){return this->val<r.val;}
    bool operator <=(const modint& r){return this->val<=r.val;}
    bool operator >(const modint& r){return this->val>r.val;}
    bool operator >=(const modint& r){return this->val>=r.val;}
    bool operator !=(const modint& r){return this->val!=r.val;}
};

//to allow (ll) <operand> (modint)
template<ll mod> modint<mod> operator +(const modint<mod> &l, const modint<mod> &r){return modint<mod>(l)+=r;}
template<ll mod> modint<mod> operator +(ll l, const modint<mod> &r){return modint<mod>(l)+=r;}
template<ll mod> modint<mod> operator +(const modint<mod> &l, ll r){return modint<mod>(l)+=r;}
template<ll mod> modint<mod> operator -(const modint<mod> &l, const modint<mod> &r){return modint<mod>(l)-=r;}
template<ll mod> modint<mod> operator -(ll l, const modint<mod> &r){return modint<mod>(l)-=r;}
template<ll mod> modint<mod> operator -(const modint<mod> &l, ll r){return modint<mod>(l)-=r;}
template<ll mod> modint<mod> operator *(const modint<mod> &l, const modint<mod> &r){return modint<mod>(l)*=r;}
template<ll mod> modint<mod> operator *(ll l, const modint<mod> &r){return modint<mod>(l)*=r;}
template<ll mod> modint<mod> operator *(const modint<mod> &l, ll r){return modint<mod>(l)*=r;}
template<ll mod> modint<mod> operator /(const modint<mod> &l, const modint<mod> &r){return modint<mod>(l)/=r;}
template<ll mod> modint<mod> operator /(ll l, const modint<mod> &r){return modint<mod>(l)/=r;}
template<ll mod> modint<mod> operator /(const modint<mod> &l, ll r){return modint<mod>(l)/=r;}
    //ここで怒られる可能性がある (暗黙的な型変換のため？) (多分消しても動く)
template<ll mod> bool operator ==(ll l, const modint<mod>& r){return l==r.val;}
template<ll mod> bool operator ==(const modint<mod>&l, ll r){return l.val==r;}
template<ll mod> bool operator <(ll l, const modint<mod>& r){return l<r.val;}
template<ll mod> bool operator <(const modint<mod>&l, ll r){return l.val<r;}
template<ll mod> bool operator <=(ll l, const modint<mod>& r){return l<=r.val;}
template<ll mod> bool operator <=(const modint<mod>&l, ll r){return l.val<=r;}
template<ll mod> bool operator >(ll l, const modint<mod>& r){return l>r.val;}
template<ll mod> bool operator >(const modint<mod>&l, ll r){return l.val>r;}
template<ll mod> bool operator >=(ll l, const modint<mod>& r){return l>=r.val;}
template<ll mod> bool operator >=(const modint<mod>&l, ll r){return l.val>=r;}
template<ll mod> bool operator !=(ll l, const modint<mod>& r){return l!=r.val;}
template<ll mod> bool operator !=(const modint<mod>&l, ll r){return l.val!=r;}

using mint = modint<MOD>;

istream &operator >>(istream &is,mint& x){
    ll t;is >> t;
    x=t;
    return (is);
}
ostream &operator <<(ostream &os,const mint& x){
    return os<<x.val;
}

mint modpow(const mint &a,ll n){
    if(n==0)return 1;
    mint t=modpow(a,n/2);
    t=t*t;
    if(n&1)t=t*a;
    return t;
}

mint fac[MAXR+1],finv[MAXR+1],inv[MAXR+1];

void COMinit() {
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    FOR(i,2,MAXR){
        fac[i]=fac[i-1]*mint(i);
        inv[i]=-inv[MOD%i]*mint(MOD/i);
        finv[i]=finv[i-1]*inv[i];
    }
}

mint COM(ll n,ll k){
    if(n<k)return 0;
    if(n<0 || k<0)return 0;
    return fac[n]*finv[k]*finv[n-k];
}