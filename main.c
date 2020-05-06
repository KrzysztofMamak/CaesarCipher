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
            printf("%c", tmp);
            int index;
            if ((((int) tmp) >= 65 && ((int) tmp) <= 90) || (((int) tmp) >= 97 && ((int) tmp) <= 122)) {
                for (int i = 0; i < ENG_ALPHABET_SIZE; i++) {
                    if (tmp == ENG_SMALL_LETTERS[i]) {
                        fprintf(resultFile, "%c", ENG_SMALL_LETTERS[i + 2]);
                        break;
                    }
                    if (tmp == ENG_CAPITAL_LETTERS[i]) {
                        fprintf(resultFile, "%c", ENG_CAPITAL_LETTERS[i + 2]);
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

}

int main()
{
    code("source.txt", "result.txt");
    return 0;
}
