#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n); getchar();
    int index[n], nums[n], nums2[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &index[i]); getchar();
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]); getchar();
        nums2[i] = nums[i];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == index[j]){
                nums[i] = nums2[j];
            }
        }
    }
    for(int i = 0; i < n - 1; i++){
        printf("%d ", nums[i]);
    }
    int length = sizeof(nums) / sizeof(nums[0]);
    printf("%d", nums[length - 1]);
    printf("\n");
    return 0;
}