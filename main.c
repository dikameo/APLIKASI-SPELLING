#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include stdbool for bool type
#include <string.h>

#define MAX_WORDS 130000 // Banyaknya baris dalam txt
#define WORD_LENGTH 50 // Panjang kata

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int word_count = 0;

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
    int max_len = len1 > len2 ? len1 : len2;
    int distance = 0;
    for (int i = 0; i < max_len; i++) {
        if (i < len1 && i < len2 && word1[i] != word2[i])
            distance++;
    }
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
        pisahkanSukuKata(words[found].word);
    } else {
        auto_correct(word);
    }
}



void banner()
{
    system("cls");
    int pil;

    printf("\033[1;36m"); // Change font color to cyan and make it bold
    printf("\t\t\t\t==============================\n"); 
    printf("\t\t\t\t|| SPELLING CHECKER ||\n"); 
    printf("\t\t\t\t|| BAHASA INDONESIA ||\n"); 
    printf("\t\t\t\t==============================\n");
    printf(" Masukkan Pilihan menu yang ada ingin cari :\n");
    printf("1. Cek Ejaan \n"); 
    printf("2. Cek Kesalahan pada kalimat \n"); 
    printf("3. Exit \n"); 
    printf("Pilihan Anda (1/2/3) : ");
    scanf("%d", &pil);
    printf("\033[0m"); // Reset font color

    switch (pil)
    {
        case 1:
        {
            char input[WORD_LENGTH];
            char pil[50];
            while (1)
            {
                printf("\033[1;33m"); // Change font color to yellow and make it bold
                printf("Enter a word: ");
                printf("\033[0m"); // Reset font color
                scanf("%s", input);
                check_word(input);
                printf("Ketik (T) untuk Mengakhiri atau Ketik (Y) untuk melanjutkan: ");
                scanf("%s", pil);
                if(strcmp("T",pil) == 0) {
                    break;
                }
            }
            break;
        }

        default:
            break;
    }
}



bool isVokal(char c) {
    char vokal[] = "aiueoAIUEO";
    for (int i = 0; i < strlen(vokal); i++) {
        if (c == vokal[i]) {
            return true;
        }
    }
    return false;
}

// Fungsi untuk memeriksa apakah karakter adalah konsonan
bool isKonsonan(char c) {
    if ((c >= 'a' && c <= 'z' && !isVokal(c)) || (c >= 'A' && c <= 'Z' && !isVokal(c))) {
        return true;
    }
    return false;
}

// Fungsi untuk memisahkan kata menjadi suku kata
void pisahkanSukuKata(char *kata) {
    int len = strlen(kata);
    for (int i = 0; i < len; i++) {
        printf("%c", kata[i]);
        
        // Pisahkan setelah vokal diikuti konsonan ganda atau akhir string
        if (isVokal(kata[i]) && i + 1 < len && isKonsonan(kata[i + 1])) {
            // Jika berikutnya ada dua konsonan berturut-turut
            if (i + 2 < len && isKonsonan(kata[i + 2])) {
                printf("-");
                continue;
            }
            // Jika berikutnya ada konsonan diikuti oleh vokal
            else if (i + 2 < len && isVokal(kata[i + 2])) {
                printf("-");
            }
        }
    }
    printf("\n");
}





int main() {
    load_words("dbbaru.txt");
    banner();
    return 0;
}