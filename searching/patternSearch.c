#include<stdio.h>
#include<string.h>


void main()
{
      char str[10], ptr[10];
      int strLen, ptrLen, i, j, count=0, f=0;

      printf("\n Enter the string : ");
      scanf("%s", str);

      printf("\n Enter the pattern : ");
      scanf("%s", ptr);

      ptrLen = strlen(ptr);
      strLen = strlen(str);

      for(i=0; i<strLen; i++)
      {
            for(j=0; j<ptrLen; j++)
            {
                  if (str[i+j] == ptr[j])
                  {
                        count++;
                  }
            }
            if (count == ptrLen)
            {
                  printf("\n Pattern found at pos %d", i+1);
                  f = 1;
            }
            count = 0;
      }
      if (f == 0)
      {
            printf("\n Pattern not found :(");
      }
      printf("\n");
}
