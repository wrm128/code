#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int NX = 18;
std::vector<string> vec, prefix, suffix;

void init(std::vector<string> &dic){
	//dic.clear();
	dic.push_back("0");
	dic.push_back("1");
	int a = 0, b = dic.size();
	for(int i=1; i<NX; ++i){
		//cout << "dic " << b << endl;
		for(int j=a; j<b; ++j){
			dic.push_back(dic[j]+"0");
			dic.push_back(dic[j]+"1");
		}
		a = b, b = dic.size();
	}
}

int solve(std::vector<string> &dic, std::vector<unordered_set<string> > &substr, int a, int b){
	int ret = -1;
	std::unordered_set<string> st;
	for(auto it = substr[a-1].begin(); it != substr[a-1].end(); ++ it){
		st.insert(*it);

	}
	for(auto it = substr[b-1].begin(); it != substr[b-1].end(); ++ it){
		st.insert(*it);
	}
	for(int i=0; i<suffix[a-1].length(); ++i){
		string tmp = suffix[a-1].substr(i);
		for(int j=0; j<prefix[b-1].length(); ++j){
			string join = tmp + prefix[b-1].substr(0, j+1);
			st.insert(join);
		}
	}
	for(int i=0; i<dic.size(); ++i){
		if(st.find(dic[i]) == st.end()){
			ret = dic[i].length() - 1;
			//cout << st.size() << "/" << dic[i] << endl;
			break;
		}
	}
	if(ret == -1){
		ret = NX;
	}
	substr.push_back(st);

	string joinstr = "";
	if(a <= vec.size() && b <= vec.size()){
		joinstr = vec[a-1] + vec[b-1];
		if(joinstr.length() <= NX){
			prefix.push_back(joinstr);
			suffix.push_back(joinstr);
		}else{
			prefix.push_back(joinstr.substr(0, NX));
			suffix.push_back(joinstr.substr((int)joinstr.length()-NX));
		}
	}else if(a <= vec.size()){
		joinstr = vec[a-1] + prefix[b-1];
		prefix.push_back(joinstr.substr(0, min((int)joinstr.length(), NX)));
		suffix.push_back(suffix[b-1]);
	}else if(b <= vec.size()){
		joinstr = suffix[a-1] + vec[b-1];
		prefix.push_back(prefix[a-1]);
		suffix.push_back(joinstr.substr(joinstr.length()-min((int)joinstr.length(), NX)));
	}else{
		prefix.push_back(prefix[a-1]);
		suffix.push_back(suffix[b-1]);
	}
	
	return ret;
}

string getSubStr(unordered_set<string> &st, string &tmp){
	for(int i=1; i<=NX; ++i){
		if(tmp.length() >= i){
			for(int j=0; j<=tmp.length()-i; ++j){
				st.insert(tmp.substr(j,i));
			}
		}
	}
}

// 由存储完整的字符串转为存储子串，避免MLE

int main()
{
	int m,n;  // n<=100, m<=100
	string s;
	int a,b;
	std::vector<string> dic;
	init(dic);
	//cout << "dic " << dic.size() << endl;
	while(cin >> n){
		std::vector<unordered_set<string> > substr;
		vec.clear();
		prefix.clear();
		suffix.clear();
		for(int i=0; i<n; ++i){
			unordered_set<string> tmp;
			cin >> s;
			if(s.length() <= NX){
				prefix.push_back(s);
				suffix.push_back(s);
			}else{
				prefix.push_back(s.substr(0,NX));
				suffix.push_back(s.substr(s.length()-NX));
			}
			vec.push_back(s);
			getSubStr(tmp, s);
			substr.push_back(tmp);
		}
		cin >> m;
		for(int i=0; i<m; ++i){
			cin >> a >> b;
			cout << solve(dic, substr, a, b) << endl;
		}
	}
	return 0;
}