#include <stdio.h>
#include <string.h>

    char encrypmessage[100], decrypmessage[100];
    int i,k,shift,l;
    int choice1,choice2;
     
int main(){


     printf("Please choose which from which task you would like me to conduct, and input its number:\n");
     printf("1. Encryption\n");
     printf("2. Decryption\n");
    
     scanf("%d", &choice1);
     
     if(choice1=1){
     printf ("Enter a message to send:\n");
     gets(encrypmessage);
     l=strlen(encrypmessage);
    
     printf ("Enter a key:\n");
     scanf ("%d", &shift);
    
    
for(i=0; i<l; i++)
    {
          if(encrypmessage[i]>='A' && encrypmessage[i]<='Z' )
          {
              encrypmessage[i]=(encrypmessage[i]-'A'+shift)%26 + 'A';
              
          } 
          else if(encrypmessage[i]>='a' && encrypmessage[i]<= 'z'){
           encrypmessage[i]= (encrypmessage[i]-'a'+ shift )%26+'a';
     }
 }

     printf("%s\n",encrypmessage);
}

 return 0;
 
}