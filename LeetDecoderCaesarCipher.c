#include <stdio.h>
#include <string.h>

int main()
{
	FILE* file;
	file = fopen("testdata.in","r");
	
	int T;
	int K;
	char S[1000];
	int i;
	int j;
	
	
	fscanf(file,"%d",&T);
	for(i=0;i<T;i++){
		fscanf(file,"%d",&K);
		fscanf(file," %[^\n]",S);
		for(j=0;j<strlen(S);j++){
			if(S[j]=='0'){
				S[j]='O';
			}
			else if(S[j]=='1'){
				S[j]='I';
			}
			else if(S[j]=='3'){
				S[j]='E';
			}
			else if(S[j]=='4'){
				S[j]='A';
			}
			else if(S[j]=='5'){
				S[j]='S';
			}           
			else if(S[j]=='6'){
				S[j]='G';
			}
			else if(S[j]=='7'){
				S[j]='T';
			}
			else if(S[j]=='8'){
				S[j]='B';
			}
			if(S[j]>='A'&&S[j]<='Z'){
				S[j] = (S[j] - 'A' + 26 - K) % 26 + 'A';
			}
		}
		printf("Case #%d: %s\n",i+1,S);
	}
	
	fclose(file);
	return 0;
}
