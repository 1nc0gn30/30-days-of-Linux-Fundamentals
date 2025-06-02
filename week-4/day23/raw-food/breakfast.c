#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void review_variables() {
    printf("\n📌 Variables and Echo:\n");
    printf("----------------------\n");
    printf("Example: name=\"Neal\"\n");
    printf("         echo \"Welcome, $name!\"\n");
    printf("\nTry creating a variable and echoing it!\n");
}

void review_loops() {
    printf("\n🔁 Loops in Bash:\n");
    printf("----------------------\n");
    printf("For Loop: for i in {1..5}; do echo $i; done\n");
    printf("While Loop: while [ $i -le 5 ]; do ((i++)); done\n");
}

void review_conditionals() {
    printf("\n🔀 Conditionals:\n");
    printf("----------------------\n");
    printf("if [ $num -gt 5 ]; then\n  echo \"Greater\"\nelse\n  echo \"Smaller\"\nfi\n");
}

void review_input_output() {
    printf("\n🧾 Input and Output:\n");
    printf("----------------------\n");
    printf("read -p \"Enter your name: \" name\n");
    printf("echo \"Welcome $name\"\n");
    printf("Redirect: echo \"Hello\" >> file.txt\n");
}

void show_menu() {
    printf("\n========================================\n");
    printf(" Day 23: Breakfast - Scripting Refresher\n");
    printf("========================================\n");
    printf("1. Variables and Echo\n");
    printf("2. Loops\n");
    printf("3. Conditionals\n");
    printf("4. Input/Output\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                review_variables();
                break;
            case 2:
                review_loops();
                break;
            case 3:
                review_conditionals();
                break;
            case 4:
                review_input_output();
                break;
            case 5:
                printf("\nExiting... Start scripting something cool!\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}
