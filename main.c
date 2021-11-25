#include <stdio.h>
#include <stdlib.h>
struct ogrenci{
    char adsoyad[30];
    char ders[20];
    int vize1,vize2,finalnotu;



};
int main()
{
    int N,i;
    float ort;
    FILE *dosya;
    printf("lutfen ogrenci saiyisini girniz:");
    scanf("%d",&N);
    struct ogrenci ogr[N];
    dosya=fopen("bilgi.txt","w");
    if(dosya==NULL)
    {
        printf("doysa olustulrlaimi");

    }
    else
    {
        for(i=0;i<N;i++)
        {
            fflush(stdin);
            printf("adisoyadi:");
            gets(ogr[i].adsoyad);
            printf("ders adi:");
            gets(ogr[i].ders);
            printf("vize1 notu :");
            scanf("%d",&ogr[i].vize1);
            printf("vize2 notu :");
            scanf("%d",&ogr[i].vize2);
            printf("final notu:");
            scanf("%d",&ogr[i].finalnotu);
            ort=ogr[i].vize1*0.2+ogr[i].vize2*0.2+ogr[i].finalnotu*0.6;
            fprintf(dosya,"%s\t %s\t %d\t %d\t %d\t %.2f\t ",ogr[i].adsoyad,ogr[i].ders,ogr[i].vize1,ogr[i].vize2,ogr[i].finalnotu,ort);
        }

    }
            fclose(dosya);
    return 0;
}
