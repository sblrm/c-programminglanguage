#include <stdio.h>

int main()
{
    unsigned long long int t, m, n;
    scanf("%llu", &t); getchar();
    for(int i = 0; i < t; i++){
        scanf("%llu %llu", &m, &n); getchar();
        unsigned long long int x[m][n], max[m], res = 0;
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                x[j][k] = 0;
                scanf("%llu", &x[j][k]); getchar();
            }
        }
        printf("Case #%d: ", i + 1);
        for(int j = 0; j < m; j++){
            max[j] = 0;
            for(int k = 0; k < n; k++){
                if(x[j][k] > max[j]){
                    max[j] = x[j][k];
                }
            }
            res += max[j];
        }
        printf("%llu\n", res);
    }
    return 0;
}