#include <stdio.h> 
#include <limits.h> 
  
long int max (long long  int one ,long long  int two) 
{	
	if (one >two) return one;
	else return two;
}
   
long int maxKerdos(long int timh[],long long  int n,unsigned long long  int k)  
{  
  
    int kerdos[k+1][n+1];  
   
    for (long int i = 0; i <= k; i++)  
        kerdos[i][0] = 0;  
  
    for (long int j= 0; j <= n; j++)  
        kerdos[0][j] = 0;  
  
    for (long int i = 1; i <= k; i++)  
    {  
        long int prevSub = INT_MIN;  
        for (long int j = 1; j < n; j++)  
        {  
            prevSub = max(prevSub, kerdos[i-1][j-1] - timh[j-1]);  
            kerdos[i][j] = max(kerdos[i][j-1], timh[j] + prevSub);  
        }  
    }  
   
    return kerdos[k][n-1];  
}  
   
  
int main()  
{  
    long int n,k;  
    scanf("%lld",&n);  
    scanf("%lld",&k);  
    long int timh[n];  
    for (int i=0; i<n; i++) {  
        scanf("%lld",&timh[i]);   
        }  
   
	long int result = maxKerdos( timh ,n ,k);
    printf("%lld\n",result);  
   
    return 0;  
} 
