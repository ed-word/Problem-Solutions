#include <bits/stdc++.h>
#define loop(i,n) for (ll i=0; i<n; i++)
#define endl "\n"
typedef long long ll;
using namespace std;


ll ways = 0;
ll iteration_num = 0;
const ll n = 7, num_squares = n*n;
bool g[n][n] = {false}; 
ll i, j, k;


void search_path(ll r, ll c, ll sq_left) {
    ++iteration_num;
    if (iteration_num % 1000000000L == 0)
        cout << iteration_num << "\t";

    if (r == (n-1) && c == (n-1)) {
        if (sq_left == 1) ways++;
        else return;
    }

    bool top = false, down = false, left = false, right = false;

    if (r != 0) {
        if (!g[r-1][c]) {
            top = true;
        }
    } 
    if (r != (n-1)) {
        if (!g[r+1][c]) {
            down = true;
        }
    }
    if (c != 0) {
        if (!g[r][c-1]) {
            left = true;
        }
    } 
    if (c != (n-1)) {
        if (!g[r][c+1]) {
            right = true;
        }
    }

    if ((left && right) && (!top && !down))
        return;
    if ((top && down) && (!left && !right))
        return; 


    g[r][c] = true;
    --sq_left;    

    if (top) search_path(r-1, c, sq_left);
    if (down) search_path(r+1, c, sq_left);
    if (left) search_path(r, c-1, sq_left);
    if (right) search_path(r, c+1, sq_left);

    g[r][c] = false;
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    auto start = chrono::high_resolution_clock::now();
    g[0][0] = true;
    search_path(1, 0, num_squares-1);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::seconds>(stop - start);

    cout << endl << "Ways: " << ways*2L << endl;
    cout << "Time: " << duration.count() << endl;;

    return 0;
}
