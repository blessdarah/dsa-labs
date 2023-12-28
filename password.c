#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool has_required_chars(char password[], int length) {
    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_special = false;
    char special_chars[] = {'!', '@', '#', '$', '%', '&'};

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_upper = true;
        } else if (islower(password[i])) {
            has_lower = true;
        } else if (isdigit(password[i])) {
            has_digit = true;
        } else {
            for (int j = 0; j < sizeof(special_chars); j++) {
                if (password[i] == special_chars[j]) {
                    has_special = true;
                    break;
                }
            }
        }
    }

    return has_upper && has_lower && has_digit && has_special;
}

void check_password_strength(char password[]) {
    int length_requirement = 8;
    int length = strlen(password);

    if (length < length_requirement) {
        printf("Weak password. Password should be at least 8 characters long.\n");
        return;
    }

    if (has_required_chars(password, length)) {
        printf("Strong password.\n");
    } else {
        printf("Weak password. Password should contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
    }
}

int main() {
    char user_password[50]; // Assuming a maximum length of 50 characters for the password

    printf("Enter your password: ");
    scanf("%s", user_password);

    check_password_strength(user_password);

    return 0;
}
