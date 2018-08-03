void DrawTable(int raws,int cols)
{
  {
    int x0=3,y0=2;
    int x[7];
    int xy[7];
    int xy1[7];
    int xy2[4];
     int i=0,j=0;
     int x1=16*cols+x0;
     int y1=2*(raws+1)+2;
     SetXY(x0+34,y0-1);
     printf("商品信息");
     for(i=0;i<7;i++)
     {
         xy[i]=5+(16*i);
     }
     SetXY(x0,y0);
     printf("┌");
     SetXY(x1,y0);
     printf("┐");
     SetXY(x0,y1);
     printf("└");
     SetXY(x1,y1);
     printf("┘");
     for(i=1;i<x1-x0;i++)
    {
        for(j=0;j<y1;j++)
        {
            if(j%2==0)
            {
                SetXY(x0+i,y0+j);
                printf("─");
            }
        }
    }
     for(j=1;j<y1-y0;j++)
    {
        for(i=0;i<cols+1;i++)
        {
        SetXY(x0+(16*i),y0+j);
        printf("│");
        }
    }
     for(i=1;i<cols;i++)
     {
         SetXY(x0+(16*i),y0);
         printf("┬");
         SetXY(x0+(16*i),y1);
         printf("┴");
     }
     SetXY((x1-12),y1+1);
}
}

