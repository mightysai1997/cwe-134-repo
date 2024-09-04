#include <stdio.h>

void secure_snprintf(const char *user_input) {
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "%s", user_input);  // Secure: Always specify a format string
    printf("%s", buffer);
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    secure_snprintf(input);
    return 0;
}
