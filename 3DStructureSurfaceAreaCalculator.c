#include <stdio.h>
#include <stdlib.h>


int main() {
	int T;

	FILE* fp;
	fp = fopen("testdata.in", "r");
	fscanf(fp, "%d", &T);
	
	for (int i = 1; i <= T; i++) {
		int blocks; int j, k, m;
		fscanf(fp, "%d", &blocks);
		int *height = malloc(sizeof(int) * blocks);	
		int unit = 0, totalBlocks = 0, area, parameter;
		
		for(j = 0; j < blocks; j++) {
			fscanf(fp, "%d", &height[j]);
		}
		
		for(k = 0; k < blocks - 1; k++) {
			if (height[k] > height[k+1]) {
			unit += (height[k] - height[k+1]);	
			}
		}

		for(k = blocks - 1; k > 0 ; k--) {
			if (height[k] > height[k-1]) {
			unit += (height[k] - height[k-1]);	
			}
		}

		for(m = 0; m < blocks; m++) {
			totalBlocks += height[m];
		}
		
		area = 4 * totalBlocks;
		parameter = (blocks * 4) + (unit * 2) + ((height[0] + height[blocks-1]) * 2);
		

		printf("Case #%d: %d %d\n", i, parameter, area);
		free(height);
	}
	
	fclose(fp);
	return 0;
}

