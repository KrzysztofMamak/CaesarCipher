#include "CaesarCipher.h"

void code(char * sourceFileName, char * resultFileName) {
    FILE * sourceFile = fopen(sourceFileName, "r");
    FILE * resultFile = fopen(resultFileName, "w");

    if (sourceFile == NULL || resultFile == NULL) {
        printf("%s", "Cannot open given file.\n");
        return;
    } else {
        char tmp;
        while (fscanf(sourceFile, "%c", &tmp) != EOF) {
            if ((((int) tmp) >= 65 && ((int) tmp) <= 90) || (((int) tmp) >= 97 && ((int) tmp) <= 122)) {
                for (int i = 0; i < ENG_ALPHABET_SIZE; i++) {
                    if (tmp == ENG_SMALL_LETTERS[i]) {
                        fprintf(resultFile, "%c", ENG_SMALL_LETTERS[(i + 2) % ENG_ALPHABET_SIZE]);
                        break;
                    }
                    if (tmp == ENG_CAPITAL_LETTERS[i]) {
                        fprintf(resultFile, "%c", ENG_CAPITAL_LETTERS[(i + 2) % ENG_ALPHABET_SIZE]);
                        break;
                    }
                }
            } else {
                fprintf(resultFile, "%c", tmp);
            }
        }
    }
}

void decode(char * sourceFileName, char * resultFileName) {
    FILE * sourceFile = fopen(sourceFileName, "r");
    FILE * resultFile = fopen(resultFileName, "w");

    if (sourceFile == NULL || resultFile == NULL) {
        printf("%s", "Cannot open given file.\n");
        return;
    } else {
        char tmp;
        while (fscanf(sourceFile, "%c", &tmp) != EOF) {
            if ((((int) tmp) >= 65 && ((int) tmp) <= 90) || (((int) tmp) >= 97 && ((int) tmp) <= 122)) {
                for (int i = 0; i < ENG_ALPHABET_SIZE; i++) {
                    if (tmp == ENG_SMALL_LETTERS[i]) {
                        if (i == 0) {
                            fprintf(resultFile, "%c", ENG_SMALL_LETTERS[ENG_ALPHABET_SIZE - 2]);
                        } else if (i == 1) {
                            fprintf(resultFile, "%c", ENG_SMALL_LETTERS[ENG_ALPHABET_SIZE - 1]);
                        } else {
                        fprintf(resultFile, "%c", ENG_SMALL_LETTERS[abs((i - 2) % ENG_ALPHABET_SIZE)]);
                        }
                        break;
                    }
                    if (tmp == ENG_CAPITAL_LETTERS[i]) {
                        if (i == 0) {
                            fprintf(resultFile, "%c", ENG_CAPITAL_LETTERS[ENG_ALPHABET_SIZE - 2]);
                        } else if (i == 1) {
                            fprintf(resultFile, "%c", ENG_CAPITAL_LETTERS[ENG_ALPHABET_SIZE - 1]);
                        } else {
                            fprintf(resultFile, "%c", ENG_CAPITAL_LETTERS[abs((i - 2) % ENG_ALPHABET_SIZE)]);
                        }
                        break;
                    }
                }
            } else {
                fprintf(resultFile, "%c", tmp);
            }
        }
    }
}

int main()
{
    code("source_code.txt", "result_code.txt");
    decode("source_decode.txt", "result_decode.txt");
    return 0;
}
