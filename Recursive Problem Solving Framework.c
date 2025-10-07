#include <stdio.h>

int perpangkatan(int x, int y){
	if(y <= 1){
		return x;
	}else{
		return x * perpangkatan(x, (y - 1));
	}
}

int main(){

	int angka, pangkat;
	printf("Masukkan angka yang diinginkan: ");
	scanf("%d", &angka);
	printf("Masukkan pangkat yang diinginkan: ");
	scanf("%d", &pangkat);
	printf("Hasil dari pangkat tersebut adalah: %d\n", perpangkatan(angka, pangkat));
	
return 0;

}

