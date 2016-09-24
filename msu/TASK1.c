#include<stdio.h>
#include<stdlib.h>
#define STEP 16
char *realgets(FILE*);
main()
{
	char *str4test;
	str4test=realgets(stdin);
	printf("\nВведенная строка для теста :%s\n", str4test);
}
char *realgets(FILE *realfile)
{
	int i=0,c ,j=0;
	char *realstring=NULL, *temp=NULL;
	if(realfile==NULL){
		fprintf(stderr, "problem with input file\n");
		return NULL;
	}
	while ((c=fgetc(realfile))!='\n' && c!=EOF){
		i++;
		if((j*STEP)<i) {
			if((temp=(char*)realloc(realstring, sizeof(char)*i))==NULL){
				fprintf(stderr,"problem with memori allocation\n");
				free(realstring);
				return NULL;
			}
			else realstring=temp;
		}
	realstring[i-1]=c;
	}
	i++;
		if((temp=(char*)realloc(realstring,sizeof(char)*i))==NULL){
			fprintf(stderr,"problem with memori allocation\n");
			free(realstring);
			return NULL;
		}
	else realstring=temp;
	realstring[i-1]='\0';
	return realstring;
}
