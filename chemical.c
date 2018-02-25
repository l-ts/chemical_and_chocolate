#include <stdio.h>
#include <limits.h>
 
long int energy(long int n ,long int arr[][n],long  int x,long int y)
{
	if (x>y) return 0;
	
	else 
	{
		long int ans2 = 0;
		for (long  int i=x; i<= y; i++)
		{
			
			for (long int j=i; j<=y; j++)
			{
				ans2+= arr[i][j];
			}
		} 
		return ans2;
	}
}

long int min (long  int one ,long  int two) 
{	
	if (one >two) return two;
	else return one;
}

long int dp(long int N,long int arr[][N],long  int i,long  int j,long int *val) 
{
	long int ans1;
	if (j==1) 
	{
		ans1 = energy(N,arr,0,i); 
		return ans1;
	}
	
	else 
	{
	for ( long int t=1; t<i; t++) 
		{	
			ans1 = min (dp( N ,arr,t,j-1,val)+ energy(N,arr, t+1,i) ,*val );
			*val = ans1;
		}
	return ans1;
	}
}

int main()

{
	long int n,k;
	scanf("%lld",&n);
	scanf("%lld",&k);
	long int a[n][n];
	for (long int i=0; i<n; i++) 
	{
		for (long long int j=0; j<n; j++) 
		{
			if (i==j) a[i][j]= 0;
			else
			{
				if (i<j) scanf("%lld",&a[i][j]);
				else a[i][j] = a[j][i];
			 }
		}
	}
    long int result = ULLONG_MAX;
    long int *val = &result;
    long int f = dp (n,a,n-1,k,val);
    printf("%lld\n",f);

    return 0;
}
