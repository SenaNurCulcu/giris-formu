#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyData(const char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Kopyalanan veri: %s\n", buffer);
}

void leakMemory() {
    char *veri = (char *)malloc(100);
    if (veri == NULL) {
        printf("Bellek ayrılmadı!\n");
        return;
    }
    strcpy(veri, "Bu bir bellek sızıntısı örneğidir.");
    printf("Veri: %s\n", veri);
}

void nullPointerExample() {
    char *ptr = NULL;
    if (rand() % 2 == 0) {
        ptr = "Merhaba!";
    }
    printf("Veri: %s\n", ptr);
}

void formatStringVulnerability(char *userInput) {
    printf(userInput);
}

void infiniteLoop() {
    int i = 0;
    while (i >= 0) {
        i++;
        if (i % 100000000 == 0) {
            printf(".");
            break;
        }
    }
}

void dangerousInput() {
    char isim[20];
    printf("Adınızı girin: ");
    gets(isim);
    printf("Merhaba, %s!\n", isim);
}

int main() {
    char input[100];

    printf("Test verisi girin (en az 11 karakter): ");
    fgets(input, sizeof(input), stdin);

    copyData(input);
    leakMemory();
    nullPointerExample();
    formatStringVulnerability(input);
    infiniteLoop();
    dangerousInput();

    return 0;
}
