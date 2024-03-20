#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 15000 // banyaknya baris dalam txt
#define WORD_LENGTH 50 // banyak kata

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

int find_word(const char *word) {
    for (int i = 0; i < word_count; ++i) {
        if (strcmp(word, words[i].word) == 0) {
            return i;
        }
    }
    return -1;
}

void auto_correct(const char *word) {
    int min_distance = WORD_LENGTH;
    int min_index = -1;

    for (int i = 0; i < word_count; ++i) {
        int distance = 0;
        for (int j = 0; j < WORD_LENGTH && word[j] != '\0' && words[i].word[j] != '\0'; ++j) {
            if(word[j] != words[i].word[j]) {
                distance++;
            }
        }

        if (distance < min_distance) {
            min_distance = distance;
            min_index = i;
        }
    }

    if (min_index != -1) {
        printf("Did you mean:\n");
        int angka = 0;
        for (int i = 0; i < 5 && min_index + i < word_count; ++i)
        {
            printf("%d. %s\n", angka+=1, words[min_index+i].word);
        }
    }
}

void check_word(const char *word) {
    int found = find_word(word);
    if (found != -1) {
        printf("Correct word: %s\n", words[found].word);
    } else {
        auto_correct(word);
    }
}

void banner()
{
    system("cls");
    int pil;
    printf("\t\t\t\t==============================\n");
    printf("\t\t\t\t||      SPELLING CHECKER    ||\n");
    printf("\t\t\t\t||      BAHASA INDONESIA    ||\n");
    printf("\t\t\t\t==============================\n");
    printf(" Masukkan Pilihan menu yang ada ingin cari :\n");
    printf("1. Cek Ejaan \n");
    printf("2. Cek Kesalahan pada kalimat \n");
    printf("3. Exit \n");
    printf("Pilihan Anda (1/2/3) : ");
    scanf("%d", &pil);
    switch (pil)
    {
        case 1:
        {
            char input[WORD_LENGTH];
            while (1)
            {
                printf("Enter a word: ");
                scanf("%s", input);
                check_word(input);
                printf("\nPress Enter to check another word or type 'exit' toquit: ");
                char exit_check[WORD_LENGTH];
                scanf("%s", exit_check);
                if(strcmp(exit_check, "exit") == 0) {
                    break;
                }
            }
            break;
        }

        default:
            break;
    }
}

int main() {
    load_words("dbbaru.txt");
    banner();
    return 0;
}