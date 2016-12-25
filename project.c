#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

void menu(){
          printf("\xB2\xB2\xB2 1 FOR ADD NEW EMPLOYEE     \xB2\xB2\xB2 \n");
          printf("\xB2\xB2\xB2 2 FOR SEARCHING EMPLOYEE   \xB2\xB2\xB2 \n");
          printf("\xB2\xB2\xB2 3 FOR EDIT EMPLOYEE        \xB2\xB2\xB2 \n");
          printf("\xB2\xB2\xB2 4 FOR DELETE EMPLOYEE      \xB2\xB2\xB2 \n");
          printf("\xB2\xB2\xB2 0 FOR EXIT                 \xB2\xB2\xB2 \n");
          printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");

}
void section(){
      system("COLOR 57");
      printf("~~~~~~~~ PLEASE SELECT THE SECTION ~~~~~~~~~\n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
      printf("\xB3 1 FOR DEVELOPMENT SECTION      \xB3 \n");
      printf("\xB3 2 FOR ACCUNTING SECTION        \xB3 \n");
      printf("\xB3 3 FOR MARKETING SECTION        \xB3 \n");
      printf("\xB3 4 FOR HUMAN RESOURCE SECTION   \xB3 \n");
      printf("\xB3 0 FOR BACK TO HOME                     \xB3 \n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");

}

void home(){
    int ch;
        do{
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
              menu();
              scanf("%d",&ch);
              switch(ch){
                case 1:{
                     printf("@@@@@@@@ YOU ARE GOING TO ADD EMPLOYEE @@@@@@@@@\n \n");
                    caseone();
                }
                case 0:exit(0);
              }
          }
          while(ch != 0);
}



void caseone(){
    int sec;
    do{
        section();
          scanf("%d",&sec);
          switch(sec){
            case 1:{
                printf(">>>>>>> YOU HAVE SELECTED DEVELOPMENT SECTION <<<<<<<<\n");
                development();
                break;
            }
            case 2:{
                printf(">>>>>>> YOU HAVE SELECTED ACCOUNTING SECTION <<<<<<<<\n");
                accounting();
                break;
            }
            case 3:{
                printf(">>>>>>> YOU HAVE SELECTED MARKETING SECTION <<<<<<<<\n");
                marketing();
                break;
            }
            case 4:{
                printf(">>>>>>> YOU HAVE SELECTED HUMANRESOURCE SECTION <<<<<<<<\n");
                human();
                break;
            }
            case 0:home();
          }
        }

        while(sec != 0);
}

int sucess(){
    char y[5]= "y";
    char yes[5];
    int cmp;
    printf("********** DATA INSERTED SUCESSFULLY ********* \n");
    printf("********** DO YOU WANT TO ADD MORE DATA ? ********* \n");
    printf("PRESS y IF YES -- PRESS n IF NOT \n");
    scanf("%s",&yes);
    cmp = strcmp(y,yes);
    if(cmp == 0){
       return 0;
    }
    else{
        return 1;
    }
}

void add(FILE *fd){
    int back;
    char name[25];
    char title[25];
    int sal;
    char email[35];
    char phon[15];
    printf("*** WRITE 'back' TO GO SELECTION MENU *** \n");
    printf("*** EMPLOYEE NAME *** \n");
    scanf("%s",&name);
    back = strcmp(name,"back");
    if(back == 0){
      caseone();
    }
    printf("*** EMPLOYEE TITLE *** \n");
    scanf("%s",&title);
    back = strcmp(title,"back");
    if(back == 0){
      caseone();
    }
    printf("*** EMPLOYEE SALARRY *** \n");
    scanf("%d",&sal);
    back = strcmp(title,"back");
    if(back == 0){
      caseone();
    }

    printf("*** WRITE 'back' TO GO SELECTION MENU *** \n");
    printf("*** EMPLOYEE PHONE *** \n");
    scanf("%s",&phon);
    back = strcmp(phon,"back");
    if(back == 0){
      caseone();
    }
    printf("*** EMPLOYEE EMAIL *** \n");
    scanf("%s",&email);
    back = strcmp(email,"back");
    if(back == 0){
      caseone();
    }
    fprintf(fd,"%s   %s  %d   %s   %s \n",name,title,sal,email,phon);
    fclose(fd);

}

void development(){
    int res,data;
    FILE *fd;
    fd = fopen("Development.txt","a");
    add(fd);
    res = sucess();
    if(res == 0){
       printf("PRESS 1 FOR ADDING THIS SELECTED SECTION \n");
       printf("PRESS 0 FOR GO BACK TO OTHER SECTION \n");
       scanf("%d",&data);
       if(data == 1){
          development();
       }
       else{
            caseone();
       }
    }
    else{
        home();
    }
}
void accounting(){
    int ares,data;
    FILE *fd;
    fd = fopen("Accounting.txt","a");
    add(fd);
    ares = sucess();
    if(ares == 0){
       printf("PRESS 1 FOR ADDING THIS SELECTED SECTION \n");
       printf("PRESS 0 FOR GO BACK TO OTHER SECTION \n");
       scanf("%d",&data);
       if(data == 1){
          accounting();
       }
       else{
            caseone();
       }
    }
    else{
        home();
    }
}
void marketing(){
    int mres,data;
    FILE *fm;
    fm = fopen("Marketing.txt","a");
    add(fm);
    mres = sucess();
    if(mres == 0){
       printf("PRESS 1 FOR ADDING THIS SELECTED SECTION \n");
       printf("PRESS 0 FOR GO BACK TO OTHER SECTION \n");
       scanf("%d",&data);
       if(data == 1){
          marketing();
       }
       else{
            caseone();
       }
    }
    else{
        home();
    }
}
void human(){
    int fres,data;
    FILE *fh;
    fh = fopen("Human.txt","a");
    add(fh);
    fres = sucess();
    if(fres == 0){
       printf("PRESS 1 FOR ADDING THIS SELECTED SECTION \n");
       printf("PRESS 0 FOR GO BACK TO OTHER SECTION \n");
       scanf("%d",&data);
       if(data == 1){
          human();
       }
       else{
            caseone();
       }
    }
    else{
        home();
    }
}



int main(){
    int s = 0;
    system("COLOR 57");
    int pass;
    printf("********* WELCOME TO HI-TECH SOFTWORE SOLUTION ************ \n");
    printf("~~~~~~~~ PLEASE ENTER YOUR PASSWORD ~~~~~~~~~\n");
    scanf("%d",&pass);
    if(pass == 12){
        home();
    }
    else{
        printf("Password isn't correct ");
    }

}








