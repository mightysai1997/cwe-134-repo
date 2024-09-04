#include <stdio.h>

void vulnerable_snprintf(const char *user_input) {
    char buffer[100];
    snprintf(buffer, sizeof(buffer), user_input);  // Vulnerable: user_input is used directly as a format string
    printf("%s", buffer);
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    vulnerable_snprintf(input);
    return 0;
}
