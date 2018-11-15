#include<stdio.h>


void main()
{
      char str1[20], str2[20], i=0, j;

      printf("\n Enter first string : ");
      scanf("%s", str1);

      printf("\n Enter second string : ");
      scanf("%s", str2);

      while(str1[i] != '\0')
            i++;

      for(j=0; str2[j] != '\0'; ++i,++j)
            str1[i] = str2[j];

      str1[i] = '\0';

      printf("\n After Concatenation : %s ", str1);
      printf("\n");
}


