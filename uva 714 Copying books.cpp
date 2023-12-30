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
				if(count <= k){ // 還有組可以加 
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
		for(int i = m-1; i >= 0; i--){ // 決定分段位置 
			if((done + arr[i] > avg) || (i+1 < remain)){ // 總和大於平均值 或是 剩下數量 比 組別數小  
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
