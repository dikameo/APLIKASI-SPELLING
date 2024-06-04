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
    int consoleWidth = 80;

    // ANSI escape code for blue text
    const char *blue = "\033[34m";
    // ANSI escape code to reset text color
    const char *reset = "\033[0m";

    printf("%s", blue);
    printCentered("                                                      ", consoleWidth);
    printCentered("           ███╗   ███╗███████╗███╗   ██╗██╗   ██╗         ", consoleWidth);
    printCentered("           ████╗ ████║██╔════╝████╗  ██║██║   ██║        ", consoleWidth);
    printCentered("    ██     ██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║     ██  ", consoleWidth);
    printCentered("           ██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║        ", consoleWidth);
    printCentered("           ██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝        ", consoleWidth);
    printCentered("           ╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝          ", consoleWidth);
    printf("%s", reset);
    
    return 0;
}
