#include <stdio.h>
#include <stdarg.h>

void secure_vsprintf(const char *format, ...) {
    char buffer[256];
    va_list args;
    va_start(args, format);
    vsprintf(buffer, "%s", format);  // Secure: use a fixed format string
    va_end(args);
    printf("%s", buffer);
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    secure_vsprintf("%s", input);  // Secure: user input is treated as data, not a format string
    return 0;
}
