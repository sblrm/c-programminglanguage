#include<stdio.h>

int main()
{
	FILE *fr;
	int A, B;
	
	fr = fopen("testdata.in","r");
	fscanf(fr,"%d %d",&A, &B);
	fclose(fr);
	
	printf("%d\n", A+B);
	

	return 0;
}
