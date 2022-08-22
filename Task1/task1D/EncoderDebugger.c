#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv){
FILE* out = stdout;
FILE* in = stdin;
char ch;
char first = '\0';
int count = 0;
int debug = 0;
int temp = 0;
int ctemp = 0;
int encript = 0; 
int changer = 0;

for(int i=1; i<argc; i++){
   if(strcmp(argv[i],"-D")==0)
     debug = 1;
   if(strncmp(argv[i], "+e" , 2) == 0){
     encript = 1;
     changer = argv[i][2];
   }
   if(strncmp(argv[i],"-e", 2) == 0){
     encript = -1;
     changer = argv[i][2];	
   }
   if(strncmp(argv[i],"-i", 2) == 0){
     in = fopen(argv[i] + 2,"r");	
   }
}
if(((changer < 48) || ((changer > 57) & (changer < 65)) || (changer > 70))&(encript != 0)){
	  printf("Invalid text !");
	  return 1;
	}
	if((changer >= 48) && (changer <= 57)){
	  temp = changer - 48;
	}
	if((changer >= 65) && (changer <= 70)){
	    temp = changer - 55;
	}
ctemp = temp;
while((ch =  fgetc(in)) != EOF){
if(debug == 1){
     if(ch == 10){
	  printf("\n");
	  printf("the number of letters: %d" ,count);
	  count = 0;
  	  printf("\n");
	}
     else{
     fprintf(stderr,"%d", ch);
     fprintf(stderr, "%s", " ");
     if((ch >= 65) && (ch <= 90)){
	int dot = 46;
	fputc(dot,out);
	fprintf(stderr,"%d\n",dot);
	count = count + 1;
	}
     else{
	
	fprintf(stderr,"%d\n",ch);
	fputc(ch,out);
    }
  }
}
else if(encript == 1 || encript == -1){
	if(encript == 1){
	  if(first == '\0')
	    first = ch;
		while(ch != '\n'){
	       printf("%c", ch);
	       ch = fgetc(in);		
	   }
	   for(int i = 0; i < temp; i++){
	   if(first != '\n')
	    printf("%c",first);
	  }
	  printf("\n");  
	  first = '\0';
	  
	}
	if(encript == -1){
		while(ch != '\n'){
	  if(ctemp == 0)
			printf("%c",ch);
	  if(ctemp != 0)
		  ctemp = ctemp - 1;
	  ch = fgetc(in);	  				
    }
        if(ctemp > 0)
          printf("%s\n","-NONE-");
        if(ctemp == 0)
          printf("\n");  
	ctemp = temp;
	}
}
else{
     if((ch >= 65) && (ch <= 90)){
        int dot = 46;
	fputc(dot,out);
    }
     else{
	 fputc(ch,out);
  }
}
}
}

