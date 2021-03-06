//200 - Rare Order	-	Carlo Sulzbach Sartori

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>

#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int REACHED = 1;
const int UNREACHED = 0;

int main(){
	
	
	string temp;
	while(cin >> temp){
		vector<string> list;
		list.pb(temp);
		while(cin >> temp){
			if(temp.compare("#") == 0)
				break;

			list.pb(temp);
		}

		mi adjl(26, vi());
		vi backward(26, 0);

		for(int i=0;i<list.size()-1;i++){
			string tx = list[i];
			string ty = list[i+1];
			bool diff = false;
			int x=0, y=0;
			for(;x<tx.size() && y<ty.size();x++, y++){
				if(tx[x] != ty[y]){ diff = true; break;}
			}

			if(diff){
				adjl[tx[x]-65].pb(ty[y]-65);
				backward[ty[y]-65]++;
			}	
		}

		queue<int> q;
		for(int i=0;i<26;i++){
			if(backward[i] == 0 && adjl[i].size() > 0){
				q.push(i);
				break;
			}
		}
	
		vi r(26, UNREACHED);
		queue<int> order;

		while(!q.empty()){
			int v = q.front(); q.pop();
			order.push(v);
			r[v] = REACHED;
			for(int i=0;i<adjl[v].size();i++){
				backward[adjl[v][i]]--;
				if(r[adjl[v][i]] == UNREACHED && backward[adjl[v][i]] == 0){
					q.push(adjl[v][i]);
				}
			}
		}

		while(!order.empty()){
			cout << (char)(order.front()+65);
			order.pop();
		}
		cout << endl;
	}

	return 0;
}
