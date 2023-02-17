/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 2 - String and External Files
 *   Hari dan Tanggal    : Jumat, 17 Februari 2023
 *   Nama (NIM)          : Dimas Ridhwana Shalsareza (13221076)
 *   Nama File           : main.c
 *   Deskripsi           : Membaca file dan melakukan validasi substring
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char nama_file[20];
    char str[10000];                        //-------Debug
    int i=0;

    int state;
    int prev_state = -1;
    int jumlah=0, temp_jumlah, max = 0;
    int index_temp; 
    int index_max = 0;

    int count = 0;                          //------ DEBUG


    scanf("%s", nama_file);
    // nama_file[20] = "student.txt";       //-------- DEBUG
    // printf("%s", nama_file);             //-------- DEBUG

    FILE *file = fopen(nama_file, "r");

    if (file == NULL){
        printf("Error : file tidak ada \n");
        return(0);
    } else{
        while(fgets(str, sizeof(str), file)){
            ++count;                                                                        //---------DEBUG 
            // printf("%d. %s",count, str);                                                 //---------DEBUG
            // printf(" %d\n", strlen(str));                                                //---------DEBUG
            // printf("       ---------------------------------------          ");          //---------DEBUG
            // printf("\nWhile looping ke-%d\n", count);                                    //---------DEBUG

            for (i=0; i<=strlen(str); i++){
                if ((int)str[i] >= 97 && ((int)str[i] <= 122)){             //Lowercase
                    state = 0;
                } else if ((int)str[i] >= 65 && ((int)str[i] <= 90)){       //Uppercase
                    state = 1;
                } else if ((int)str[i] >= 48 && ((int)str[i] <= 57)){       //Number
                    state = 2;
                } else{
                    state = 3;
                }

                // printf("For looping ke-%d\n",i);                                     //---------DEBUG
                // printf("    str[i] = %c\n",str[i]);                                  //---------DEBUG
                // printf("    state = %d\n",state);                                    //---------DEBUG   

                if (state == prev_state){
                    jumlah++;
                } else {
                    temp_jumlah = jumlah;
                    if (temp_jumlah>max){
                        max = temp_jumlah;
                        index_max = index_temp;
                    }
                    prev_state = state;
                    jumlah = 1;
                    index_temp = i;
                }

                // printf("    str[i] = %c\n",str[i]);                                  //---------DEBUG
                // printf("        Jumlah              : %d\n",jumlah);                 //---------DEBUG
                // printf("        nilai  Max          : %d\n",max);                    //---------DEBUG
                // printf("        index max           : %d\n",index_max);              //---------DEBUG
                // printf("        index temp          : %d\n",index_temp);             //---------DEBUG
                // printf("        nilai  Max akhir    : %d\n",max);                    //---------DEBUG
            }    


            // Print highest substring
            i=0;
            if (count>1){
                for (i=index_max; i<(index_max+max); i++){
                    printf("%c",str[i]);
                }
                printf("\n");
            }
            // printf("       ---------------------------------------          \n");    //---------DEBUG
            i=0, index_max=0, index_temp=0, state=0,prev_state=-1,jumlah=0;
            jumlah=0, temp_jumlah, max = 0;
        }   
    }
    fclose(file);
    return(0);
}       