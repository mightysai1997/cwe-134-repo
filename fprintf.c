#include <stdio.h>

void vulnerable_fprintf(const char *user_input) {
    FILE *file = fopen("log.txt", "w");
    fprintf(file, user_input);  // Vulnerable: user_input is used directly as a format string
    fclose(file);
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    vulnerable_fprintf(input);
    return 0;
}
