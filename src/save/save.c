#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "save.h"
#define MATRIX1_SIZE 50
#define MATRIX2_SIZE 3

int save_game(const char *filename, int matrix[MATRIX1_SIZE][MATRIX1_SIZE]) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка открытия файла: %s\n", filename);
        return -20;
    }

    for (int i = 0; i < MATRIX1_SIZE; ++i) {
        for (int j = 0; j < MATRIX1_SIZE; ++j) {
            fprintf(file, "%d ", matrix[i][j]);
        }
    }

    fclose(file);
    return 0;
}

int save_settings(const char *filename, int mas[MATRIX2_SIZE]) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка открытия файла: %s\n", filename);
        return -20;
    }

    for (int i = 0; i < MATRIX2_SIZE; ++i) {
            fprintf(file, "%d ", mas[i]);
    }

    fclose(file);
    return 0;
}
