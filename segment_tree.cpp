#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;


void update(ll tree[], ll n, ll k, ll x) {
    k = n + k;
    ll old_val = tree[k], new_val = x;
    tree[k] = (new_val - old_val);
    k /= 2;
    while (k >= 1) {
        tree[k] += (new_val - old_val);
        k /= 2; 
    }
}


ll sum(ll tree[], ll n, ll a, ll b) {
    a += n;
    b += n;
    ll s = 0;
    while (a <= b) {
        if (a % 2 == 1) s += tree[a++];
        if (b % 2 == 0) s += tree[b--];
        a /= 2;
        b /= 2;
    }
    return s;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n = 8;
    ll arr[n] = {5, 8, 6, 3, 2, 7, 2, 6}; 
    ll tree[2*n] = {0};


    for (ll i = 0; i < n; i++) {
        update(tree, n, i, arr[i]);
    }

    cout << "Tree: ";
    for (ll i = 0; i < 2*n; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;

    cout << "Sum(2,7): " << sum(tree, n, 2, 7) << endl;

    return 0;
}
