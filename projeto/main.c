#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

#define LED_PIN 2  
#define RELAY_PIN 4  

void process_command(char *command) {
    if (strcmp(command, "LIGAR LED") == 0) {
        gpio_put(LED_PIN, 1);
        printf("LED ligado!\n");
    } else if (strcmp(command, "DESLIGAR LED") == 0) {
        gpio_put(LED_PIN, 0);
        printf("LED desligado!\n");
    } else if (strcmp(command, "LIGAR RELE") == 0) {
        gpio_put(RELAY_PIN, 1);
        printf("Relé ativado!\n");
    } else if (strcmp(command, "DESLIGAR RELE") == 0) {
        gpio_put(RELAY_PIN, 0);
        printf("Relé desativado!\n");
    } else {
        printf("Comando não reconhecido.\n");
    }
}

int main() {
    stdio_init_all();  
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_init(RELAY_PIN);
    gpio_set_dir(RELAY_PIN, GPIO_OUT);

    char command[50];

    while (true) {
        if (scanf("%49s", command) == 1) {
            process_command(command);
        }
    }
}
