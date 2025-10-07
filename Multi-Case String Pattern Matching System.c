#include <stdio.h>
#include <stdbool.h>

// loop for false true statement of int 
bool isEven(int num){
	if(num % 2 == 0) return true;
	else return false;
}

int main(){
	
	// containment of input 
	unsigned int i, j, k, t, n;
	
	// input taken 
	scanf("%d", &t);
	
	// loop for triangle formation 
	for(i=1; i<=t; i++){		
		scanf("%d", &n);
		
		printf("Case #%d:\n", i);
		
		switch (isEven(n)){
			case true:
				for(j=1; j<=n; j++){
					for(k=n; k>=1; k--){
						if(k>j) printf(" ");
						else if(isEven(k+j)) printf("#");
						else printf("*");
					}
					printf("\n");
				}
			break;
			case false:
				for(j=1; j<=n; j++){
					for(k=n; k>=1; k--){
						if(k>j) printf(" ");
						else if(isEven(k+j)) printf("*");
						else printf("#");
					}
					printf("\n");
				}
			break;
		}
			
	}
	
	return 0;
	
}
