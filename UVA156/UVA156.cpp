#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<unordered_map>
#include<unordered_set> 
using namespace std;	
string rearrange(string c) 
{ 
	for (int i=0; i < c.length(); i++) {
		for(int j=0; j< c.length() - 1; j++) {
			if(c[j] > c[j+1]) {
				char tmp = c[j];
				c[j] = c[j+1];
				c[j+1] = tmp;
			}
		}
	}
	return c;
}

int main()
{
	vector<string> v;
	unordered_map<string, string> dict;
	unordered_set<string> remove;
	while (1) {
		string word;
		cin >> word;
		if (word[0] == '#')
			break;
		string lower_string = word;
		transform(lower_string.begin(), lower_string.end(), lower_string.begin(), ::tolower);
		lower_string = rearrange(lower_string); 
		if (dict.find(lower_string) == dict.end() && remove.find(lower_string) == remove.end()) {
			dict[lower_string] = word;
		} else if(dict.find(lower_string) != dict.end() ) {
			dict.erase(lower_string);
			remove.insert(lower_string);
		} 
	}
	for(auto p: dict) {
		v.push_back((p.second));
	}
	sort(v.begin(), v.end());
	for (auto word: v) {
		cout << word << endl;
	}
	return 0;
}
