#include <stdio.h>

int main() 
{
    int n, a = 0, b = 1, next;
    int i;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
	{
        if ((i - 1) % 3 == 0)
		{
            next = 10;
        } 
		else
		{
            next = a + b;
        }
        printf("%d", a);
        if(1 != n-1)
        {
        	printf(" ");
		}
        a = b;
        b = next;
    }
    printf("\n");

    return 0;
}
