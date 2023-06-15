#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user {
    char name[50];
    char phone[50];
    char ac[50];
    char password[50];
    double balance;
};


int main(){
    struct user usr,usr1;
    FILE *fp;
    char filename[50],phone[50],pword[50], ac[50], nver[50], phonever[50], nac[50];
    int opt,choice, t;
    int count=0;
    char cont = 'y';
    float amount;
    printf("\n\n\n\t\t\t\tWelcome to Maze Bank");
    printf("\nWhat do you want to do?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account");

    printf("\n\nYour choice:\t");
    scanf("%d",&opt);

    if(opt == 1){
        system("cls");
        printf("Enter your name:\t");
        scanf(" %[^\n]",usr.name);
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
        system("cls");
        printf("\nAccount number:\t");
        scanf("%s",ac);
        printf("Password:\t");
        scanf("%s",pword);
        strcpy(filename,ac);
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
                system("cls");
                printf("\n1.Balance check");
                printf("\n2.Deposit money");
                printf("\n3.Withdraw money");
                printf("\n4.Transfer money");
                printf("\n5.Change password");
                printf("\n6.Account details");
                printf("\n\nEnter your choice:\t");
                scanf("%d",&choice);

                switch(choice){

                    case 1:
                        system("cls");
                        printf("\nYour current balance is %.2lf Tk\n",usr.balance);
                        break;
                    case 2:
                        system("cls");
                        printf("\nEnter the amount:\t");
                        scanf("%f",&amount);
                        usr.balance += amount;
                        fp = fopen(filename,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL) printf("\nSuccesfully deposited.");
                        fclose(fp);
                        break;
                    case 3:
                        system("cls");
                        printf("\nEnter the amount:\t");
                        scanf("%f",&amount);
                        usr.balance -= amount;
                        fp = fopen(filename,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL) printf("\nYou have withdrawn %.2f Tk",amount);
                        fclose(fp);
                        break;

                    case 4:
                        system("cls");
                        printf("\nPlease enter the account number to transfer the balance:\t");
                        scanf("%s",ac);
                        printf("\nPlease enter the amount to transfer:\t");
                        scanf("%f",&amount);
                        strcpy(filename,ac);
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
                                printf("\nYou have succesfully transfered %.2f Tk to %s",amount,ac);
                                strcpy(filename,usr.ac);
                                fp = fopen(strcat(filename,".dat"),"w");
                                usr.balance -= amount;
                                fwrite(&usr,sizeof(struct user),1,fp);
                                fclose(fp);
                            }


                        }
                        break;
                 case 5:
                     system("cls");
                        printf("\nPlease enter your new password:\t");
                        scanf("%s",pword);
                        fp = fopen(filename,"w");
                        strcpy(usr.password,pword);
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL)
                        printf("\nPassword succesfully changed");
                        }
                    break;
                 case 6:
                     system("cls");
                    printf("Account number: %s", usr.ac);
                    printf("\nYour name: %s", usr.name);
                    printf("\nPhone number: %s", usr.phone);
                    printf("\nCurrent balance: %.2lf", usr.balance);
                   break;
                default:
                    printf("\nInvalid option");
                }


                printf("\nDo you want to continue the transaction [y/n]\t");
                scanf("%s",&cont);

            }
            while (cont == 'n'){
                printf("Thank you for your time.\n");
                printf("Press any key to close the software.\n");
            }
        }
        else {
            printf("\nInvalid password\n");
            printf("1.Reset password\n");
            printf("2.Exit\n");
            scanf("%d", &t);
            if(t==1){
                    system("cls");
            printf("\nAccount number:\t");
            scanf("%s",nac);
            if(!strcmp(nac,usr.ac)){
                printf("Enter your name:\t");
                scanf(" %[^\n]", &nver);
                if(!strcmp(nver,usr.name)){
                            printf("Enter your phone number:\t");
                            scanf("%s",phonever);
                    if(!strcmp(phonever,usr.phone)){
                        system("cls");
                        printf("\nPlease enter your new password:\t");
                        scanf("%s",pword);
                        fp = fopen(filename,"w");
                        strcpy(usr.password,pword);
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL){
                        printf("\nPassword succesfully changed");
                        }

                    }
                }
            }
            if(t==2){
                    system("cls");
                printf("Press any key to close the software\n");
            }
          }
        }

        }
        }



    return 0;
}
