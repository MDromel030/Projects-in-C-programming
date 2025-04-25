#include <stdio.h>
#include <string.h>

void create_account();
void deposit_Money();
void withdraw_money();
void check_balance();

const char *ACCOUNT_FILE = "account.dat";

typedef struct
{
    char name[50];
    int acc_number;
    float balance;

} Account;

int main()
{

    while (1)
    {
        int choice;
        printf("\n\nWelcome to **FBA Bank**\n");
        printf("\n1.Create Account");
        printf("\n2.Deposit money");
        printf("\n3.Withddraw Money");
        printf("\n4.Check Balance");
        printf("\n5.Exit");
        printf("\nSlect Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_account();

            break;

        case 2:
            deposit_Money();

            break;

        case 3:
            withdraw_money();

            break;

        case 4:
            check_balance();

            break;

        case 5:
            printf("\nClosing The bank !!Thanks For Your Time!!");
            return 0;
            break;

        default:
            printf("Invalid Choice");
            break;
        }
    }
}
void create_account()
{
    Account acc;
    FILE *file = fopen(ACCOUNT_FILE, "ab+");
    if (file == NULL)
    {
        printf("\n Invalid Activities");
        return;
    }
    char c;
    do
    {
        c = getchar();

    } while (c != '\n' && c != EOF);

    printf("\nEnter Your Name:");

    fgets(acc.name, sizeof(acc.name), stdin);

    int index = strcspn(acc.name, "\n"); // to search |n and make it to null so  that name will be null terminated
    acc.name[index] = '\0';

    printf("\nEnter Your Account Number:");

    scanf("%d", &acc.acc_number);

    acc.balance = 0;

    fwrite(&acc, sizeof(acc), 1, file);

    fclose(file);
    printf("\nAccount  created Succesfully");
}

void deposit_Money()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (file == NULL)
    {
        printf("\n Invalid Activities");
        return;
    }

    int ac_number;
    float amount_money;
    Account acc_to_read;
    printf("\nEnter Your Account Number:");
    scanf("%d", &ac_number);
    printf("\nEnter The Amount to deposit:");
    scanf("%f", &amount_money);

    while (fread(&acc_to_read, sizeof(acc_to_read), 1, file))

    {
        if (acc_to_read.acc_number == ac_number)
        {
            acc_to_read.balance += amount_money;
            fseek(file, -sizeof(acc_to_read), SEEK_CUR); // to move cursor to start from the begining of the amount
            fwrite(&acc_to_read, sizeof(acc_to_read), 1, file);
            fclose(file);
            printf("\nSucccessfully Deposited Bdt %.2f\nNew Balance is %.2f", amount_money, acc_to_read.balance);
            return;
        }
    }
    fclose(file);
    printf("\nMoney Could Not Be Desposited as the Account number %d was not found in Records", ac_number);
}

void withdraw_money()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (file == NULL)
    {
        printf("\n Invalid Activities");
        return;
    }
    int ac_number;
    float amountz_money;
    Account acc_read;
    printf("\nEnter your account nnumber:");
    scanf("%d", &ac_number);
    printf("\nEnter the Amount you want to Withdraw:");
    scanf("%f", &amountz_money);
    while (fread(&acc_read, sizeof(acc_read), 1, file))
    {
        if (acc_read.acc_number == ac_number)
        {
            if (acc_read.balance >= amountz_money)
            {
                acc_read.balance -= amountz_money;
                fseek(file, -sizeof(acc_read), SEEK_CUR);
                fwrite(&acc_read, sizeof(acc_read), 1, file);

                printf("\nSuccessfully Withdrawn BDt%.2f\n Remaining Balance is BDT %.2f", amountz_money, acc_read.balance);
            }
            else
            {
                printf("Insufficient Blanace!!");
            }
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("\nMoney Could Not Be Withdrawn as the Account number %d was not found in Records", ac_number);
}

void check_balance()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (file == NULL)
    {
        printf("\n Invalid Activities");
        return;
    }
    int ac_number;
    Account acc_read;

    printf("Enter Your Account Number: ");
    scanf("%d", &ac_number);
    while (fread(&acc_read, sizeof(acc_read), 1, file))

    {
        if (acc_read.acc_number == ac_number)
        {
            printf("\nYour account balance is %.2f", acc_read.balance);
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("\n Account number:%d was not found", ac_number);
}