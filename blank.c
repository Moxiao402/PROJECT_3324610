#include "encrypter.h"

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int main() {
    char *source = "Letter frequencies, like word frequencies, tend to vary, both by writer and by subject. One cannot write an essay about x-rays without using frequent Xs, and the essay will have an idiosyncratic letter frequency if the essay is about the use of x-rays to treat zebras in Qatar. Different authors have habits which can be reflected in their use of letters. Hemingway's writing style, for example, is visibly different from Faulkner's. Letter, bigram, trigram, word frequencies, word length, and sentence length can be calculated for specific authors, and used to prove or disprove authorship of texts, even for authors whose styles are not so divergent.";
    char *dest = malloc(sizeof(char) * strlen(source));
    char *dest2 = malloc(sizeof(char) * strlen(source));
    __encrypt_by_rotation_cipher(source, dest, 10, strlen(source));
    printf("%s\n", dest);

    __decrypt_by_rotation_cipher_without_key(dest, dest2, strlen(source));
    printf("%s\n", dest2);
}