#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include stdbool for bool type
#include <string.h>
#include <math.h>
#include <Windows.h>
#define ANSI_COLOR_BLUE    "\x1b[34m"

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

void pencarianKata();
void pencarianHistori();
void loadingAwal();
void pilihan();
void bannerHistori();
void menuKredit();



typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int word_count = 0;

void printCentered(const char *text, int width) {
    int len = strlen(text);
    int padding = (width - len) / 2;
    int i;

    for ( i = 0; i < padding; i++) {
        putchar(' ');
    }
    printf("%s\n", text);
}

void pencarianBanner(){
        system("cls");
    int consoleWidth = 80; 
    char sentence[] = "\tDalam aplikasi ini memiliki sekitar 120.000+ kosa kata yang dapat Anda gunakan untuk melakukan spelling";
   
   printf("\t██████╗ ███████╗███╗   ██╗ ██████╗ █████╗ ██████╗ ██╗ █████╗ ███╗   ██╗    ██╗  ██╗ █████╗ ████████╗ █████╗\n");
   printf("\t██╔══██╗██╔════╝████╗  ██║██╔════╝██╔══██╗██╔══██╗██║██╔══██╗████╗  ██║    ██║ ██╔╝██╔══██╗╚══██╔══╝██╔══██╗\n");
   printf("\t██████╔╝█████╗  ██╔██╗ ██║██║     ███████║██████╔╝██║███████║██╔██╗ ██║    █████╔╝ ███████║   ██║   ███████║\n");
   printf("\t██╔═══╝ ██╔══╝  ██║╚██╗██║██║     ██╔══██║██╔══██╗██║██╔══██║██║╚██╗██║    ██╔═██╗ ██╔══██║   ██║   ██╔══██║\n");
   printf("\t██║     ███████╗██║ ╚████║╚██████╗██║  ██║██║  ██║██║██║  ██║██║ ╚████║    ██║  ██╗██║  ██║   ██║   ██║  ██║ \n");
   printf("\t╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝    ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ \n");
    printf("\n\n");
        for (int i = 0; i < strlen(sentence); i++) {
        printf("%c", sentence[i]);
        fflush(stdout);
        Sleep(50); // pause for 50 milliseconds                                      
    }
}

void intruksi(){
    char input[WORD_LENGTH];

        system("cls");
    int consoleWidth = 80;
    char sentence[] = "\t\t\t Berikut instruksi dari penjelasan masing-masing dalam aplikasi SPIL";

   
   printf("\t\t\t██╗███╗   ██╗███████╗████████╗██████╗ ██╗   ██╗██╗  ██╗███████╗██╗\n");
   printf("\t\t\t██║████╗  ██║██╔════╝╚══██╔══╝██╔══██╗██║   ██║██║ ██╔╝██╔════╝██║\n");
   printf("\t\t\t██║██╔██╗ ██║███████╗   ██║   ██████╔╝██║   ██║█████╔╝ ███████╗██║\n");
   printf("\t\t\t██║██║╚██╗██║╚════██║   ██║   ██╔══██╗██║   ██║██╔═██╗ ╚════██║██║\n");
   printf("\t\t\t██║██║ ╚████║███████║   ██║   ██║  ██║╚██████╔╝██║  ██╗███████║██║\n");
   printf("\t\t\t╚═╝╚═╝  ╚═══╝╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝\n");

printf("\n\n");

for (int i = 0; i < strlen(sentence); i++) {
        printf(ANSI_COLOR_BLUE "%c", sentence[i]);
        fflush(stdout);
        Sleep(50); // pause for 50 milliseconds
    }

printf(ANSI_COLOR_BLUE "\n\n\033[1m# CARI KATA #\033[0m\n");

printf("1. Menu untuk melakukan pencarian kata");
printf("\n2. Klik kolom pencarian dan ketik yang ingin Anda cari kemudian klik icon pencarian untuk memulai pencarian");
printf("\n3. Klik icon kembali untuk mereset hasil pencarian");

printf(ANSI_COLOR_BLUE "\n\n\033[1m# HISTORI #\033[0m\n");
printf("1. Hasil pencarian yang Anda cari apabila ditemukan");
printf("\n2. Batas penyimpanan adalah 5 kata terbaru\n");
printf("=====================================================================================================\n"); 
    do{

            printf("KETIK 99 UNTUK KEMBALI KEMENU AWAL : ");
            printf("\033[0m"); // Reset font color
            scanf("%s",input);
            if(strcmp("99",input)==0){
                pilihan();
            }
    } while (strcmp("99",input)!=1);
                                                          
}

void banner()
{
    int pil;
    char opsi[200];
    printf("\t\t\t\t\t* MASUKKAN PILIHAN ANDA [1/2/3/4/5] : ");
    scanf("%d", &pil);

    switch (pil)
    {
        case 1:
            pencarianKata();
            break;
        case 2:
            pencarianHistori();
            break;
        case 3:
            intruksi();
            break;
        case 4:
            menuKredit();
            break;
        case 5:
            do {
                printf("\t\t\t\t\tAPAKAH KAMU YAKIN INGIN KELUAR (Y/T) : ");
                scanf(" %s", opsi);  // No & needed for a string (array) variable

                if (strcmp(opsi, "Y") == 0) {
                    printf("\t\t\t\t\tTERIMA KASIH SUDAH MEMAKAI APLIASKI INI\n");
                } else if (strcmp(opsi, "T") == 0) {
                    pilihan();
                }
            } while (strcmp(opsi, "Y") != 0 && strcmp(opsi, "T") != 0);
        default:
            break;
    }
}

void pilihan(){
    system("cls");
    printf("\e[43m"); 
    printf("\t\t\t\t===========================================================\n\n"); 
    printf("\033[0m");
    printf("\t\t\t\t\t\t███████╗ ██████╗  ██╗ ██╗       \n");
    printf("\t\t\t\t\t\t██╔════╝ ██╔══██╗ ██║ ██║       \n");
    printf("\t\t\t\t\t\t███████╗ ██████╔╝ ██║ ██║       \n");
    printf("\t\t\t\t\t\t╚════██║ ██╔═══╝  ██║ ██║       \n");
    printf("\t\t\t\t\t\t███████║ ██║      ██║ ███████╗  \n");
    printf("\t\t\t\t\t\t╚══════╝ ╚═╝      ╚═╝ ╚══════╝  \n");
    printf("\e[1;33m");
    printf("\t\t\t\t\t\tSpelling Indonesian Languange  \n\n");
    printf("\e[43m"); 
    printf("\t\t\t\t===========================================================\n"); 
    printf("\t\t\t\t         Masukkan Pilihan menu yang ada ingin cari         \n");
    printf("\t\t\t\t===========================================================\e[0m\n\n");
    printf("\t\t\t\t\e[43m[]\033[0m  \t{1} CEK EJAAN DARI SEBUAH KATA \t\t\t \e[43m[]\033[0m\n");
    printf("\t\t\t\t\e[43m[]\033[0m  \t{2} CEK HISTORI PENCARIAN\t\t\t \e[43m[]\033[0m  \n");
    printf("\t\t\t\t\e[43m[]\033[0m  \t{3} INTRUKSI PENGGUNAAN APLIKASI SPIL\t\t \e[43m[]\033[0m  \n");
    printf("\t\t\t\t\e[43m[]\033[0m  \t{4} KREDIT PEMBUAT\t\t\t\t \e[43m[]\033[0m  \n");
    printf("\t\t\t\t\e[43m[]\033[0m  \t{5} KELUAR\t\t\t\t\t \e[43m[]\033[0m  \n\n");
    printf("\e[43m"); 
    printf("\t\t\t\t===========================================================\n\n"); 
    printf("\e[0m");
    banner();
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

int is_prefix(const char *prefix, const char *word) {
    while (*prefix && *word) {
        if (*prefix != *word) {
            return 0;
        }
        prefix++;
        word++;
    }
    return *prefix == '\0';
}

void auto_correct(const char *word) {
    printf("\t\t\t\t\tKata yang kami rekomendasikan :\n");
    int count = 0;
    for (int i = 0; i < word_count; ++i) {
        if (is_prefix(word, words[i].word)) {
            printf("\t\t\t\t\t%d. %s\n", ++count, words[i].word);
            if (count >= 5) break; // Limit to top 5 suggestions
        }
    }

    if (count == 0) {
        printf("\t\t\t\t\tKata Tidak ditemukan.\n");
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
        printf("\t\t\t\t\tKATA YANG TELAH DITEMUKAN : %s\n", words[found].word);
        // pisahkanSukuKata(words[found].word);
        printf("\t\t\t\t\tHASIL PENGEJAAN MENJADI :");
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
    system("cls");
    bannerHistori();

    int count =0;
    if (file != NULL) {
        printf("\033[1;33m"); 
        printf("\t\t\t\t\t\t\tRIWAYAT PENCARIAN : ");
        printf("\033[0m\n");
        while (fgets(line, MAX_LENGTH, file)) {
            printf("\033[1;33m");
            printf("\t\t\t\t\t\t\t %d. %s", count+=1,line);
            printf("\033[0m");
        }
        fclose(file);
    } else {
        printf("Gagal membuka file untuk membaca.");
    }
    printf("\e[43m"); 
    printf("\n\t\t\t\t===================================================================\n\n"); 
    printf("\033[0m");
}

void pencarianKata(){
            pencarianBanner();
            do{
             char input[WORD_LENGTH];
                printf("\n\t\t══════════════════════════════════════════════════════════════════════════════════════════\n"); // Change font color to yellow and make it bold
                printf("\033[1;33m"); 
                printf("\n\t\t\tMASUKKAN KATA YANG ANDA CARI (KETIK 99 JIKA INGIN KEMBALI) : ");
                printf("\033[0m"); 
                scanf("%s", input);
                if(strcmp("99",input)==0){
                    pilihan();
                }else{
                    check_word(input);
                }
            } while (1);
            pencarianKata();
}
void pencarianHistori(){
    char input[WORD_LENGTH];
    bannerHistori();
    displayHistory();
    do{
            printf("\t\t\t\t\t\tKETIK 99 UNTUK KEMBALI KEMENU AWAL : ");
            printf("\033[0m"); // Reset font color
            scanf("%s",input);
            if(strcmp("99",input)==0){
                pilihan();
            }
    } while (strcmp("99",input)!=1);
}

void loadingAwal(){
    system("cls");
    printf("\t\t\t\t\t\t███████╗██████╗ ██╗██╗       \n");
    printf("\t\t\t\t\t\t██╔════╝██╔══██╗██║██║       \n");
    printf("\t\t\t\t\t\t███████╗██████╔╝██║██║       \n");
    printf("\t\t\t\t\t\t╚════██║██╔═══╝ ██║██║       \n");
    printf("\t\t\t\t\t\t███████║██║     ██║███████╗  \n");
    printf("\t\t\t\t\t\t╚══════╝╚═╝     ╚═╝╚══════╝  \n");
    printf("\t\t\t\t\t       Spelling Indonesian Languange\n\n\n");
    for (int i = 0; i <= 100; i++) {
        Sleep(10);
        printf("\r\t\t\t\t      [");
        for (int j = 0; j <= i; j++) {
            if (j % 5 == 0)
            {
             printf("█║");
            }
            
        }
        printf("] %d%%", i);
    }
    printf("\n");
    Sleep(1000);
    pilihan();
}

void bannerHistori(){
    // printf("                                                            \n");
    printf("\e[43m"); 
    printf("\t\t\t\t===================================================================\n\n"); 
    printf("\033[0m");
    printf("\t\t\t\t          ██╗  ██╗██╗███████╗████████╗ ██████╗ ██████╗ ██╗       \n");
    printf("\t\t\t\t   ██     ██║  ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗██║     ██  \n");
    printf("\t\t\t\t ██  ██   ███████║██║███████╗   ██║   ██║   ██║██████╔╝██║   ██  ██\n");
    printf("\t\t\t\t   ██     ██╔══██║██║╚════██║   ██║   ██║   ██║██╔══██╗██║     ██ \n");
    printf("\t\t\t\t          ██║  ██║██║███████║   ██║   ╚██████╔╝██║  ██║██║        \n");
    printf("\t\t\t\t          ╚═╝  ╚═╝╚═╝╚══════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝       \n");
    printf("\t\t\t\t                                                                  \n");
    printf("\e[43m"); 
    printf("\t\t\t\t===================================================================\n\n"); 
    printf("\033[0m");
}

void menuKredit(){
    char input[200];
    system("cls");
    printf("\t\t\t\t\t                                                         \n");
    printf("\t\t\t\t\t           ██████ ██████  ███████ ██████  ██ ████████        \n");
    printf("\t\t\t\t\t  ██      ██      ██   ██ ██      ██   ██ ██    ██        ██ \n");
    printf("\t\t\t\t\t██  ██    ██      ██████  █████   ██   ██ ██    ██      ██  ██ \n");
    printf("\t\t\t\t\t  ██      ██      ██   ██ ██      ██   ██ ██    ██        ██ \n");
    printf("\t\t\t\t\t           ██████ ██   ██ ███████ ██████  ██    ██           \n\n");
    printf("\t\t\t\t\t               Berikut para pembuat aplikasi SPIL :                                        \n");
    printf("\t\t\t\t\t   Muhammad Azmi Fathani                Herdiana Dwi Maharani                   \n");
    printf("\t\t\t\t\t      202310370311116                      202310370311129                                                  \n");
    printf("\t\t\t\t\t                                                                              \n");
    printf("\t\t\t\t\t                          Wahyu Andika         \n");
    printf("\t\t\t\t\t                         202310370311075         \n");
    printf("\t\t\t\t\t            < Terima kasih telah mencoba program kami >                                             \n");
        do{

            printf("\t\t\t\t\tKETIK 99 UNTUK KEMBALI KEMENU AWAL : ");
            printf("\033[0m"); // Reset font color
            scanf("%s",input);
            if(strcmp("99",input)==0){
                pilihan();
            }
    } while (strcmp("99",input)!=1);
                                        
}
int main() {
    load_words("db.txt");
    loadingAwal();
    return 0;
}
