#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* Nama Kelompok :
* 1. I Made Alit Darma Putra (045)  
* 2. Putu Bagus Dio Pranata (100)
*/ 

void header (){
    char head[500];
	FILE *header=fopen("header.txt", "r");

    if(header == NULL){
        printf("Aplikasi error header.txt tidak ditemukan");
        exit(1);
    }
    while(fgets(head,500,header)!=NULL)
    {
        printf("%s", head);
    }
    fclose(header);
    printf("\n");
}

void daftar_belanja (int menu [], int n[], int harga [], char nama_menu [][20]){
    for(int i=0; i<30; i++){
        switch (menu[i])
        {
            case 1:
                printf("%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[0], n[i], harga[0], harga[0]*n[i]);
                break;
            case 2:
                printf("%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[1], n[i], harga[1], harga[1]*n[i]);
                break;
            case 3:
                printf("%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[2], n[i], harga[2], harga[2]*n[i]);
                break;
            case 4:
                printf("%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[3], n[i], harga[3], harga[3]*n[i]);
                break;
            case 5:
                printf("%d.\t%s\t\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[4], n[i], harga[4], harga[4]*n[i]);
                break;
            case 6:
                printf("%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[5], n[i], harga[5], harga[5]*n[i]);
                break;
            case 7:
                printf("%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[6], n[i], harga[6], harga[6]*n[i]);
                break;
            case 8:
                printf("%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[7], n[i], harga[7], harga[7]*n[i]);
                break;
            case 9:
                printf("%d.\t%s\t\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[8], n[i], harga[8], harga[8]*n[i]);
                break;
            case 10:
                printf("%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[9], n[i], harga[9], harga[9]*n[i]);
                break;
        }
    }
}

int total_bayar(long *Ptotal, int Fpilih[], int Fbanyak[], int harga[]){
    for(int i=0; i<30; i++){
        switch (Fpilih[i]){
        case 1:
            *Ptotal+=harga[0]*Fbanyak[i];
            break;
        case 2:
            *Ptotal+=harga[1]*Fbanyak[i];
            break;
        case 3:
            *Ptotal+=harga[2]*Fbanyak[i];
            break;
        case 4:
            *Ptotal+=harga[3]*Fbanyak[i];
            break;
        case 5:
            *Ptotal+=harga[4]*Fbanyak[i];
            break;
        case 6:
            *Ptotal+=harga[5]*Fbanyak[i];
            break;
        case 7:
            *Ptotal+=harga[6]*Fbanyak[i];
            break;
        case 8:
            *Ptotal+=harga[7]*Fbanyak[i];
            break;
        case 9:
            *Ptotal+=harga[8]*Fbanyak[i];
            break;
        case 10:
            *Ptotal+=harga[9]*Fbanyak[i];
            break;
        }
    }
    return *Ptotal;
}

void diskon (long Ftotal, long *total_diskon){
    int jumlah_diskon; 

    if(Ftotal>=50000){
        if(Ftotal>=50000 && Ftotal<=100000){
            *total_diskon = 0.02 * Ftotal;
            jumlah_diskon = 2;
        }else if(Ftotal>100000 && Ftotal<=300000){
            *total_diskon = 0.03 * Ftotal;
            jumlah_diskon = 3;
        }else if(Ftotal>300000){
            *total_diskon = 0.05 * Ftotal;
            jumlah_diskon = 5;
        }
        printf("\n				Diskon		%d", jumlah_diskon);
        putchar('%');
        printf(" x Rp.%ld       : Rp.   %ld,-", Ftotal, *total_diskon);
    }
}

void rekap (long pendapatan, long penjualan, time_t waktuSekarang){
    struct tm *waktu = localtime (&waktuSekarang);

    FILE *file_rekap = fopen("rekap_pendapatan_harian.txt", "a");
    fprintf(file_rekap, "%i/%i/%i\t\tRp. %ld\t\tRp. %ld\n", waktu->tm_mday, waktu->tm_mon + 1, waktu->tm_year + 1900, penjualan, pendapatan);
    fclose(file_rekap);
}

void struk(int menu [], int n [], int harga [], char nama_menu [][20], long bayar, char nama [], long total_diskon, long total){
    time_t waktu;
    time (&waktu);
    struct tm *waktutm = localtime (&waktu);

    FILE *struk_belanja = fopen("struk.txt", "a");
    fprintf(struk_belanja, "\n%i/%i/%i", waktutm->tm_mday, waktutm->tm_mon+1, waktutm->tm_year+1900);
    fprintf(struk_belanja, "\nPesanan Atas Nama   : %s\n", nama);
    fprintf(struk_belanja, "=======================================================================================");
    fprintf(struk_belanja, "\nNo      Daftar Pesanan       Jumlah               Harga                    Total\n");
    fprintf(struk_belanja, "=======================================================================================\n");
    for(int i=0; i<30; i++){
        switch (menu[i])
        {
            case 1:
                fprintf(struk_belanja, "%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[0], n[i], harga[0], harga[0]*n[i]);
                break;
            case 2:
                fprintf(struk_belanja,"%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[1], n[i], harga[1], harga[1]*n[i]);
                break;
            case 3:
                fprintf(struk_belanja,"%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[2], n[i], harga[2], harga[2]*n[i]);
                break;
            case 4:
                fprintf(struk_belanja,"%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[3], n[i], harga[3], harga[3]*n[i]);
                break;
            case 5:
                fprintf(struk_belanja,"%d.\t%s\t\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[4], n[i], harga[4], harga[4]*n[i]);
                break;
            case 6:
                fprintf(struk_belanja,"%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[5], n[i], harga[5], harga[5]*n[i]);
                break;
            case 7:
                fprintf(struk_belanja,"%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[6], n[i], harga[6], harga[6]*n[i]);
                break;
            case 8:
                fprintf(struk_belanja,"%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[7], n[i], harga[7], harga[7]*n[i]);
                break;
            case 9:
                fprintf(struk_belanja,"%d.\t%s\t\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[8], n[i], harga[8], harga[8]*n[i]);
                break;
            case 10:
                fprintf(struk_belanja,"%d.\t%s\t\t%d\t\tRp. %d,-\t\tRp. %d,-\n", i+1, nama_menu[9], n[i], harga[9], harga[9]*n[i]);
                break;
        }
    }
    fprintf(struk_belanja, "=======================================================================================");
    fprintf(struk_belanja, "\n\t\t\t\t\t\t\tTotal Belanja : Rp. %ld,-", total);
    fprintf(struk_belanja, "\n\t\t\t\t\t\t\tDiskon        : Rp. %ld,-", total_diskon);
    fprintf(struk_belanja, "\n=======================================================================================\n");
    fprintf(struk_belanja, "                                Total Akhir                           : Rp. %ld,-", total-total_diskon);
    fprintf(struk_belanja, "\n\t\t\t\tBayar : \t\t\t\tRp. %ld, -\n", bayar);
    fprintf(struk_belanja, "=======================================================================================\n");
    fprintf(struk_belanja, "\t\t\t\tKembalian                             : Rp. %ld,-\n", bayar-(total-total_diskon));
    fclose(struk_belanja);
}

int main(){
    int pilih[30] = {}, banyak[30], i=0, harga [10]={12000, 10000, 8000, 15000, 10000, 21000, 15000, 15000, 19000, 15000};
    char  nama[20], menu [10][20] = {{"Nasi Goreng"}, {"Mie Goreng"}, {"Roti Bakar"}, {"Kentang Goreng"}, {"Pancake"}, {"Espresso"}, {"Caffe Late"}, {"Capuccino"}, {"Mocha"}, {"Milk Tea"}};
    long total = 0, total_diskon=0, bayar, rekap_pendapatan = 0, rekap_penjualan = 0;
    char lanjut;
    time_t waktuSekarang;

    do{
        header ();
        time (&waktuSekarang);
        do{                                             //mengambil pesanan//
            printf("\nMasukkan pilihan menu :");
            scanf("%d", &pilih[i]);
            printf("Masukkan jumlah pesanan :");
            scanf("%d", &banyak[i]);
            system("cls");
            header();
            printf("\nDaftar pesanan sementara :\n");
            daftar_belanja(pilih, banyak, harga, menu);
            i++;
            if(i == 30){
                printf("\nAnda sudah mencapai batas pemesanan yang dapat dilakukan\n");
            }
        }while (pilih[i-1]!=0 && i != 30);

        fflush(stdin);

        printf("\nNama Pemesan :");
        scanf("%[^\n]s", &nama);
        
        system("cls");                  //mencetak hasil akhir pesanan//
        header();                   
        printf("\n\nPesanan Atas Nama   : %s\n", nama);
        printf("=======================================================================================");
        printf("\nNo      Daftar Pesanan       Jumlah               Harga                    Total\n");
        printf("=======================================================================================\n");
        daftar_belanja(pilih, banyak, harga, menu);
        printf("=======================================================================================");
        printf("\n\t\t\t\t\t\t\tTotal Belanja : Rp. %ld,-", total_bayar(&total, pilih, banyak, harga));
        diskon(total, &total_diskon);
        printf("\n=======================================================================================\n");
        printf("                                Total Akhir                           : Rp. %ld,-\n", total-total_diskon);
        printf("\t\t\t\tBayar                                 : Rp. ");
        scanf("%ld", &bayar);
        printf("=======================================================================================\n");
        printf("\t\t\t\tKembalian                             : Rp. %ld,-", bayar-(total-total_diskon));
        printf("\n\nTerima kasih sudah berkunjung di Rindu Kopi\n\n");

        rekap_pendapatan += total-total_diskon;
        rekap_penjualan += total;

        FILE *daftar_transaksi = fopen("daftar_transaksi.txt", "a");        //mencetak hasil transaksi ke dalam file//
        fprintf(daftar_transaksi, "  %s \t\t\t\t %s \t\t\t Rp.%ld \t\t\t Rp.%ld \t\t\t\t Rp.%ld\n", ctime(&waktuSekarang), nama, total, total_diskon, total-total_diskon);
        fclose(daftar_transaksi);

        struk(pilih, banyak, harga, menu, bayar, nama, total_diskon, total);

        fflush(stdin);

        printf("\nApakah anda ingin melakukan transaksi lainnya (Y/N) : ");
        scanf("%c", &lanjut);

        if(lanjut == 'Y'){                  //mengembalikan isi variabel ke awal//
            i = total = total_diskon = 0;
            for(int j = 0; j<30; j++){
                pilih[j] = 0;
                banyak[j] = 0;
            }
        }
        system("cls");
    }while(lanjut != 'N');

    rekap(rekap_pendapatan, rekap_penjualan, waktuSekarang);          
    printf("\nData Transaksi Berhasil di Simpan");
    return 0;
}