#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*
void ParseValueStr(char *Des,char* SrcStr)
{
  int iLen = strlen(SrcStr);
  if(iLen == 0)
  {
    return;
  }
  if()
}
*/
int main(int args,char * argc[])
{
    if(args < 3)
    {
     printf("you should 2 world\n");
     return 1;
    }
    char buf[100];
    char value[100];
    int values[32];
    int set_flag = 0;
    int len,line = 0;
    char *p;
    
    FILE* fp = fopen(argc[1],"r");
    FILE* fp_output = fopen("output_1.map","w+");
    /*while(!(feof(fp)))
    {
     fgets(buf,sizeof(buf),fp);
     //ParseValueStr();
    }
    fclose(fp);
    fp = NULL;
    printf("%s\n",buf);
    */
    while(fgets(buf,sizeof(buf),fp)!=NULL)
    {
      line++;
      len = strlen(buf);
      buf[len-1] = '\n';
      printf("%s %d\n",buf,line);
      p = strstr(buf,"MODULE SUMMARY");
      if(p)
      {
        set_flag = 1;
        printf("%s %d\n",buf,line);
        fwrite(buf,len-1,1,fp_output);
        continue;
      }
     if(set_flag == 1)
     {
        p = strstr(buf,argc[2]);
        if(p)
        {
          fwrite(buf,len-1,1,fp_output);
          printf("!!!!!!ok!!!!!!!!!!\n");
          fclose(fp_output);
          break;
        }
     }
     
    }
    
    return 0;



}
