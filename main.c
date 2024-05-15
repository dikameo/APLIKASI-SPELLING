#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include stdbool for bool type
#include <string.h>
#include <math.h>

#define MAX_WORDS 130000 // Banyaknya baris dalam txt
#define WORD_LENGTH 50 // Panjang kata
#define MAX_LINES 6
#define MAX_LENGTH 100

void load_words(const char *filename); // Deklarasi awal fungsi load_words()
int calculate_distance(const char *word1, const char *word2); // Deklarasi awal fungsi calculate_distance()
void auto_correct(const char *word);
int find_word(const char *word);
void check_word(const char *word); // Deklarasi awal fungsi check_word()
void pengejaan_kata(char *kata); // Deklarasi awal fungsi pengejaan_kata()
void saveHistory(char *word);
void displayHistory();



typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int word_count = 0;

void banner()
{
    system("cls");
    int pil;
    printf("\033[1;36m"); 
    printf("\t\t\t\t==============================\n"); 
    printf("\t\t\t\t|| SPELLING CHECKER ||\n"); 
    printf("\t\t\t\t|| BAHASA INDONESIA ||\n"); 
    printf("\t\t\t\t==============================\n");
    printf(" Masukkan Pilihan menu yang ada ingin cari :\n");
    printf("1. Cek Ejaan \n"); 
    printf("2. Cek Histori\n"); 
    printf("3. Exit \n"); 
    printf("Pilihan Anda (1/2/3) : ");
    scanf("%d", &pil);
    printf("\033[0m"); // Reset font color

    switch (pil)
    {
        case 1:
        {
            char input[WORD_LENGTH];
            do
            {
                printf("\033[1;33m"); // Change font color to yellow and make it bold
                printf("Masukkan Kata (Kembali ketik 99): ");
                printf("\033[0m"); // Reset font color
                scanf("%s", input);
                if(strcmp("99",input)==0){
                    // break;
                    banner();
                }else{
                    check_word(input);
                }
            } while (1);
            break;
        }
        case 2:{
            char input [200];
            displayHistory();
            do{
            printf("Ketik 99 untuk Kembali kemenu awal: ");
            printf("\033[0m"); // Reset font color
            scanf("%s",input);
            if(strcmp("99",input)==0){
                banner();
            }
            } while (strcmp("99",input)!=1);
            break;
            
           
        }
        case 3:
            printf("TERIMA KASIH SUDAH MENCOBA");
            break;
        default:
            break;
    }
}



void load_words(const char *filename) { // Membuka file
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File Tidak bisa dibuka");
        exit(1);
    }

    char line[WORD_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        strcpy(words[word_count].word, line);
        words[word_count].count = 0;
        word_count++;
    }

    fclose(file);
}

int calculate_distance(const char *word1, const char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int **matrix = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
        matrix[i][0] = i;
    }
    for (int j = 1; j <= len2; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
        }
    }
    int distance = matrix[len1][len2];
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

void auto_correct(const char *word) {
    int min_distance = WORD_LENGTH;
    int min_index = -1;

    for (int i = 0; i < word_count; ++i) {
        int distance = calculate_distance(word, words[i].word);
        if (distance < min_distance) {
            min_distance = distance;
            min_index = i;
        }
    }

    if (min_index != -1) {
        printf("Did you mean:\n");
        int angka = 0;
        for (int i = min_index; i < min_index + 5 && i < word_count; ++i)
        {
            printf("%d. %s\n", angka+=1, words[i].word);
        }
    }
}

int find_word(const char *word) {
    for (int i = 0; i < word_count; ++i) {
        if (strcmp(word, words[i].word) == 0) {
            return i;
        }
    }
    return -1;
}

void check_word(const char *word) {
    int found = find_word(word);
    char hasil[300] = ""; 
    if (found != -1) {
        printf("Kata telah ditemukan : %s\n", words[found].word);
        // pisahkanSukuKata(words[found].word);
        printf("Hasil pengejaan menjadi :");
        pengejaan_kata(words[found].word);
        saveHistory(words[found].word);
        // savingHistori(words[found].word);

        printf("\n");
    } else {
        auto_correct(word);
    }
}

void pengejaan_kata(char *kata) {
    int i;
    for (i = 0; i < strlen(kata); i++) {
        printf("%c", kata[i]);
        if (i != strlen(kata) - 1) {
            printf("-");
        }
    }
}

void saveHistory(char *word) {
    char lines[MAX_LINES][MAX_LENGTH];
    int lineCount = 0;
    int i;

    FILE *file = fopen("dbhistori.txt", "r");

    // Membaca baris yang sudah ada dalam file
    if (file != NULL) {
        while (fgets(lines[lineCount], MAX_LENGTH, file) && lineCount < MAX_LINES) {
            // Menghapus karakter newline dari string
            lines[lineCount][strcspn(lines[lineCount], "\n")] = 0;
            lineCount++;
        }
        fclose(file);
    }

    // Menyimpan string tambahan dari parameter
    if (strlen(word) > 0 && lineCount < MAX_LINES ) {
        strncpy(lines[lineCount], word, MAX_LENGTH - 1);
        lines[lineCount][MAX_LENGTH - 1] = '\0'; // Memastikan string berakhir dengan null terminator
        lineCount++;
    }

    // Menghapus string yang terlama jika jumlah baris sudah mencapai batasan
    if (lineCount == MAX_LINES ) {
        // Menghapus string terlama
        for (i = 0; i < MAX_LINES - 1; i++) {
            strcpy(lines[i], lines[i + 1]);
        }
        lineCount--;
    }

    // Menyimpan string ke dalam file
    file = fopen("dbhistori.txt", "w");
    if (file != NULL) {
        for (i = 0; i < lineCount; i++) {
            fprintf(file, "%s\n", lines[i]);
        }
        fclose(file);
    } else {
        printf("Gagal membuka file untuk penulisan.");
    }

    // Menampilkan hasil

}

void  displayHistory() {
    char line[MAX_LENGTH];
    FILE *file = fopen("dbhistori.txt", "r");

    int count =0;
    if (file != NULL) {
        printf("\033[1;33m"); 
        printf("RIWAYAT PENCARIAN : ");
        printf("\033[0m\n");
        while (fgets(line, MAX_LENGTH, file)) {
            printf("\033[1;33m");
            printf("%d. %s", count+=1,line);
            printf("\033[0m");
        }
        fclose(file);
    } else {
        printf("Gagal membuka file untuk membaca.");
    }
}







int main() {
    load_words("dbbaru.txt");
    banner();
    return 0;
}
