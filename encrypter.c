#include "encrypter.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

float letter_frequency_table[ALPHABET_LENGTH] = {
        .08167, .01492, .02782, .04253,
        .12702, .02228, .02015, .06094,
        .06966, .00153, .00772, .04025,
        .02406, .06749, .07507, .01929,
        .00095, .05987, .06327, .09056,
        .02758, .00978, .02360, .00150,
        .01974, .00074
};

/**
 * convert letter to uppercase and get the offset relative to 'A'
 */
int __tonumber(char c) {
    return toupper(c) - 'A';
}

void __encrypt_by_rotation_cipher(char *source, char *dest, key_type key, unsigned int len) {
    int i;
    for (i = 0; i < len; ++i) {
        if (isalpha(*source)) {
            int number = __tonumber(*source++);
            number = (number + key + ROTATION_CIPHER_MOD) %
                     ROTATION_CIPHER_MOD;// plus ROTATION_CIPHER_MOD used to avoid the negative result
            *dest++ = (char) ('A' + number);
        } else
            *dest++ = *source++;
    }
    *dest = '\0'; // end of text
}

void __decrypt_by_rotation_cipher(char *source, char *dest, key_type key, unsigned int len) {
    int i;
    for (i = 0; i < len; ++i) {
        if (isalpha(*source)) {
            int number = __tonumber(*source++);
            number = (number - key + ROTATION_CIPHER_MOD) %
                     ROTATION_CIPHER_MOD;// plus ROTATION_CIPHER_MOD used to avoid the negative result
            *dest++ = (char) ('A' + number);
        } else
            *dest++ = *source++;
    }
    *dest = '\0'; // end of text
}

key_type __calculate_rotation_cipher_key(char *source, unsigned int len) {
    int i, j;
    key_type key = 0;
    float eps = 1.0;

    /* calculate the frequency table of cipher text */
    float frequency[ROTATION_CIPHER_TYPES] = {0};

    __calculate_letter_frequency(source, frequency, len);

    /* get the key according to expectation */
    float diff = 0;
    for (i = 0; i < ROTATION_CIPHER_TYPES; i++) {
        float sum = 0;
        for (j = 0; j < ALPHABET_LENGTH; j++) {
            int number = j;
            number = (number + i + ROTATION_CIPHER_MOD) % ROTATION_CIPHER_MOD;
            sum += frequency[number] * letter_frequency_table[j];
        }

        diff = (float) fabs(sum - ROTATION_CIPHER_KEY_TARGET);
        if (diff < eps) {
            // if the current key is closer to the original text than other,we should update these two arguments
            eps = diff;
            key = (key_type) i;
        }
    }
    return key;
}

void __decrypt_by_rotation_cipher_without_key(char *source, char *dest, unsigned int len) {
    key_type key = __calculate_rotation_cipher_key(source, len);
    __decrypt_by_rotation_cipher(source, dest, key, len);
}

void __encrypt_by_substitution_cipher(char *source, char *dest, char *key, unsigned int len) {
    int i;

    for (i = 0; i < len; i++) {
        char c = *source++;
        if (isalpha(c)) {
            if (islower(c))
                c = (char) toupper(c); // convert to uppercase
            c = key[__tonumber(c)];
        }
        *dest++ = c;
    }
}

void __decrypt_by_substitution_cipher(char *source, char *dest, char *key, unsigned int len) {
    int i;

    char *unmap = malloc(sizeof(char) * ALPHABET_LENGTH);
    for (i = 0; i < ALPHABET_LENGTH; i++)
        unmap[__tonumber(*key++)] = (char) ('A' + i);
    for (i = 0; i < len; i++) {
        char c = *source++;
        if (islower(c))
            c = (char) toupper(c);
        *dest++ = unmap[c];
    }
}

void __decrypt_by_substitution_cipher_without_key(char *source, char *dest, unsigned int len) {
    float frequency[26] = {0};
    __calculate_letter_frequency(source, frequency, len);

    int i, j;
    char table[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    char tmp[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char key[26];

    for (i = 0; i < ALPHABET_LENGTH; i++) {
        short flag = 0;
        for (j = 0; j < ALPHABET_LENGTH; j++)
            if (frequency[j + 1] > frequency[j]) {
                char c = tmp[j];
                tmp[j] = tmp[j + 1];
                tmp[j + 1] = c;

                float f = frequency[j];
                frequency[j] = frequency[j + 1];
                frequency[j + 1] = f;
                flag = 1;
            }
        if (flag == 0)
            break;
    }

    for (i = 0; i < 26; i++)
        *(key + (tmp[i] - 'A')) = table[i];

    for (i = 0; i < len; i++)
        if (isalpha(*source))
            *dest++ = key[__tonumber(*source++)];
        else
            *dest++ = *source++;
}

void __calculate_letter_frequency(char *source, float *dest, unsigned int len) {
    int i;

    for (i = 0; i < ALPHABET_LENGTH; i++)
        *(dest + i) = 0;

    for (i = 0; i < len; i++) {
        if (isalpha(*(source + i))) {
            int number = __tonumber(*(source + i));
            ++dest[number];
        }
    }

    for (i = 0; i < ALPHABET_LENGTH; i++)
        dest[i] /= len;
}


