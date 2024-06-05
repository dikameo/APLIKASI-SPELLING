#include <stdio.h>
#include <string.h>

#define ANSI_COLOR_BLUE    "\x1b[34m"

// Function to center align text
void printCentered(const char *text, int width) {
    int len = strlen(text);
    int padding = (width - len) / 2;
    int i;

    for ( i = 0; i < padding; i++) {
        putchar(' ');
    }
    printf("%s\n", text);
}

int main() {

    system("cls");
    int consoleWidth = 80;
    char sentence[] = "\t\t\t Berikut instruksi dari penjelasan masing-masing dalam aplikasi SPIL";

   
printCentered("██╗███╗   ██╗███████╗████████╗██████╗ ██╗   ██╗██╗  ██╗███████╗██╗ ", consoleWidth);
printCentered("██║████╗  ██║██╔════╝╚══██╔══╝██╔══██╗██║   ██║██║ ██╔╝██╔════╝██║", consoleWidth);
printCentered("██║██╔██╗ ██║███████╗   ██║   ██████╔╝██║   ██║█████╔╝ ███████╗██║", consoleWidth);
printCentered("██║██║╚██╗██║╚════██║   ██║   ██╔══██╗██║   ██║██╔═██╗ ╚════██║██║", consoleWidth);
printCentered("██║██║ ╚████║███████║   ██║   ██║  ██║╚██████╔╝██║  ██╗███████║██║", consoleWidth);
printCentered("╚═╝╚═╝  ╚═══╝╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝", consoleWidth);

printf("\n\n");

for (int i = 0; i < strlen(sentence); i++) {
        printf(ANSI_COLOR_BLUE "%c", sentence[i]);
        fflush(stdout);
        usleep(5000); // pause for 50 milliseconds
    }

printf(ANSI_COLOR_BLUE "\n\n\033[1m# CARI KATA #\033[0m\n");

printf("1. Menu untuk melakukan pencarian kata");
printf(" \n2. Klik kolom pencarian dan ketik yang ingin Anda cari kemudian klik icon pencarian untuk memulai pencarian");
printf(" \n3. Klik icon kembali untuk mereset hasil pencarian");

printf(ANSI_COLOR_BLUE "\n\n\033[1m# HISTORI #\033[0m\n");
printf("1. Hasil pencarian yang Anda cari apabila ditemukan");
printf(" \n2. Batas penyimpanan adalah 5 kata terbaru");
                                                                                                            
                                                                                      
    return 0;
}