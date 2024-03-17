#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void banner(){
    system("cls");
    printf("\t\t\t\t==============================\n");
    printf("\t\t\t\t||      SPELLING CHECKER    ||\n");
    printf("\t\t\t\t||      BAHASA INDONESIA    ||\n");
    printf("\t\t\t\t==============================\n");
    carikata();
}

void carikata(){
    FILE *file;
    char kata[100], line[1000];
    int found = 0;

    printf("\nMasukkan abjad atau kata yang Anda cari untuk menampilkan daftar kata\n");
    printf("Masukkan abjad atau kata: ");
    scanf("%s", kata);

    file = fopen("d:\\db.txt", "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {

        if (strstr(line, kata) != NULL) {
            found = 1;
            printf("Kata tersedia: %s", line);
        }
    }

    fclose(file);

    if (!found) {
        system("cls");
        printf("\t\t\t\tKata yang Anda cari tidak ada di Kamus.\n");
    }
    ejaan();
}

int ejaan(){
    char typo[100];
    printf("\n\n\t\t\t\tSPELLING CHECKER\n");
    printf("\nMasukkan kata salah eja: ");
    scanf("%s", typo);
}

int main (){
    banner();
    return 0;
}
