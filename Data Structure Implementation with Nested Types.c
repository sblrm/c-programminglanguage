#include <stdio.h>

typedef struct Address_struct{
	char streetName[100];
	char streetNumber[5];
	char province[100];
	char country[100];
} Address;

typedef struct Student_struct{
	char nim[20];
	char nama[100];
	Address address;
} Student;

int main(){
	
	Student mahasiswa;
	
	printf("Ketik namamu: ");
	scanf("%[^\n]", mahasiswa.nama);
	getchar();
	
	printf("Ketik NIM-mu: ");
	scanf("%[^\n]", mahasiswa.nim);
	getchar();
	
	printf("Ketik nama jalan rumahmu: ");
	scanf("%[^\n]", mahasiswa.address.streetName);
	getchar();
	
	printf("Ketik nomer rumahmu: ");
	scanf("%[^\n]", mahasiswa.address.streetNumber);
	getchar();

	printf("Ketik provinsimu: ");
	scanf("%[^\n]", mahasiswa.address.province);
	getchar();
	
	printf("Ketik negaramu: ");
	scanf("%[^\n]", mahasiswa.address.country);
	getchar();
		
	printf("\n");
	
	printf("Namamu adalah: %s\n", mahasiswa.nama);
	printf("NIMmu adalah: %s\n", mahasiswa.nim);
	printf("Alamatmu adalah: %s %s, %s, %s\n", 
			mahasiswa.address.streetNumber, 
			mahasiswa.address.streetName,
			mahasiswa.address.province,
			mahasiswa.address.country);
	
	
return 0;

}

