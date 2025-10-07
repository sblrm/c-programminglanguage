#include <stdio.h>

int hasilPembagian(int x, int y){
	
	int result;
	result = x/y;
	return result;
	
}

void displayHasil(int a, int b, int hasil){
	
	if(hasil = a / b){
		printf("Hasil dari pembagian %d dan %d adalah %d\n", a, b, hasil);
	}else{
		printf("Hasil dari pembagian %d dan %d adalah koma.", a, b);	
	}
}


int main(){

	int maka;
	int num1, num2;
	printf("Masukkan angka pertama: ");
	scanf("%d", &num1);
	printf("Masukkan angka kedua: ");
	scanf("%d", &num2);
	
	maka = hasilPembagian(num1, num2);
	displayHasil(num1, num2, maka);

	return 0;

}

