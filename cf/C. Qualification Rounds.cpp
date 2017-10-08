#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// n<= 100000, k<=4
// it=(1111)b=(15)d
int main()
{
	int n,k,a;
	while(cin >> n >> k){
		bool flag = false;
		std::vector<int> tmp;
		std::vector<std::vector<int> > vec;
		//std::vector<int> sum;
		std::vector<bool> has(16,false);
		for(int i=0; i<n; ++i){
			tmp.clear();
			bool all0 = true;
			bool all1 = true;
			int it = 0;
			for(int j=0; j<k; ++j){
				cin >> a;
				tmp.push_back(a);
				if(a){
					all0 = false;
					it |= (1 << j);
				}
				if(!a){
					all1 = false;
				}
			}
			if(!all1){
				vec.push_back(tmp);
			}
			if(all0){
				flag = true;
			}
			has[it] = true;
			//sum.push_back(it);
		}
		int m = vec.size();
		for(int i=0; i<16; ++i){
			for(int j=0; j<16; ++j){
				if(has[i] && has[j] && ((i&j) == 0)){
					flag = true;
				}
			}
		}

		if(flag){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}