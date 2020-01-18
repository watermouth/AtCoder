#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using ll = long long;

int main() {
	ll N, K;
	string S;
	cin >> N >> K >> S;
	// K connected blocksのサイズを左から順にカウントする
	vector<int> color;
	vector<int> block_size;
	int i=0;
	while (i<N) {
		//cout << "block: " << i << endl;
		color.push_back((S[i] == '0') ? 0 : 1);
		int j=i+1;
		while (j<N) {
			if(S[i] == S[j]) ++j;
			else break;
		}
		block_size.push_back(j-i);
		i=j;
	}
	// 最も左からK block結合して, 
	int block_idx = 0;
	int operation_cnt = 0;
	vector<int> cum_block_size;
	while (block_idx < color.size()) { 
		if(color[block_idx] == 0) {
			operation_cnt++;
		}
		cum_block_size.push_back(block_size[block_idx]);
		if (block_idx > 0) {
			cum_block_size[block_idx] += cum_block_size[block_idx-1];
		}
		block_idx++;
	}
	// whiteからスタートする
	int left_block_idx = (color[0] == 0) ? 0 : 1;
	block_idx = min(2*K - 1, (ll)(color.size()-1));
	int ans = cum_block_size[block_idx++];
	for (int i=block_idx; i<block_size.size(); ++i) {
		ans = max(ans, cum_block_size[i] - cum_block_size[left_block_idx]); 
		if(color[i] == 0) {
			left_block_idx++;
		}
		//cout << left_block_idx << ", " << cum_block_size[i] << endl;
	}
	for (int i=0;i<block_size.size(); ++i) {
		//cout << block_size[i] << "," << cum_block_size[i] << endl;
	}
	cout << ans << endl;
	return 0;
}

