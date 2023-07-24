#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int countChar(char b[])
{
    int count=0,i=0;
    while(b[i]!='\0')
    {
        i++;
        count++;
    }
    return count;
}
int match(int arr1[26],int arr2[26])
{
   for(int i=0;i<26;i++)
   {
    if(arr1[i]!=arr2[i])
    {
        return 0;
    }
   }
   return 1;
}
void sW(FILE* fp,char pattern[],char b[])
{
    int n=countChar(pattern);
    int i=0,k=0,count=0;
    char ch;
    int arr[50];
    int arr1[33]={0},arr2[33]={0};
    for(int j=0;j<n;j++)
    {
       arr1[pattern[j]-'a']++;
    }
    while(i<n &&  ((ch=fgetc(fp))!=EOF))
    {
        printf("%c ",ch);
        if((ch>=97 && ch<=123) || ch==32)
        {
            arr2[ch-'a']++;
            i++;
        }
        else{
            if(ch=='\n')
            arr2[' '-'a']++;
            i+=2;
        }
    }

    if(match(arr1,arr2)==1)
    {
        count++;
       fseek(fp,-1*n,SEEK_CUR);
       arr[k++]=ftell(fp);
       fseek(fp,n,SEEK_CUR);
    }
    while((ch=fgetc(fp))!=EOF)
    {
        if((ch<97 || ch>123) && ch!=32)
        {
            ch=' ';
        }
        printf("%c ",ch);
       arr2[ch-'a']++;
       fseek(fp,-1*(n+1),SEEK_CUR);
       arr2[fgetc(fp)-'a']--;
       if(match(arr1,arr2)==1)
       {
        printf("hi\n");
        count++;
        arr[k++]=ftell(fp);
        fseek(fp,n,SEEK_CUR);
       }
       else{
        fseek(fp,n,SEEK_CUR);
       }
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++)
    {
        fseek(fp,arr[i],SEEK_SET);
        fputs(b,fp);
    }
}
void main()
{
    FILE* fp=NULL;
    fp=fopen("virat.txt","r+");
    if(fp==NULL)
    {
        printf("Error in creating a file\n");
        exit(0);
    }
    char pattern[30];
    char b[40];
    printf("Enter the pattern\n");
    gets(pattern);
    printf("Enter a string you want relace the pattern with\n");
    gets(b);
    sW(fp,pattern,b);
    printf("Successful\n");
    fclose(fp);
}