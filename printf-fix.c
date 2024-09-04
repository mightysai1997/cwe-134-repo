#include <stdio.h>

void secure_printf(const char *user_input) {
    printf("%s", user_input);  // Secure: Always specify a format string
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    secure_printf(input);
    return 0;
}
