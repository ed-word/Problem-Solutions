#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n"
#define loop(i,n) for (ll i = 0; i < n; i++)
using namespace std;

//cahnge
vector < vector< vector<ll> > > expval(17); // 1 to 6

template <class T>
T matmul(T &m1, T &m2) {
	vector< vector<ll> > res(m1.size());
	for (int i = 0; i < m1.size(); i++) {
		res[i] = vector<ll> (m2[0].size());
		for (int j = 0; j < m2[0].size(); j++) {
			res[i][j] = 0;
			for (int k = 0; k < m1[0].size(); k++) {
				res[i][j] += m1[i][k]*m2[k][j];
			}
		}
	}
	return res;
}


template <class T>
T fastexpo(T &a, ll n) {
	if (n == 1)
		return a;

	ll t = n / 2;
	vector< vector<ll> > res = fastexpo(a, t);

	if (n % 2 == 0) {
		res = matmul(res, res);
	} else {
		vector< vector<ll> > temp = matmul(res, a);
		res = matmul(temp, res);
	}
	return res;
}

template <class T>
void precomp_binexpo(T &a, ll n) {
	// precomp a^2,a^4,...a^n
	if (n == 1) {
		expval[n] = matmul(a,a);	
		return;
	}
	precomp_binexpo(a, n-1);
	expval[n] = matmul(expval[n-1], expval[n-1]);
	return;
}

template <class T>
T binexpo(T &a, ll n) {
    expval[0] = a;
	vector <ll> pvec;
	// cout << "Binexpo" << endl;
	while (n != 0) {
		// cout << "n: " << n << endl;
		ll pow2 = (ll)log2(n);
		n -= pow(2, pow2);
		// cout << "pow2: " << pow2 << endl;
		pvec.push_back(pow2);
	}
	vector< vector<ll> > res = expval[pvec[0]];
	for (ll i = 1; i < pvec.size(); i++)
		res = matmul(res, expval[pvec[i]]);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector< vector<ll> > coeff {{1, 1}, 
                			{1, 0}};
    vector< vector<ll> > f {{1}, 
                			{0}};

    precomp_binexpo(coeff, 16);

/*    loop(i,expval.size()) {
    	cout << "Power 2^" << i << endl;
    	for (auto it1: expval[i]) {
    		for(auto it2: it1) {
    			cout << it2 << " ";
    		}
    		cout << endl;
    	}
    	cout << endl;
    }*/


    
	int t;
	cin >> t;
	while (t--) {
		ll n, m, result = 0, mod = 1e9+7;
		cin >> m >> n;
		
		vector <ll> a(m), b(m);
        loop(i,m) {
            cin >> a[i];
        }
        loop(i,m) {
            cin >> b[i];
        }
		
		if (n > 2)
			coeff = binexpo(coeff, n-2);
		else if (n == 2)
			a = b;


	    // cout << "Coeff" << endl;
    	// for (auto it1: coeff) {
    	// 	for(auto it2: it1) {
    	// 		cout << it2 << " ";
    	// 	}
    	// 	cout << endl;
    	// }


		if (n <= 2) {
			loop(i, m)
				result += (a[i]*m) % mod;
		} else {
			for (ll i=0; i < m; i++) {
				for (ll j=0; j < m; j++) {
					ll f0 = a[i];
					ll f1 = b[j];
					f[0][0] = f1;
					f[1][0] = f0;
					vector< vector<ll> > res = matmul(coeff, f);
                    ll r = res[0][0];
					result = (result + (r % mod)) % mod;
				}
			}	
		}

		cout << result << endl;

	}
	return 0;
}
