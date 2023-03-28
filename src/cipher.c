#include <stdio.h>

void read(char line[256]);
void recover(char line[256], char str[256]);

int main() {
    char line[256];
    char str[256];
    int a = 0, c = 0;
    line[0] = '\0';
    while (a != -1) {
        int b = scanf("%d.%d", &a, &c);
        if (b == 1) {
            if (a == 1) {
                scanf("%s", line);
                read(line);
            }
            if (a == 2) {
                if (line[0] != '\0') {
                    rewind(stdin);

                    scanf("%s", str);
                    recover(line, str);
                    read(line);
                }
            } else if (a == 0 || a > 1 || a < -1)
                printf("n/a\n");
        } else {
            printf("n/a\n");
            rewind(stdin);
        }
    }
    return 0;
}

void read(char line[256]) {
    char a[255];
    FILE *file = NULL;
    file = fopen(line, "r");
    if (file == NULL)
        printf("n/a\n");
    else {
        fgets(a, 256, file);
        printf("%s\n", a);
    }
    fclose(file);
}

void recover(char line[256], char str[256]) {
    FILE *file = NULL;
    file = fopen(line, "a+");

    if (file == NULL)
        printf("n/a\n");
    else {
        fprintf(file, "%s\n", str);
    }
    fclose(file);
}