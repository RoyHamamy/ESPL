#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char censor(char c) {
  if(c == '!')
    return '*';
  else
    return c;
}

char encrypt(char c) {
    if((c >=41 && c <= 122)){
        c = c + 2;
    }
    return c;
}

char cprt(char c){
    if(c >= 0x41 && c <= 0x7a){
        printf("%c\n", c);
    }
    else{
        printf("%c\n", '*');
    }

    return c;
}

char my_get(char c){
    char a = fgetc(stdin);
    return a;
}

char decrypt(char c){
    if((c >=41 && c <= 122)){
        c = c - 2;
    }
    return c;
}

char dprt(char c){
    printf("%d\n", c);
    return c;
}

char* map(char *array, int array_length, char (*f) (char)){
    char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
    for(int j = 0; j < array_length; j++){
        *(mapped_array + j) = f(*(array + j));
    }
    return mapped_array;
}

char quit(char c){
    if(c == 113){
        exit(0);
    }
    else{
        return c;
    }
}

struct fun_desc {
  char *name;
  char (*fun)(char);
};

int main(){
struct fun_desc ans[] = { {"cencor",censor} , {"Encrypt" , encrypt} , {"Decrypt" , decrypt} , {"Print dec" , dprt} , {"Print string" , cprt} , {"Get string" , my_get} , {"Quit",quit}};
char ch;
int some = 100;
char* arr = (char*)calloc(6, sizeof(char));

while (some != 1){
printf("please choose a function: ");
printf("\n");
for(int i = 0; i < 7; i ++){

   printf("%d) %s\n" , i , ans[i].name);
   
}
   
printf("options: ");

ch = fgetc(stdin);
fgetc(stdin);
if(((ch >= 48) && (ch <= 53))){
printf("within bounds");
printf("\n");
int index = ch - 48 ;
char* otherArr= map(arr , 5 , ans[index].fun);
arr = otherArr;
printf("done.");
printf("\n");
printf("\n");

}
else if(ch == 54){
ch = quit('q');
}
else{

printf("not within bounds");
printf("\n");
printf("\n");

free(arr);

return 0;
}
}

return 0;
}





