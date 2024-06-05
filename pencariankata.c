#include <stdio.h>
#include <string.h>

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
    char sentence[] = "\t\t\tDalam aplikasi ini memiliki sekitar 14.000+ kosa kata yang dapat Anda gunakan untuk melakukan spelling";
      
printCentered("\t\t██████╗ ███████╗███╗   ██╗ ██████╗ █████╗ ██████╗ ██╗ █████╗ ███╗   ██╗    ██╗  ██╗ █████╗ ████████╗ █████╗ ", consoleWidth);
printCentered("\t\t██╔══██╗██╔════╝████╗  ██║██╔════╝██╔══██╗██╔══██╗██║██╔══██╗████╗  ██║    ██║ ██╔╝██╔══██╗╚══██╔══╝██╔══██╗", consoleWidth);
printCentered("\t\t██████╔╝█████╗  ██╔██╗ ██║██║     ███████║██████╔╝██║███████║██╔██╗ ██║    █████╔╝ ███████║   ██║   ███████║ ", consoleWidth);
printCentered("\t\t██╔═══╝ ██╔══╝  ██║╚██╗██║██║     ██╔══██║██╔══██╗██║██╔══██║██║╚██╗██║    ██╔═██╗ ██╔══██║   ██║   ██╔══██║ ", consoleWidth);
printCentered("\t\t██║     ███████╗██║ ╚████║╚██████╗██║  ██║██║  ██║██║██║  ██║██║ ╚████║    ██║  ██╗██║  ██║   ██║   ██║  ██║ ", consoleWidth);
printCentered("\t\t╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝    ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝  ", consoleWidth);                   

printf("\n\n");
        for (int i = 0; i < strlen(sentence); i++) {
        printf("%c", sentence[i]);
        fflush(stdout);
        usleep(5000); // pause for 50 milliseconds                                      
    }

    return 0;
}