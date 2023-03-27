#include <stdio.h>

void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    char line[256];
    int a = 0, c = 0;
    FILE *file;
    while (a != -1) {
        int b = scanf("%d.%d", &a, &c);
        if (b == 1) {
            if (a == 1) {
                scanf("%255s", line);
                file = fopen(line, "r");
                if (file == NULL)
                    printf("n/a\n");
                else {
                    fgets(line, 256, file);
                    printf("%s\n", line);
                    fclose(file);
                }
            } else if (a == 0 || a > 1 || a < -1)
                printf("n/a\n");
        } else {
            printf("n/a\n");
            rewind(stdin);
        }
    }
}
