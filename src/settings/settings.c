#include <stdbool.h>
#include<stdlib.h>
#include <stdio.h>
#include "settings.h"
int set_settings(const char *filename, int mas[MATRIX2_SIZE]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка открытия файла: %s\n", filename);
        return -20;
    }

    for (int i = 0; i < MATRIX2_SIZE; ++i) {
       
            if (fscanf(file, "%d", &mas[i]) != 1) {
                printf("Ошибка чтения из файла\n");
                fclose(file);
                return -20;
            }
    }

    fclose(file);
    return 0;
}

int load_game(const char *filename, int matrix[MATRIX1_SIZE][MATRIX1_SIZE]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка открытия файла: %s\n", filename);
        return -20;
    }

    for (int i = 0; i < MATRIX1_SIZE; ++i) {
        for (int j = 0; j < MATRIX1_SIZE; ++j) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                printf("Ошибка чтения из файла\n");
                fclose(file);
                return -20;
            }
        }
    }

    fclose(file);
    return 0;
}
