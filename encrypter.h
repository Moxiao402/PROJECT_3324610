#ifndef SIMPLEENCRYTER_ENCRYPTER_H
#define SIMPLEENCRYTER_ENCRYPTER_H

typedef short key_t;

#define ROTATION_CIPHER_MOD 26
#define ROTATION_CIPHER_TYPES 26
#define ALPHABET_LENGTH 26
#define ROTATION_CIPHER_KEY_TARGET 0.065497

/**
 * The table of frequency of english letter.
 * From https://en.wikipedia.org/wiki/Letter_frequency
 */
extern float letter_frequency_table[ALPHABET_LENGTH];

/**
 * This function used to encrypt text by rotation cipher.
 * @param source the pointer of message
 * @param dest the pointer to save text after encrypt
 * @param key the key of rotation cipher,a integer from 0 to 25(included)
 * @param len the length of message
 */
extern void __encrypt_by_rotation_cipher(char *source, char *dest, key_t key, unsigned int len);

/**
 * This function used to decrypt text by rotation cipher with the key.
 * @param source the pointer of cipher text
 * @param dest the pointer to save text after decrypt
 * @param key the key of rotation cipher,a integer from 0 to 26(included)
 * @param len the length of cipher text
 */
extern void __decrypt_by_rotation_cipher(char *source, char *dest, key_t key, unsigned int len);

/**
 * The function used to calculate the key of specified cipher text encrypted by rotation cipher.
 *
 * At beginning,we should calculate the frequency of every single letter of cipher text,save as float array frequency.
 * Then,we count the expectation of frequency[i] * letter_frequency_table[i].
 *
 * @param source the pointer of cipher text
 * @param len the length of cipher text
 * @return the key of this cipher text
 */
extern key_t __calculate_rotation_cipher_key(char *source, unsigned int len);

/**
 * The function will be used to decrypt a cipher text encrypted by rotation cipher without key.
 * I suppose that the original message is a meaningful english string,so we can find the frequency of every single letter
 * from https://en.wikipedia.org/wiki/Letter_frequency.
 * Therefore,we can count the frequency of every letter of every possible original text,and compare it to the letter frequency table.
 * According our assumption,we can find a most likely original text.
 * Notice: The length of cipher text is the longer the better,if you input a very short cipher text,maybe you will get a wrong result.
 * @param source the pointer of cipher text
 * @param dest the pointer to save text after decrypt
 * @param len the length of cipher text
 */
extern void __decrypt_by_rotation_cipher_without_key(char *source, char *dest, unsigned int len);

#endif //SIMPLEENCRYTER_ENCRYPTER_H
