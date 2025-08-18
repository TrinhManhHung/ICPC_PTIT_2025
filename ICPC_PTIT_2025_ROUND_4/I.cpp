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

int sumDigit(ll n) {
    string s = to_string(n);
    int ans = 0;
    for (char c : s) ans += c - '0'; 
    return ans; 

}

void solve(){
    ll n, s; cin >> n >> s;

    if (sumDigit(n) <= s) {
        cout << 0 << endl;
        return;
    }

    ll ans = 0, pow10 = 1;
    while (sumDigit(n) > s) {
        ll r = n % pow10;
        if (r != 0) {
            ll x = pow10 - r;
            n += x;
            ans += x;
        }

        pow10 *= 10; //lam tron hang tiep
    }

    cout << ans << endl;
}

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("../build/inputf.txt", "r", stdin);
        // freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    iof();
    faster();
    int TC = 1; 
    cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}

/*
    
*/