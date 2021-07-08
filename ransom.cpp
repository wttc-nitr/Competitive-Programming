#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll lcm(ll a, ll b){
    return a*b/__gcd(a,b);
}

ll inclusion_exclusion(vector<ll>const& dv, ll m_or_n){
    int n = dv.size();
    ll res = 0;
    for (int mask=0; mask < (1<<n); mask++){
        ll c_lcm = 1, cnt = 0;
        for (int i=0; i<n; i++){
            if (mask & (1<<i)){
                c_lcm = lcm(c_lcm,dv[i]);
                cnt++;
            }
        }
        if (cnt){
            if (cnt & 1)
                res += m_or_n/c_lcm;
            else res -= m_or_n/c_lcm;
        }
    }

    return res;
}

void solve(void){
    ll n,m,a,d; cin >> n >> m >> a >> d;
    vector<ll> dv{a, a+d, a+2*d, a+3*d, a+4*d};
    
    --n; // use n+1 in last
    ll suM = inclusion_exclusion(dv,m);
    ll suN = inclusion_exclusion(dv,n);
    ll n_to_m = suM-suN;
    cout << m-(n+1) + 1 - n_to_m << '\n';
}

int main(void){
     ios::sync_with_stdio(0); cin.tie(0);
     int t; cin >> t;
     while (t--){
        solve();
    }
    
    
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
