#include <stdio.h>
#include <stdlib.h>

struct inis_pisti_kullanim_sirasi{
int oncelik_id;
int ucak_id;
int talep_edilen_inis_saati;
int erteleme_Sayaci;
struct inis_pisti_kullanim_sirasi *next;
};
typedef struct inis_pisti_kullanim_sirasi inis;
// function adds element in the structure.

inis inis_listesi[28];
inis *inis_sirasi=NULL;
inis *aktif_konum=NULL;
int guncel_veri_sayisi=0;
int saat=1;


void add(inis *eklenecek)
{
    aktif_konum=inis_sirasi;
    while(aktif_konum->next!=NULL)
        aktif_konum=aktif_konum->next;

    aktif_konum->next=(inis*)malloc(sizeof(inis));
    aktif_konum->next=eklenecek;
    aktif_konum=aktif_konum->next;
    aktif_konum->next=NULL;
    guncel_veri_sayisi++;
}

void kontrollu_ekleme(inis *eklenecek_eleman)
{


}


//deletes the last element and turns it.
/*struct inis *pool()
{

}

// turns the last element without deletes it
struct inis *peek()
{

}*/

// deletes all of the element
void clear()
{

}

// deletes the reported element
void removes()
{

}


void inis_izni_talep_et(inis *ptr)
{
    if(guncel_veri_sayisi==24)
    {

    }

    else
    {
        if(guncel_veri_sayisi==0)
            {
              inis_sirasi=(inis*)malloc(sizeof(inis));
              *inis_sirasi=*ptr;
              inis_sirasi->next=NULL;
              guncel_veri_sayisi++;
              //exit(0);
            }
        else
        {
          add(ptr);
        }




    }


}

void inislistesiyazdir()
{
    inis *iter;
    iter=inis_sirasi;
    for(int i=0;i<24;i++)
    {
    if(iter == NULL)
        {
          printf("null elemana gelindi");
            break;
        }
    printf("%d %d %d\n",iter->oncelik_id,iter->ucak_id,iter->talep_edilen_inis_saati);

    if(iter->next == NULL)
        {
          break;
        }


    iter=iter->next;
    }
}



int main()
//taking and put the values to array from the input.txt
{

FILE *input=fopen("input.txt","r");
inis x[1];
int i,j;
//1st line override
fseek(input,42,SEEK_SET);
 for(int i=0;i<28;i++)
 {
    fscanf(input,"%d %d %d",&inis_listesi[i].oncelik_id,&inis_listesi[i].ucak_id,&inis_listesi[i].talep_edilen_inis_saati);
 }

 for(int i=0;i<28;i++)
 {
        printf("%d %d %d\n",inis_listesi[i].oncelik_id,inis_listesi[i].ucak_id,inis_listesi[i].talep_edilen_inis_saati);
 }
 // inis_listesi siralama


     for(i=0;i<28;i++)
    {
        for(j=1;j<28;j++)
        {
            if(inis_listesi[j-1].talep_edilen_inis_saati>inis_listesi[j].talep_edilen_inis_saati)
            {
                x[0]=inis_listesi[j];
                inis_listesi[j]=inis_listesi[j-1];
                inis_listesi[j-1]=x[0];
            }
        }
    }
    printf("\n\n\n\n");
    for(int i=0;i<28;i++)
    {
    printf(" gonderilen inis listesi elemani= %d %d %d\n",inis_listesi[i].oncelik_id,inis_listesi[i].ucak_id,inis_listesi[i].talep_edilen_inis_saati);
    inis_izni_talep_et(&inis_listesi[i]);
    inislistesiyazdir();
    printf("\n\n");
    }



    printf("\nguncel veri %d",guncel_veri_sayisi);



    return 0;
}
