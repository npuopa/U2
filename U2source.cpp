#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int main()
{
	map<int, vector<pair<int, pair<string, string> > >, greater<int> > res;
	vector<string> disqualified;
	
	ifstream in("U2.txt");
	int m;
	in >> m;
	
	while(m--){
		string city;
		int quantity;
		in >> city >> quantity;
		while(quantity--){
			string name;
			int points, mistakes;
			in >> name >> points >> mistakes;
			if(mistakes > 5){
				disqualified.push_back(name);
			}else{
				res[points - mistakes * 10].push_back({mistakes, {name, city}});
			}
		}
	}
	
	in.close();
	
	vector<pair<int, pair<string, string> > > winners = (*res.begin()).second;
	sort(winners.begin(), winners.end());
	
	ofstream out;
    out.open("U2rez.txt");
    out << (*res.begin()).first << endl;
    
    for(int i = 0; i < winners.size(); ++i){
    	out << winners[i].second.first << "\t" << winners[i].second.second << endl;	
	}
	
	if(!disqualified.empty()){
		out << "Diskvalifikuoti:" << endl;
		for(int i = 0; i < disqualified.size(); ++i){
			out << disqualified[i] << endl;
		}
	}
	
	out.close();

	return 0;
}

