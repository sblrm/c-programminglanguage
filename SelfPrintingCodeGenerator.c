#include <stdio.h>

int main(){
	char S[100];
	scanf("%[^\n]", S);
	char percent = '%';
	char revslash = 92;
	char petik = '"';
	
	printf("#include <stdio.h>\n");
	printf("int main()\n{\n");
	printf("    printf(%c%cs%cn%c,%c%s%c);", petik, percent, revslash, petik, petik, S, petik);
	printf("\n    return 0;");
	printf("\n}\n");
	
	
	return 0;
}
