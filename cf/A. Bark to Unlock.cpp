#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	string pw;
	string tmp;
	std::vector<string> vec;
	while(cin >> pw){
		bool flag = false;
		int prefix = 0, suffix = 0;
		cin >> n;
		for(int i=0; i<n; ++i){
			cin >> tmp;
			vec.push_back(tmp);
			if(tmp == pw){
				flag = true;
			}
			if(tmp[1] == pw[0]){
				prefix += 1;
			}
			if(tmp[0] == pw[1]){
				suffix += 1;
			}
		}
		if(!flag){
			if(prefix && suffix){
				flag = true;
			}
		}
		if(flag){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}