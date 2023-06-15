#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user {
    char name[50];
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};

int main(){
    struct user usr,usr1;
    FILE *fp;
    char filename[50],phone[50],pword[50], ac[50];
    int opt,choice;
    char cont = 'y';
    float amount;

    printf("\nWhat do you want to do?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account");

    printf("\n\nYour choice:\t");
    scanf("%d",&opt);

    if(opt == 1){
        system("cls");
        printf("Enter your name:\t");
        scanf("%[^\n]",usr.name);
        printf("Enter your account number:\t");
        scanf("%s",usr.ac);
        printf("Enter your phone number:\t");
        scanf("%s",usr.phone);
        printf("Enter your new password:\t");
        scanf("%s",usr.password);
        usr.balance = 0;
        strcpy(filename,usr.ac);
        fp = fopen(strcat(filename,".dat"),"w");
        fwrite(&usr,sizeof(struct user),1,fp);
        if(fwrite != 0){
            printf("\n\nAccount succesfully registered");
        }else {
            printf("\n\nSomething went wrong please try again");
        }
        fclose(fp);
    }
    if(opt == 2){
        system("clear");
        printf("\nPhone number:\t");
        scanf("%s",ac);
        printf("Password:\t");
        scanf("%s",pword);
        strcpy(filename,phone);
        fp = fopen(strcat(filename,".dat"),"r");
        if(fp == NULL){
            printf("\nAccount number not registered");
        }
        else {
        fread(&usr,sizeof(struct user),1,fp);
        fclose(fp);
        if(!strcmp(pword,usr.password)){
            printf("\n\t\tWelcome %s",usr.name);;
            while(cont == 'y'){
                system("clear");
                printf("\n1.Balance check");
                printf("\n2.Deposit money");
                printf("\n3.Withdraw money");
                printf("\n4.Transfer money");
                printf("\n5.Change password");
                printf("\n\nEnter your choice:\t");
                scanf("%d",&choice);

                switch(choice){
                    case 1:
                        printf("\nYour current balance is %.2f Tk\n",usr.balance);
                        break;
                    case 2:
                        printf("\nEnter the amount:\t");
                        scanf("%f",&amount);
                        usr.balance += amount;
                        fp = fopen(filename,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL) printf("\nSuccesfully deposited.");
                        fclose(fp);
                        break;
                    case 3:
                        printf("\nEnter the amount:\t");
                        scanf("%f",&amount);
                        usr.balance -= amount;
                        fp = fopen(filename,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL) printf("\nYou have withdrawn Rs.%.2f",amount);
                        fclose(fp);
                        break;

                    case 4:
                        printf("\nPlease enter the phone number to transfer the balance:\t");
                        scanf("%s",phone);
                        printf("\nPlease enter the amount to transfer:\t");
                        scanf("%f",&amount);
                        strcpy(filename,phone);
                        fp = fopen(strcat(filename,".dat"),"r");
                        if(fp == NULL) printf("\nAccount number not registered");
                        else {
                            fread(&usr1,sizeof(struct user),1,fp);

                        fclose(fp);
                        if(amount > usr.balance) printf("\nInsufficient balance");
                        else {


                            fp = fopen(filename,"w");
                            usr1.balance += amount;
                            fwrite(&usr1,sizeof(struct user),1,fp);

                            fclose(fp);
                            if(fwrite != NULL){
                                printf("\nYou have succesfully transfered Rs.%.2f to %s",amount,phone);
                                strcpy(filename,usr.phone);
                                fp = fopen(strcat(filename,".dat"),"w");
                                usr.balance -= amount;
                                fwrite(&usr,sizeof(struct user),1,fp);
                                fclose(fp);
                            }


                        }
                        break;
                 case 5:
                        printf("\nPlease enter your new password:\t");
                        scanf("%s",pword);
                        fp = fopen(filename,"w");
                        strcpy(usr.password,pword);
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL)
                        printf("\nPassword succesfully changed");
                        }
                    break;
                default:
                    printf("\nInvalid option");
                }


                printf("\nDo you want to continue the transaction [y/n]\t");
                scanf("%s",&cont);

            }
        }
        else {
            printf("\nInvalid password");
        }
        }

    }


    return 0;
}
