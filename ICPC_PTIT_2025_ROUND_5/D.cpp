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

bool cmp(string a, string b){
    if (a.sz != b.sz)
        return a.sz > b.sz;
    return a > b;
}

bool cmp2(string a, string b){
    string s1 = a + b;
    string s2 = b + a;
    if (s1 > s2) return true;
    return false;
}

void solve(){
    int n; cin >> n;
    string a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, cmp);

    sort(a, a + 3, cmp2);

    cout << a[0] + a[1] + a[2] << endl;
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
 *    created: 24-08-2025 10:03:23
**/

/*
    
*/