#include "encrypter.h"
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

float choice=0;


int main() {
    char *source="RCR VYE BGBX HBNX FHB FXNQBRV YM RNXFH IZNQEBCJ FHB PCJB? C FHYEQHF KYF. CF'J KYF N JFYXV FHB DBRC PYEZR FBZZ VYE. CF'J N JCFH ZBQBKR. RNXFH IZNQEBCJ PNJ N RNXA ZYXR YM FHB JCFH, JY IYPBXMEZ NKR JY PCJB HB LYEZR EJB FHB MYXLB FY CKMZEBKLB FHB OCRCLHZYXCNKJ FY LXBNFB ZCMB… HB HNR JELH N AKYPZBRQB YM FHB RNXA JCRB FHNF HB LYEZR BGBK ABBI FHB YKBJ HB LNXBR NWYEF MXYO RVCKQ. FHB RNXA JCRB YM FHB MYXLB CJ N INFHPNV FY ONKV NWCZCFCBJ JYOB LYKJCRBX FY WB EKKNFEXNZ. HB WBLNOB JY IYPBXMEZ… FHB YKZV FHCKQ HB PNJ NMXNCR YM PNJ ZYJCKQ HCJ IYPBX, PHCLH BGBKFENZZV, YM LYEXJB, HB RCR. EKMYXFEKNFBZV, HB FNEQHF HCJ NIIXBKFCLB BGBXVFHCKQ HB AKBP, FHBK HCJ NIIXBKFCLB ACZZBR HCO CK HCJ JZBBI. CXYKCL. HB LYEZR JNGB YFHBXJ MXYO RBNFH, WEF KYF HCOJBZM.";

    char *dest = malloc(sizeof(char) * strlen(source));
    __decrypt_by_substitution_cipher_without_key(source,dest,strlen(source));
    printf("%s\n", dest);
    printf("%d\n",strlen(dest));


    printf("WELCOME TO THE ENCRYOTION AND DECRYOTION PROGRAM.\n");
    printf("PLEASE SELECT THE FOLLOWING FUNCTION THAT YOU WOULD LIKE TO ACCESS:\n");
    printf("1. ROTATION ENCRYPTION WITH KEY\n");
    printf("2. ROTATION DECRYPTION WITH KEY\n");
    printf("3. ROTATION DECRYPTION WITHOUT KEY\n");
    printf("4. SUBSTITUTION ENCRYPTION WITH SUBSTITUTION\n");
    printf("5. SUBSTITUTION DECRYPTION WITH SUBSTITUTION\n");
    printf("6. SUBSTITUTION DECRYPTION WITHOUT SUBSTITUTION GIVEN\n");



    printf("Please make your choice here and press space:" );
           scanf("%f", &choice);

    if (choice = 1) {

        char*source;
        char *dest = malloc(sizeof(char) * strlen(source));


        __encrypt_by_rotation_cipher(source,dest,key1, strlen(source));
        printf("%s\n", dest);
        printf("%d\n", key1);



    }

    else if(choice= 2){

        char source[900];
    printf("Please type in the message that you want to decrypt here and press space:");
      scanf("%s", source);


        char *dest = malloc(sizeof(char) * strlen(source));
        __decrypt_by_rotation_cipher(source, dest, 10, strlen(source));
        printf("%s\n", dest);

    }

    else if (choice= 3){

        char *source=0;
        printf("Please type in the message that you want to sent here and press space:");

        char *dest = malloc(sizeof(char) * strlen(source));
        __decrypt_by_substitution_cipher_without_key(source,dest, strlen(source));
        printf("s\n", dest);
        printf("%d\n",strlen(dest));

    }




    else if(choice=6){
        char *source="RCR VYE BGBX HBNX FHB FXNQBRV YM RNXFH IZNQEBCJ FHB PCJB? C FHYEQHF KYF. CF'J KYF N JFYXV FHB DBRC PYEZR FBZZ VYE. CF'J N JCFH ZBQBKR. RNXFH IZNQEBCJ PNJ N RNXA ZYXR YM FHB JCFH, JY IYPBXMEZ NKR JY PCJB HB LYEZR EJB FHB MYXLB FY CKMZEBKLB FHB OCRCLHZYXCNKJ FY LXBNFB ZCMB… HB HNR JELH N AKYPZBRQB YM FHB RNXA JCRB FHNF HB LYEZR BGBK ABBI FHB YKBJ HB LNXBR NWYEF MXYO RVCKQ. FHB RNXA JCRB YM FHB MYXLB CJ N INFHPNV FY ONKV NWCZCFCBJ JYOB LYKJCRBX FY WB EKKNFEXNZ. HB WBLNOB JY IYPBXMEZ… FHB YKZV FHCKQ HB PNJ NMXNCR YM PNJ ZYJCKQ HCJ IYPBX, PHCLH BGBKFENZZV, YM LYEXJB, HB RCR. EKMYXFEKNFBZV, HB FNEQHF HCJ NIIXBKFCLB BGBXVFHCKQ HB AKBP, FHBK HCJ NIIXBKFCLB ACZZBR HCO CK HCJ JZBBI. CXYKCL. HB LYEZR JNGB YFHBXJ MXYO RBNFH, WEF KYF HCOJBZM.";

        char *dest = malloc(sizeof(char) * strlen(source));
        __decrypt_by_substitution_cipher_without_key(source,dest,strlen(source));
        printf("%s\n", dest);
        printf("%d\n",strlen(dest));

    }

    else {

        printf("The choice is not available, sorry.");

    }


}
