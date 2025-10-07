#include <stdio.h>

int main()
{
   int rows[100];
   int i;
   int j;
   int k;
   int l;
   int r;
   int amount;
   scanf("%d", &amount);

   for(r=0; r<amount; r++){
      scanf("%d", &rows[r]);
   }

   for(l=0; l<amount; l++){
   for(i=0; i<rows[l]; i++){
      for(j=0; j<(rows[l]-i)-1;j++){
         printf(" ");
      }
      for(k=0; k<2*i+1;k++){
         printf("*");
      }
      printf("\n");
   	}
   }
   return 0;
}
