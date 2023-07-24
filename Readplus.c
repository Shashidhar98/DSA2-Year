#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    FILE *fp;
    char str[10];
    char ch;
    fp= fopen("bye.txt","r+");
    if(fp==NULL)
    {
        printf("Error");
        exit(0);
    }
    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    fputs("zzz",fp);
      
        fputc('k',fp);
        fseek(fp,5,SEEK_SET);
        fputc('Z',fp);
            fclose(fp);

}