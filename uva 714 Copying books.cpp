#include <iostream>

using namespace std;

int main()
{
	int cas, m, k;
	int arr[505];
	
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d%d", &m, &k);
		
		long long total = 0;
		int maxn = 0;
		for(int i = 0; i < m; i++){
			scanf("%d", &arr[i]);
			maxn = max(maxn, arr[i]);
			total += arr[i];		
		}
		
		long long low = maxn, high = total, avg = (low + high) / 2;//printf("%lld %lld %lld\n", low, high, avg);
		while(low < high){ 
			
			int count = 1;
			
			long long done = 0;
			for(int i = 0; i < m; i++){
				if(count <= k){ // �٦��եi�H�[ 
					if((done + arr[i]) <= avg){
						//printf("%lld %lld\n", done+arr[i], avg);
						done += arr[i];						
					}
					else{
						done = arr[i];
						count++;
					}
				}
				
				else{
					break;
				}
			}

			if(count <= k){
				high = avg;
				avg = (low + high) / 2;
			}
			else{
				low = avg + 1;
				avg = (low + high) / 2;	
			}
		}
		
		long long done = 0;
		int print[505] = {0};
		int remain = k;
		for(int i = m-1; i >= 0; i--){ // �M�w���q��m 
			if((done + arr[i] > avg) || (i+1 < remain)){ // �`�M�j�󥭧��� �άO �ѤU�ƶq �� �էO�Ƥp  
				print[i] = 1;
				remain--;
				done = arr[i];
			}
			else{
				done += arr[i];
			}
		}
		for(int i = 0; i < m; i++){
			printf("%d", arr[i]);
			if(print[i]) printf(" / ");
			else if(i != m-1) printf(" ");
		} 
		printf("\n");
	}
} 
