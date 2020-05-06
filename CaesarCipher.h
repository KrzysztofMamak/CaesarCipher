#ifndef CAESARCIPHER_H_
#define CAESARCIPHER_H_

#include <stdio.h>
#include <stdlib.h>

const int PL_ALPHABET_SIZE = 32;
const int ENG_ALPHABET_SIZE = 26;

const char ENG_SMALL_LETTERS[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z' };
const char ENG_CAPITAL_LETTERS[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z' };
const char PL_SMALL_LETTERS[] = { 'a', '�', 'b', 'c', '�', 'd', 'e', '�', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', '�', 'm', 'n', '�', 'o',
        '�', 'p', 'r', 's', '�', 't', 'u', 'w', 'y', 'z', '�', '�' };
const char PL_CAPITAL_LETTERS[] = { 'A', '�', 'B', 'C', '�', 'D', 'E', '�', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', '�', 'M', 'N', '�', 'O',
        '�', 'P', 'R', 'S', '�', 'T', 'U', 'W', 'Y', 'Z', '�', '�' };

void code(char * sourceFileName, char * resultFileName);
void decode(char * sourceFileName, char * resultFileName);

#endif
