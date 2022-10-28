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

void nhap(int &n)
{
    //ham nhap
    printf("nhap vao so sinh vien: ");
    scanf("%d",&n);
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
}

void sapXep(int n)
{
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
}

void xuat(int n)
{
    //ham xuat
        for (int i = 0 ; i < n; i++)
    {
        printf("\nho ten sinh vien [%d]: ",i);
        puts(sv1[i].hoten);
        printf("gioi tinh va tuoi sv[%d]: %s - %d",i,sv1[i].gioitinh,sv1[i].tuoi);
        printf("\ndiem toan - ly - hoa la: %.2f - %.2f - %.2f",sv1[i].dtoan,sv1[i].dly,sv1[i].dhoa);
        printf("\ndiem trung binh la: %.2f",sv1[i].dtb);

        if (sv1[i].dtb >= 8)
        {
            printf("\nhoc sinh nay loai gioi");
        }
        else if (sv1[i].dtb >= 5)
        {
            printf("\nhoc sinh nay loai kha");
        }
        else
        {
            printf("\nhoc sinh nay ngu");
        }
}
}

void docFile(int n)
{
        FILE *ptr;
    ptr = fopen("C:\\Users\\ACER NITRO 5\\Desktop\\Git\\student_lib\\sb.txt","w");
    if(ptr == NULL)
{
    printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1); 
}

    for (int i = 0 ; i < n; i++)
    {
        fprintf(ptr,"\nho ten sinh vien [%d] la: %s ",i,sv1[i].hoten);
        fprintf(ptr,"\ngioi tinh va tuoi sv[%d]: %s - %d",i,sv1[i].gioitinh,sv1[i].tuoi);
        fprintf(ptr,"\ndiem toan - ly - hoa la: %.2f - %.2f - %.2f",sv1[i].dtoan,sv1[i].dly,sv1[i].dhoa);
        fprintf(ptr,"\ndiem trung binh la: %.2f",sv1[i].dtb);
        fprintf(ptr,"\n-------------------------------------------------------------------------------------------------");
    }
fclose(ptr);
}

int main()
{
    label:
    int n,chon;
    printf ("=======================lua chon cua ban la gi=======================\n");
    printf("1: nhap sinh vien\n");
    printf("2: xuat sinh vien\n");
    printf("3: sep xep sinh vien\n");
    printf("4: doc File sinh vien\n");
    printf("5: thoat chuong trinh\n");

    scanf("%d",&chon);
    
    switch(chon){
        case 1: nhap(n);
        break;
        case 2 : xuat(n);
        break;
        case 3 : sapXep(n);
        break;
        case 4 : docFile(n);
        break;
        case 5 : return 0;
        break;
        default: printf("chon lai");
        break;
    }
    printf("\nnhan phim bat ky de tiep tuc: ");
    _getch();
    goto label;
}