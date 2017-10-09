#include "utils.h"
#include <string.h>
#include <malloc.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
int num=-1;
int is_empty=1;
int word=0;
int len=strlen(command);
char token[150][150]={0};

for(int i=0; i<len; i++){
if(command[i]==' '||command[i]=='\t'||command[i]=='\n'){
if(is_empty==0)
is_empty=1;
}
else{
if(is_empty==1){
  num++;
word=0;
token[num][word++]=command[i];
is_empty=0;
}
else{
token[num][word++]=command[i];
}
}
}
if(num==-1){
*argc=1;
*argv=(char **)malloc(sizeof(char*));
(*argv)[0]=(char*)malloc(sizeof(char));
return;
} 
(*argv) = (char **)malloc(sizeof(char*) * (num+1));
for(int i=0; i<=num; i++){
(*argv)[i]=(char*)malloc(sizeof(char)*(strlen(token[i])+1));
strcpy((*argv)[i],token[i]);
}
 (*argc)=num+1;
 // TODO: Fill this!
}
