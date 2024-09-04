#include <stdio.h>

void secure_dprintf(const char *format) {
    dprintf(1, "%s", format);  // Secure: use a fixed format string
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    secure_dprintf(input);  // Secure: user input is treated as data, not a format string
    return 0;
}
