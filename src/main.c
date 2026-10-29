#include <stdio.h>
#include <string.h>

void get_distro(char *dest, size_t size) {
    FILE *fp = fopen("/etc/os-release", "r");
    char line[256];

    snprintf(dest, size, "linux");
    if (fp == NULL) return;

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "PRETTY_NAME=", 12) == 0) {
            char *val = line + 12;

            if (val[0] == '"') val++;
            val[strcspn(val, "\r\n\"")] = '\0';

            strncpy(dest, val, size - 1);
            dest[size - 1] = '\0';
            break;
        }
    }
    fclose(fp);
}

int main(void) {
    char distro[64];
    get_distro(distro, sizeof(distro));

    printf("\n");
    printf("       ___          OS: %s\n", distro);
    printf("      / | \\         \n");
    printf("     |  |  |         \n");
    printf("     |  |  |         \n");
    printf("     |  |  |         \n");
    printf("   __|  |  |__       \n");
    printf(" /   \\     /   \\     \n");
    printf("|     |   |     |    \n");
    printf(" \\___/\\___/\\___/     \n");
    printf("\n");

    return 0;
}