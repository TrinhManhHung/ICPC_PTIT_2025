#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvl vector<vector<long long>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

map<ll, ll> ptich(ll n) {
    map<ll, ll> m;
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ll cnt = 0;
            while (n % i == 0) {
                ++cnt;
                n /= i;
            }
            m[i] += cnt;
        }
    }

    if (n > 1) m[n] += 1;
    return m;
}

void solve(){
    ll n, p; cin >> n >> p;
    map<ll, ll> m1;
    m1 = ptich(p);

    ll res = 1;
    for (auto it = m1.begin(); it != m1.end(); it++) {
        ll p1 = it->fi, e1 = it->se;
        res *= pow(p1, e1 / n);
    }

    cout << res << endl;
}

int main(){
    faster();
    int TC = 1; 
    // cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}

/**
 *    author:  thienban
 *    created: 24-08-2025 09:28:49
**/

/*
    Ta có a1 x a2 x...x an = p
    Gọi g là GCD(a1,...,an) => a1 = g*b1, a2 = g*b2,..., an = g*bn
    p = g*b1 *...* g*bn = g^n * (b1*...*bn)
    => p phải chia hết cho g^n
    ptich p và g thành tsnt ta có:
        p = p1^e1 *...*pn^en
        g = p1^x1 *...*pn^xn => g^n = p1^(x1*n) *...* pn^(xn*n)
    
    p chia hết cho g^n khi e1 >= x1*n, ..., en >= xn*n
        => x1 <= e1/n, ..., xn <= en/n
        vậy g max khi x1,.., xn max
        Max(x1)=e1/n, ..., Max(xn)=en/n

    vậy Max(g) = p1^(e1/n) * p2^(e2/n) * ... * pn^(en/n)
        
*/