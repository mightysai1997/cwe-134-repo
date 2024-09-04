#include <stdio.h>

void vulnerable_printf(const char *user_input) {
    printf(user_input);  // Vulnerable: user_input is used directly as a format string
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    vulnerable_printf(input);
    return 0;
}
