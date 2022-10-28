#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
typedef struct sinhVien
{
    char hoten[100];
    char gioitinh[5];
    int tuoi;
    float dtoan,dly,dhoa,dtb;
}sV;
sV sv1[100];

int main()
{
    int n;
    
    printf("nhap vao so sinh vien: ");
    scanf("%d",&n);

    //ham nhap
    for (int i = 0 ; i < n; i++)
    {
        printf("ho va ten sinh vien thu [%d]: ",i);
        getchar();
        gets(sv1[i].hoten);
        fflush(stdin);
        printf("nhap gioi tinh va tuoi: ");
        fflush(stdin);
        gets(sv1[i].gioitinh);
        scanf("%d",&sv1[i].tuoi);
        printf("nhap diem toan ly hoa: ");
        scanf("%f%f%f",&sv1[i].dtoan,&sv1[i].dly,&sv1[i].dhoa);
        sv1[i].dtb = (sv1[i].dtoan+sv1[i].dly+sv1[i].dhoa)/3;
    }

// sap xep
    sV tmp;
    for(int i = 0;i < n;++i){
        for(int j = i+1; j < n;++j){
            if(sv1[i].dtb > sv1[j].dtb){
                tmp = sv1[i];
                sv1[i] = sv1[j];
                sv1[j] = tmp;
            }
        }
    }

//ham xuat
    for (int i = 0 ; i < n; i++)
    {
        printf("\nho ten sinh vien [%d]: ",i);
        puts(sv1[i].hoten);
        printf("gioi tinh va tuoi sv[%d]: %s - %d",i,sv1[i].gioitinh,sv1[i].tuoi);
        printf ("\ndiem toan - ly - hoa la: %.2f - %.2f - %.2f",sv1[i].dtoan,sv1[i].dly,sv1[i].dhoa);
        printf ("\ndiem trung binh la: %.2f",sv1[i].dtb);

    }

}