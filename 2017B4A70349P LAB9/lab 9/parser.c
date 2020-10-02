#include "parser.h"


int get_size(char* filename)
{
	FILE* f=fopen(filename,"r");
	FILE* f2=fopen("temp.txt","w");
	int count=0;
	if(f==NULL)
	{
		printf("error");
		exit(0);
	}

	char c;
    int found_word = 0;

        while ((c =fgetc(f)) != EOF )
        {
            if (isalpha(c))
            {
                found_word = 1;
                c = tolower(c);
                fputc(c,f2);
            }
            else {
                if (found_word) {
                    fputc('\n',f2);
                    found_word=0;
                    count++;
                }
            }

        }
    fclose(f);
    fclose(f2);
    printf("Number of words are %d",count);
    return count;

}

char** parse(char* filename,int count)
{
	FILE *f;
	char c;
    int i=0;
    f=fopen("temp.txt","r");
    char **elements;
    elements=malloc(count*sizeof(char *));
    for(int i=0;i<count;i++)
    {
    	elements[i]=malloc(20*sizeof(char));
    }

    // char elements[count][20]; //20 is max size of a word
    while(i<count)
    { 
    	int j=0;
    	c=fgetc(f);
    	while(isalpha(c)|| c!='\n')
    	{
    		elements[i][j++]=c;
    		c=fgetc(f);
    	}
    	elements[i][j]='\0';
    	// printf("%s\n",elements[i]);
    	i++;
    }
    return elements;
}
