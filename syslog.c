#include <syslog.h>

void vulnerable_syslog(const char *user_input) {
    syslog(LOG_ERR, user_input);  // Vulnerable: user_input is used directly as a format string
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);  // Assume input is controlled by the attacker
    vulnerable_syslog(input);
    return 0;
}
