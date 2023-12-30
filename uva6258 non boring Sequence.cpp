#include <iostream>
#include <map>
#include <algorithm>

#define maxn 200005

using namespace std;

map<int, int> m;
int l[maxn], r[maxn];

bool check(int s, int e){
	if(s >= e){
		return true;
	}
	
	for(int i = 0; i <= (e-s) / 2; i++){
		if(l[s+i] < s && r[s+i] > e){
			return check(s, s+i-1) && check(s+i+1, e);
		} 
		if(l[e-i] < s && r[e-i] > e){
			return check(s, e+i-1) && check(e+i+1, e);
		}
	}
	return false;
}

int main()
{
	int cas, n, arr[maxn];
	
	scanf("%d", &cas);
	while(cas--){
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
		}
		
		m.clear();
		
		for(int i = 0; i < n; i++){
			if(m.count(arr[i])) l[i] = m[arr[i]];
			else l[i] = -1;
			m[arr[i]] = i; 
		}
		
		m.clear();
		for(int i = n-1; i >= 0; i--){
			if(m.count(arr[i])) r[i] = m[arr[i]];
			else r[i] = n;
			m[arr[i]] = i; 
		}
		
		if(check(0, n-1)) printf("non-boring\n");
		else printf("boring\n");
	}
}
