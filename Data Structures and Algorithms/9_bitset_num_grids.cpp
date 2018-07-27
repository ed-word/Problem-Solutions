#include <bits/stdc++.h>
typedef long long ll;
#define max_size (ll)1e6
using namespace std;


int main() {
	ll num_rows = 5, num_cols = 5;
	ll num_blocks = (num_cols / max_size) + bool(num_cols % max_size);
	
	bitset <max_size> rows[num_rows][num_blocks];
	string block_str;
		
	ll i, j, k, num_grids = 0, count = 0;
	for (i = 0; i < num_rows; i++) {
		for (j = 0; j < num_blocks; j++) {
			cin >> block_str;
			rows[i][j] = bitset<max_size>(block_str);
		}
	}
	

	for (i = 0; i < num_rows; i++) {
		for (j = i + 1; j < num_rows; j++) {
			count = 0;
              		for (k = 0; k < num_blocks; k++) {
                        	count += (rows[i][k] & rows[j][k]).count();
                	}
			num_grids += (count * (count - 1)) / 2;
		}
        }
	
	cout << "Num Grids: " << num_grids << endl;
	
	return 0;
}

/*
$ g++ tp.cpp && ./a.out
01001
01100
10000
01101
00000
Num Grids: 2
*/
