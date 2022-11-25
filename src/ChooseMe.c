/*
this program is a login and signup system 
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h> 
#include<stdbool.h>
#include<stdlib.h>

int k = 0,c = 0 ,C = 0;
      // this is for using strlwr
char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;
                                            // this is to define stlwr for clang compilers 
while (*p) {
        *p = tolower((unsigned char)*p);
        p++;
}

return str;
}
int security(int );
int output(int );
int wrong(int ,int );
void change(int id,int counter ,int total_amount);
void sign_up(int,int  );
void sign_in(int,int );
void login();
int zak(int id,int counter);

    char min;
    int tempo;
    char temp [50];
    char new_lname[100],new_fname[100], new_password[50], new_email[100], new_bankaccount[30],question[100],new_reply[100];
    int  new_balance;
    char address[30];
    char passcode[30]; // this is the the arrays that we are using to compare with 
    char email[50][50];
    char fname[50][50];
    char lname[50][50];
    char password[50][50];
    char bank_account[50][50];
    int  balance[100]={0};
    char secret_question[50][50];
    char reply[50][50];
    char sign[10];
    
int main(){
    int i  = 0,user = 0,count = 0;
    int id,found=0; // found is a sentinal value
    // id is to keep track of the persons that we have 

    FILE *outpute;
    outpute = fopen("output.txt","r");
     if (!outpute ) // equivalent to saying if ( in_file == NULL ) 
            {  
                printf("oops, file can't be read\n"); 
                FILE *file;
                file =fopen("database.txt","r"); 
                while (!feof(file))
                { 
                fscanf(file, "%s %s %s %s %s %d %s %s\n" , email[i],fname[i],lname[i],password[i],bank_account[i],
                &balance[i],secret_question[i],reply[i]);
                i++;
                user++;
                count++;
                }
                fclose(file);
                fclose(outpute);
                
            }
    else {             
        
                        FILE *output;
                        output = fopen("output.txt","r");
                        while (!feof(output))
                        { 
                                fscanf(output, "%s %s %s %s %s %d %s %s\n" , email[i],fname[i],lname[i],password[i],bank_account[i],
                                &balance[i],secret_question[i],reply[i]);
                                i++;
                                count++;
                        }fclose(output);
        }
    
    printf("This is a login in menu\n");
   
    
    
    printf("----------------------------------------------------------------------------------------------------------\n");
    strcpy(sign,"sign in");
if (strcmp(sign,"sign in")==0)
{   
    sign_in(count,user);
    
}
else if(strcmp(sign,"sign up")==0){
    sign_up(count,user);
}
    FILE *outputee;
    outputee = fopen("output.txt", "r");
    while(!feof(outputee))
    {
    fscanf(outputee,"%s %s %s %s %s %d %s %s \n",email[i],fname[i],lname[i],password[i],bank_account[i],&balance[i],secret_question[i],reply[i]);
    }
    fclose(outputee);


return 0;
}


int zak(int id,int counter)
{
    int  total_amount=0;
    int  amount[5]={0},result[5]={0};
    char word[8];
    char answer[]={"yes"},choice[10];
    char menu[5][20]={{"Book"}
        ,{"Skin Care"}
        ,{"Watch"}
        ,{"Desk"}
        ,{"Laptop"}
    };
    int price[5]={200,700,1000,4000,6000};
printf("Welcome, if you want to make an order, type 'order'; if you want to change your information,type 'change' or do you want to delete your account 'delete': \n");
    scanf("%s",word);
        if(strcmp(word,"order") == 0){
            printf("Here is the menu:\n");
            for(int i=0;i<5;i++){
                printf("%s for %d MAD\t",menu[i],price[i]);
            }
            while(strcmp(answer,"yes")==0){
                printf("\nType what you want to buy based on the menu: ");
                getchar();
                gets(choice);
                for(int i=0;i<7;i++){
                tolower(choice[i]);
                }
                if(strcmp(choice,"book")==0){
                    printf("How many books do you want? ");
                    scanf("%d",&amount[0]);
                    result[0]=amount[0]*200;
                }
                else if(strcmp(choice,"skin care")==0){
                    printf("How many skin care do you want? ");
                    scanf("%d",&amount[1]);
                    result[1]=amount[1]*700;
                }
                else if(strcmp(choice,"watch")==0){
                    printf("How many watches do you want? ");
                    scanf("%d",&amount[2]);
                    result[2]=amount[2]*1000;
                }
                else if(strcmp(choice,"desk")==0){
                    printf("How many desks do you want? ");
                    scanf("%d",&amount[3]);
                    result[3]=amount[3]*4000;
                }
                else if(strcmp(choice,"laptop")==0){
                    printf("How many laptops do you want? ");
                    scanf("%d",&amount[4]);
                    result[4]=amount[4]*6000;
                }
             for(int i=0;i<5;i++){
            total_amount+=result[i];   
            }
                printf("\nDo you want to order anything else(type yes), or do you want to proceed to the payment?(type payment)");
                scanf("%s",answer);
            }
            printf("\nThese items have been added to your cart.");
            printf("\nThe total amount to pay is %d MAD",total_amount);
            if(balance[id]>total_amount){
                balance[id]-=total_amount;
                printf("\nCongrats %s you have purchased this item you still have %d MAD\n",fname[id],balance[id]);   
                printf("\nDo you want to log out? yes or no ");
                scanf("%s",answer);
                if(strcmp(answer,"no")==0){
                    zak(id,counter);
                }
                else if(strcmp(answer,"yes")==0){
                    
                    output(counter);
                    printf("You have been logged out");
                    return 0;
                }
                else if(strcmp(answer,"payment")==0){
                    printf("\nDo you want to order anything else(type yes), or do you want to proceed to the payment?(type no)");
                    scanf("%s",answer);
                    zak(id,counter);
                }
                
                }
                
            else if(balance[id]<total_amount){
                printf("\nYou do not have enough balance consider change your bank info type 'change' to continue\n");
                scanf("%s",answer);
                if(strcmp(answer,"yes")){
                    change(id,counter,total_amount);
                }
                
            }
        }
    if(strcmp(word,"change")==0){
    for(int j=3;j>0;j--){
    printf("Type your password: ");
    scanf("%s",passcode);
    if(strcmp(password[id],passcode)==0){
    int number;
    printf("Your email : %s \n Your first name: %s\n Your last name: %s \nYour password: %s\n Your bank account: %s\n Your balance: %d\n Your secret question: %s\n Your answer: %s" , email[id],fname[id],lname[id],password[id],bank_account[id],
    balance[id],secret_question[id],reply[id]);
    printf("\nIf you want to change your first name press 1, press 2 for last name, press 3 for email, press 4 for bank account");
    scanf("%d",&number);
    if(number==1){
        printf("\nType a first name: ");
        scanf("%s",fname[id]);
    }
    else if(number==2){
        printf("\nType a last name: ");
        scanf("%s",lname[id]);
    }
    else if(number==3){
        printf("\nType a new email: ");
        scanf("%s",email[id]);
    }
    else if(number==4){
        printf("\nType a bank account: ");
        scanf("%s",bank_account[id]);
        printf("What is the balance: ");
        scanf("%d",&balance[id]);
    }
    
    printf("Information saved, please log in again");
    output(counter);
    break;
    }
    else 
    printf("Wrong password, try again you still have %d times\n",j);
    }
}
else if(strcmp(word,"delete")==0){
    char temp[50];
    printf("Type your password: ");
    scanf("%s",passcode);
    if(strcmp(password[id],passcode)==0){
   /* FILE *file,*temp;
    char buffer[1024];
    int delete_line=0;

    delete_line=id+1;
    file=fopen("output.txt","r");
    temp=fopen("temp_database.txt","w");
bool keep_reading = true;
int current_line = 1;
do{
    fgets(buffer,1024,file);
    if(feof(file)) keep_reading=false;
    else if(current_line!=delete_line)
    fputs(buffer,temp);
    current_line++;
}
while(keep_reading);
fclose(file);
fclose(temp);
for(;;){
remove("output.txt");
rename("temp_database.txt","output.txt");
printf("Account deleted successfully");

*/
int found = 0,c,element,n,pos;
for (c= id ; c < counter - 1 ; c++)
{
   strcpy( fname[c] , fname[c + 1]);
    strcpy(lname[c] , lname[c + 1]);
    strcpy(email [c] , email[c + 1]);
    strcpy(password[c] , password[c + 1]);
    strcpy(secret_question[c] , secret_question[c+1]);
    strcpy(reply[c] , reply[c + 1]);
    strcpy(bank_account[c] , bank_account[c + 1]);
    balance[c] = balance[c + 1];

}

    counter = counter - 1;
    output(counter);

}

else {
    printf("\nWrong password you have been logged out");
    output(counter);
}
}
}


void sign_up(int count,int c){
	int B = 0;
    int flag = 0;	
    printf("Enter Your First Name\t");
    scanf("%s", new_fname);
    printf("Enter Your last Name\t");
    scanf("%s", new_lname);
    printf("Enter Your Password\t");
    scanf("%s", new_password);
    printf("Enter Your Email\t");
    scanf("%s", new_email);
    printf("Enter Bank Account Number \t");
    scanf("%s", new_bankaccount);
    printf("What is your balance ? \t");
    scanf("%d",&new_balance);
    printf("Enter the secret question \t");
    scanf("%s",question);
    printf("Enter an answer: \t");
    scanf("%s",new_reply);
    int j;
    j = count + 1;
    for(int i=0;i<j ;i++){
        if (strcmp(new_email,email[i])==0 || strcmp(new_bankaccount,bank_account[i])==0)//checks with the arrays if the arrays
        {
        printf("\nYou already have an existant account, Please login");
        sign_in(count,c);
        }

    }
/* else if(strcmp(new_email,email[i])!=0 && strcmp(new_bankaccount,bank_account[i])!=0)*/
       
      
       if(flag == 0){

    
       strcpy(fname[count],new_fname);
       strcpy(lname[count],new_lname);
       strcpy(email[count],new_email);
       strcpy(bank_account[count],new_bankaccount);
       balance[count] = new_balance;
       strcpy(secret_question[count],question);
       strcpy(reply[count],new_reply);
       strcpy(password[count],new_password);

       } 
        

        

        
        printf("\nLog in again");
        count = count + 1;
        sign_in(count,c);
    }
        


void sign_in(int count,int c)
{
    int  id,found=0;
printf("\nEnter your email: ");
    scanf("%s",address);
    int j;
    j = count + 1;
    for( int i = 0 ; i < j; i++)
    {
    	        if(strcmp(email[i],address)==0)
    			{
						found = 1;
                        id = i;
    			}
                
    }
    if (found == 1)
    {
				security(id);
				zak(id,count);
    		    }
    else if(found == 0)
    		{
            printf("User does not exist!\t Sign up\n");
            sign_up(count,c);
    		}
}

void change(int id,int counter,int total_amount){
    for(int j=0;j<3;j++){
    printf("\nType a bank account: ");
    scanf("%s",bank_account[id]);
    printf("What is the balance: ");
    scanf("%d",&balance[id]);
    if(balance[id]<total_amount){
        printf("\nNot enough balance");
    }
    if(balance[id]<total_amount && j==2){
        printf("\nThe order will be dropped and you will be logged out");
        output(counter);
        break;
    }
    else if (balance[id]>total_amount){

    balance[id]-=total_amount;

    char answer[9];
    
    printf("\nCongrats %s you have purchased this item you still have %d MAD\n",fname[id],balance[id]);
    printf("do you want to log out yes or no ? ");
    scanf("%s",answer);
    if(strcmp(answer,"yes")==0){ 
    output(counter);
    break;
    }
    else if(strcmp(answer,"no")==0){
        zak(id,counter);
    }
    }
    }
}

int output(int counter)
{ 
int flag = 0;
 if (counter == 3){
    flag = 1;
}
else {
     flag = 0;
}
    int tempo;
    char temp [50];
    
    
    
    for(int z=0;z<counter+2;z++)
    
    {
    for (int i = 0; i < counter; i++)
    {
        for (int j = i + 1; j < counter; j++)
        {

            if (strcmp (lname[i] , lname[j]) > 0)  
            {

                strcpy(temp, lname[i]);
                strcpy(lname[i], lname[j]);
                strcpy(lname[j], temp);
            
            
                strcpy(temp ,  fname[i] );
                strcpy(fname[i] , fname[j] );
                strcpy(fname[j] , temp );



                strcpy(temp ,  email[i] );
                strcpy(  email[i] , email[j]);
                strcpy(  email[j] , temp);




                strcpy(  temp ,  password[i]);
                strcpy( password[i] , password[j] );
                strcpy( password[j] , temp);


                strcpy( temp ,  bank_account[i] );
                strcpy( bank_account[i] , bank_account[j]);
                strcpy( bank_account[j] , temp );



                tempo =  balance[i];
                balance[i] = balance[j];
                balance[j] = tempo;


                strcpy(temp ,  secret_question[i]);
                strcpy(secret_question[i] , secret_question[j]);
                strcpy(secret_question[j] , temp );


                strcpy(temp ,  reply[i] );
                strcpy(reply[i] , reply[j] );
                strcpy(reply[j] , temp );
            }
        }
    }
}
if (flag == 1){

FILE *output;
    output = fopen("output.txt", "w");

    for (int i = 0; i < 3; i++)
    {
        fprintf(output,"%s %s %s %s %s %d %s %s\n",email[i],fname[i],lname[i],password[i],bank_account[i],
    balance[i],secret_question[i],reply[i]);
    }
    fclose(output);
    return 0;
}
else if(flag == 0){
    
    FILE *output;
    output = fopen("output.txt", "w");
    for (int i = 0; i < counter; i++)
    {
        fprintf(output,"%s %s %s %s %s %d %s %s\n",email[i],fname[i],lname[i],password[i],bank_account[i],
    balance[i],secret_question[i],reply[i]);
    }
    fclose(output);
    return 0;
}
return 0 ;
}


int security(int id){
    char jawab[100];
    int x,flag=0;
            printf("Enter a password ");
            scanf("%s",passcode);
            for(int i=0;i<strlen(password[id]);i++){
                if(passcode[i]!=password[id][i]){
                    if(passcode[i]==password[id][i-1] || passcode[i]==password[id][i+1]){
                    flag=1;
                    }
                    else
                    flag=-1;
                }
                }
            if(strcmp(passcode,password[id])==0){
                printf("Succesfully logged in! \n");
                return 0;
            }
            else if(flag==1){
                printf("security question\n");
                printf("%s",secret_question[id]);
                scanf("%s",jawab);
                if(strcmp(jawab,reply[id])==0){
                    printf("Logged in\n");
                    return 0;
                }
                else 
                for(;;){
                printf("Wrong\n");
                break;
                }
            }
            else
                printf("the password is wrong");
            
        return 0;
}