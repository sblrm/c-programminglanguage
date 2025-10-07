#include <stdio.h>

int i, j;

int main()
{
	int t, n;
	long long int a, b;
	scanf("%d", &t);
	for(j=0;j<t;j++){
		scanf("%d %d %d", &n, &a, &b);
		int jo[n+1];
		jo[0] = a;
		jo[1] = b;
		for(i=0;i<=n;i++){
			if(i<2) jo[i] = jo[i];
			else jo[i] = jo[i-1] - jo[i-2];
			if(i==n) printf("Case #%d: %d\n", j+1, jo[i]);
		}
	}
	return 0;
}

