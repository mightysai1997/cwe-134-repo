#include <stdio.h>
#include <stdarg.h>

void secure_vfprintf(const char *format, ...) {
    FILE *file = fopen("output.txt", "w");
    va_list args;
    va_start(args, format);
    vfprintf(file, "%s", format);  // Secure: use a fixed format string
    va_end(args);
    fclose(file);
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    secure_vfprintf("%s", input);  // Secure: user input is treated as data, not a format string
    return 0;
}
