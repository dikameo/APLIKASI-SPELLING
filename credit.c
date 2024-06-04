#include <stdio.h>
#include <string.h>

void printCentered(const char *text, int width) {
    int len = strlen(text);
    int padding = (width - len) / 2;
    int i;
    for (i = 0; i < padding; i++) {
        putchar(' ');
    }
    printf("%s\n", text);
}

int main() {
    int consoleWidth = 30;

    // ANSI escape code for blue text
    const char *blue = "\033[34m";
    // ANSI escape code to reset text color
    const char *reset = "\033[0m";

    printf("%s", blue);
    printCentered("                                                         ", consoleWidth);
    printCentered("           ██████ ██████  ███████ ██████  ██ ████████        ", consoleWidth);
    printCentered("  ██      ██      ██   ██ ██      ██   ██ ██    ██        ██ ", consoleWidth);
    printCentered("██  ██    ██      ██████  █████   ██   ██ ██    ██      ██  ██ ", consoleWidth);
    printCentered("  ██      ██      ██   ██ ██      ██   ██ ██    ██        ██ ", consoleWidth);
    printCentered("           ██████ ██   ██ ███████ ██████  ██    ██           ", consoleWidth);
    printCentered("                                                   ", consoleWidth);
    printCentered("               Berikut para pembuat aplikasi SPIL :                                        \n", consoleWidth);
    printCentered("   Muhammad Azmi Fathani                Herdiana Dwi Maharani                   ", consoleWidth);
    printCentered("      202310370311116                      202310370311129                                                  ", consoleWidth);
    printCentered("                                                                              ", consoleWidth);
    printCentered("                          Wahyu Andika         ", consoleWidth);
    printCentered("                         202310370311075         \n", consoleWidth);
    printCentered("            < Terima kasih telah mencoba program kami >                                             ", consoleWidth);
    printf("%s", reset);

    return 0;
}
