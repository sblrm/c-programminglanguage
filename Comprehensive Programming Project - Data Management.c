#include <stdio.h>
#include <string.h>

struct lecturer {
    char code[31];
    char name[31];
    char gender[11];
    int num_students;
    struct student *students;
};

struct student {
    char code[31];
    char name[31];
    char gender[11];
    struct family {
        char father_name[31];
        char mother_name[31];
        int num_siblings;
    } family;
};

int main() {
    int n, k;
    scanf("%d", &n);
    struct lecturer lecturers[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s %d", lecturers[i].code, lecturers[i].name, lecturers[i].gender, &lecturers[i].num_students);
        lecturers[i].students = malloc(lecturers[i].num_students * sizeof(struct student));
        for (int j = 0; j < lecturers[i].num_students; j++) {
            scanf("%s %s %s %s %s %d", lecturers[i].students[j].code, lecturers[i].students[j].name, lecturers[i].students[j].gender, lecturers[i].students[j].family.father_name, lecturers[i].students[j].family.mother_name, &lecturers[i].students[j].family.num_siblings);
        }
    }
    scanf("%d", &k);
    printf("Kode Dosen: %s\n", lecturers[k-1].code);
    printf("Nama Dosen: %s\n", lecturers[k-1].name);
    printf("Gender Dosen: %s\n", lecturers[k-1].gender);
    printf("Jumlah Mahasiswa: %d\n", lecturers[k-1].num_students);
    for (int i = 0; i < lecturers[k-1].num_students; i++) {
        printf("Kode Mahasiswa: %s\n", lecturers[k-1].students[i].code);
        printf("Nama Mahasiswa: %s\n", lecturers[k-1].students[i].name);
        printf("Gender Mahasiswa: %s\n", lecturers[k-1].students[i].gender);
        printf("Nama Ayah: %s\n", lecturers[k-1].students[i].family.father_name);
        printf("Nama Ibu: %s\n", lecturers[k-1].students[i].family.mother_name);
        printf("Jumlah Saudara Kandung: %d\n", lecturers[k-1].students[i].family.num_siblings);
    }
    for (int i = 0; i < n; i++) {
        free(lecturers[i].students);
    }
    return 0;
}
