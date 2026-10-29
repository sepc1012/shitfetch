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

void print_logo(const char *distro){
    FILE *fp = NULL;

    if (strstr(distro, "Arch") !=  NULL){
        fp = fopen("src/logos/ascii/arch.txt","r");

    }else{
        fp= fopen("src/logos/ascii/default.txt","r");
    }
    
    if( fp == NULL){
        printf("    [!] Logo not found");
        return;

    }

    char line[256];
    while (fgets(line, sizeof(line), fp)){
        printf("%s", line);
    } 
    fclose(fp);
}

int main(void) {
    char distro[64];
    get_distro(distro, sizeof(distro));

    printf("\n");
    print_logo(distro);
    printf("OS: %s\n", distro);
    printf("\n");

    return 0;
}