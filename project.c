#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user{
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};

int main(){
    struct user usr;
    FILE *fp;
    char filename[50], passwordcheck[20], accountcheck[30];
    usr.balance = 100000;
    float prev = usr.balance; 
    float withamount, depamount;
    int check; // 2nd choice
    int choice; // 1st choice

    printf("\n              Online Banking system            ");
    printf("\n______________________________________________ \n");
    printf("\n|             1. Regiister an account         |");
    printf("\n|             2. Login to an account          |");
    printf("\n|             3. EXIT the pprograme           |");
    printf("\n_______________________________________________");

    do{
        printf("\n\n Enter your choice : ");
        scanf("%d", &choice);
    if(choice == 1){
        printf("\n\n-------------- Regiister an account --------------\n");
        // system("clear");
        printf("Enter your account no : ");
        scanf("%s", usr.ac);
        printf("Enter your phone number : ");
        scanf("%s", usr.phone);
        printf("Enter your password : ");
        scanf("%s", usr.password);
        strcpy(filename, usr.phone); // creat file , name = phn no
        fp = fopen(strcat (filename,".dat"), "w"); // open file
        fwrite(&usr, sizeof (struct user), 1, fp); // write all details
        if (fwrite != 0){
            printf("\n**************** Account Successfully Registered ****************");
        }
        else{
            printf("\n**************** Something went Wrong, Please try again ****************");
        }
        fclose(fp);
    }

    if (choice == 2){
        printf("\n\n-------------- Login to an account --------------\n");
        printf("Enter your account number : ");
        scanf("%s", accountcheck);
        printf("Enter your passwoord : ");
        scanf("%s", passwordcheck);
        strcpy(filename, passwordcheck);
        fp = fopen(strcat(filename, "dat"), "r");
        fread(&usr, sizeof(struct user), 1, fp);
        fclose(fp);
        if (!strcmp(passwordcheck, usr.password) && !strcmp(accountcheck, usr.ac )){ // comparision
            printf("\n************** Accoount loggedin **************");
            printf("\n Details : ");
            printf("\n Account no : %s", usr.ac);
            printf("\n Phone no : %s", usr.phone);
            printf("\n Balance : %0.4f", usr.balance);
            printf("\n\n_______________________________\n\n");
            printf("|   1. For Withdrawell        |\n");
            printf("|   2. For Deposit            |\n");
            printf("|   3. EXIT                   |\n");
            printf("_______________________________\n\n");
            
            do{
                printf("Enter your choice : ");
                scanf("%d", &check);
                if (check == 1){
                    printf("Enter the amount : ");
                    scanf("%f", &withamount);
                    usr.balance = usr.balance - withamount;
                    printf("\n Previous balance : %0.4f", prev);
                    printf("\n Current balance : %0.4f \n", usr.balance);
                    prev = usr.balance;
                }
                else if (check == 2){
                    printf("Enter the amount : ");
                    scanf("%f", &depamount);
                    usr.balance = usr.balance + depamount;
                    printf("\n Previous balance : %f", prev);
                    printf("\n Current balance : %f \n", usr.balance);
                    prev = usr.balance;
                }
            }while(check != 3);
        }
        else{
            if (strcmp(passwordcheck, usr.password)){
                printf("\n******** Invalid Password ********");
            }
            else{
                printf("\n******** Invalid account mo ********");
            }
        }
    }
    }while (choice != 3);
    
    return 0;
}