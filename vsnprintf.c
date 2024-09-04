#include <stdio.h>
#include <stdarg.h>

void vulnerable_vsnprintf(const char *format, ...) {
    char buffer[256];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);  // Vulnerable: format string is user-controlled
    va_end(args);
    printf("%s", buffer);
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    vulnerable_vsnprintf(input);
    return 0;
}
