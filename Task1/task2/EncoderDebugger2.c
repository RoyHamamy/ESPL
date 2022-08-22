#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
   if(strncmp(argv[i],"-o", 2) == 0){
     out = fopen(argv[i] + 2,"w+");	
   }
}
if(((changer < 48) || ((changer > 57) & (changer < 65)) || (changer > 70))&(encript != 0)){
	  fprintf(stderr,"Invalid text !");
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
     fprintf(stderr,"%d", ch);
     fprintf(stderr, "%s", " ");
     if((ch >= 65) && (ch <= 90)){
	int dot = 46;
	fputc(dot,out);
	fprintf(stderr,"%d\n",dot);
	count = count + 1;
	}
     else{
	if(ch == 10){
	  fprintf(out,"%s","\n");
	  fprintf(stderr,"the number of letters: %d" ,count);
	  count = 0;
  	  fprintf(out,"%s","\n");
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
	       fprintf(out,"%c", ch);
	       ch = fgetc(in);		
	   }
	   for(int i = 0; i < temp; i++){
	   if(first != '\n')
	    fprintf(out,"%c",first);
	  }
	  fprintf(out,"%s","\n");  
	  first = '\0';
	  
	}
	if(encript == -1){
		while(ch != '\n'){
	  if(ctemp == 0)
			fprintf(out,"%c",ch);
	  if(ctemp != 0)
		  ctemp = ctemp - 1;
	  ch = fgetc(in);	  				
    }
        if(ctemp > 0)
          fprintf(out,"%s\n","-NONE-");
        if(ctemp == 0)
          fprintf(out,"%s","\n");  
	ctemp = temp;
	}
}
else{
     if((ch >= 65) && (ch <= 90)){
        int dot = 46;
	fprintf(out,"%c", dot);
    }
     else{
	 fprintf(out,"%c", ch);
  }
}
}
}

