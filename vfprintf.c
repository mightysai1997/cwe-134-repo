#include <stdio.h>
#include <stdarg.h>

void vulnerable_vfprintf(const char *format, ...) {
    FILE *file = fopen("output.txt", "w");
    va_list args;
    va_start(args, format);
    vfprintf(file, format, args);  // Vulnerable: format string is user-controlled
    va_end(args);
    fclose(file);
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    vulnerable_vfprintf(input);
    return 0;
}
