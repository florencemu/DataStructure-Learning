#include <stdio.h>

#include <string.h>

#define N 100

int main()

  {

      int m;

      int n;

         printf("请输入总人数n \n");

         scanf("%d",&n);

         printf("请输入报的数m \n");

         scanf("%d",&m);

      int a[N] = {0};

      int i;

      int j;

         int k = 0;

         for(i = 0; i < n; i++)

      {

          a[i] = i+1;

      }

      while (n > 1)

      {

          i = (i + m - 1) % n;

                k++;

                printf("第%d个出圈的是%d\n",k,a[i]);

          for(j = i+1; j < n; j++)

          {

              a[j-1] = a[j];

          }

          n--;

          if(i == n)

                {

                    i = 0;

          }

      }

      printf("最后剩下的时%d\n", a[i]);

      return 0;

  }
