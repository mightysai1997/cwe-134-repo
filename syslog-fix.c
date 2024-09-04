#include <syslog.h>

void secure_syslog(const char *user_input) {
    syslog(LOG_ERR, "%s", user_input);  // Secure: Always specify a format string
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    secure_syslog(input);
    return 0;
}
