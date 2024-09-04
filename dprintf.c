#include <stdio.h>

void vulnerable_dprintf(const char *format) {
    dprintf(1, format);  // Vulnerable: format string is user-controlled
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    vulnerable_dprintf(input);
    return 0;
}
