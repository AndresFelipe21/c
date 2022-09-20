#include <stdio.h>

void deposit();
void withdrawal();
void balance();

int validate(int account_numb_temp, int passwd_temp); //VALIDA LOS PARAMETROS
int i,x;
int account_numb_temp;
int amount_temp;
int passwd_temp;

struct account_details
{
    int account_no;
    int password;
    int amount;
};

struct account_details s[3]={(12343432,1234,0), (12343432,5678,0), (89877182,1098,0)}; CADA PARENTESIS ES UN CLIENTE, SU INFORMACION POR CADA UNO GUARDA TRES DATOS

int main()
{
    while(1)
    {
        int choice;
        printf("\n---ATM MACHINE---\n");
        printf("1. DEPOSIT\n2. WITHDRAWAL\n3. BALANCE ENQUIRY\n4. EXIT\nEnter Your Choice\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                deposit();
                break;
            }
            case 2:
            {
                withdrawal();
                break;
            }
            case 3:
            {
                balance();
                break;
            }
            case 4:
            {
                exit(1);
            }
            default:
                printf("Enter a Valid choice\n");
        }
    }
}

void withdrawal()
{
    printf("\nEnter the account number\t"); //PRINT SIEMPREN VA CON SU SCANF EN ORDEN
    scanf("%d", &account_numb_temp);
    
    printf("\nEnter the password\t");
    scanf("%d", &passwd_temp);
    
    printf("\nEnter the amount to withdrawal\t");
    scanf("%d", &amount_temp);
    
    x = validate(account_numb_temp, passwd_temp); // VALIDAR ES UN METODO QUE COMPARA LOS VALORES DEL USUARIO CON LO QUE HAY EN LA BASE DE DATOS SE GUARDA ADEMAS EN LA VARIABLE x QUE COMPARA LA POSICION DE CADA CLIENTE
    
    if(s[x].amount<amount_temp)
    {
        printf("\nUnable to withdrawal from your amount. Your balance is lower");
    }
}

int validate(int account_numb_temp, int passwd_temp) //VARIABLE QUE NOMBRO Y COMPARO EN EL CICLO FOR DE ABAJO

{
    for(i=0;i<3;i++) // MIENTRAS i SEA MENOR O IGUAL QUE TRES INCREMENTA 1
    {
        if(s[i].account_no==account_numb_temp) //SE EJECUTA MIENTRAS LA CONDICION DE ARRIBA SE CUMPLA- IF (CONDICION) //cOMPARACION DEL NUMERO DE CUENTA
        {
            if(s[i].password==passwd_temp) //cOMPARACION DE LA CLAVE DE CUENTA
            {
                return i; //retorna la posicion si esto se cumple
                break;
            }
            else //SI NO SE CUMPLE IMPRIME ESTO (SI LA CUENTA NO EXISTE)
            {
                printf("\nPassword Mismatch");
                exit(1);
            }
        }
        if(i==2)
        {
            printf("\nAccount doesn't exist");
            exit(1);
        }
    }
}
void balance ()
{
    printf("\nEnter the account number\t");
    scanf("%d", &account_numb_temp);
    
    printf("\nEnter the amount to deposit\t");
    scanf("%d", &amount_temp);
    
    printf("\nEnter the password\t");
    scanf("%d", &passwd_temp);
    
    x=validate(account_numb_temp, passwd_temp);
    
    s[x].amount+=amount_temp;
    
    printf("\nRs:%d is successfully")
}
