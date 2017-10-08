#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int h,m,s,t1,t2;
	while(cin >> h >> m >> s){
		cin >> t1 >> t2;
		//bool flag = false;
		std::vector<double> v;
		v.push_back(h+m/60.0+s/3600.0);  // notice that the hour hand may be affected by the minute hand and second hand
		v.push_back((m+s/60.0)/5.0);  // notice that the minute hand may be affected by the second hand
		v.push_back(s/5.0);
		sort(v.begin(), v.end());
		if(t1 > t2){
			swap(t1, t2);
		}
		//cout << t1 << " " << t2 << endl;
		if(t2 <= v[0] || t1 >= v[2]){
			cout << "YES" << endl;
			continue;
		}
		if(t1 <= v[0] && t2 >= v[2]){
			cout << "YES" << endl;
			continue;
		}
		if(t1 >= v[0] && t2 <= v[1]){
			cout << "YES" << endl;
			continue;
		}
		if(t1 >= v[1] && t2 <= v[2]){
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
	}
	return 0;
}