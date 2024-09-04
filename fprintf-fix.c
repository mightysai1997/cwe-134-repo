#include <stdio.h>

void secure_fprintf(const char *user_input) {
    FILE *file = fopen("log.txt", "w");
    fprintf(file, "%s", user_input);  // Secure: Always specify a format string
    fclose(file);
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    secure_fprintf(input);
    return 0;
}

