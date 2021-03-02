#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct
{
    char *accountHolder, *accountNumber;
    float accountBalance;
} BankAccount;

void readBankAccountDetails(BankAccount *account)
{
    static char _buffer[64];
    static int _bufferUsed;

    printf("Account Holder      : ");
    scanf("%s%n", _buffer, &_bufferUsed);

    account->accountHolder = malloc(sizeof(char) * _bufferUsed);
    strcpy(account->accountHolder, _buffer);

    printf("Account Number      : ");
    scanf("%s%n", _buffer, &_bufferUsed);

    account->accountNumber = malloc(sizeof(char) * _bufferUsed);
    strcpy(account->accountNumber, _buffer);

    printf("Account Balance     : ");
    scanf("%f", &(account->accountBalance));

    printf("\n");
}

void printAccountDetails(const BankAccount *account)
{
    printf("Student : {"
           "\n\t'Account Holder'   : '%s',"
           "\n\t'Account Number'   : %s,"
           "\n\t'Account Balance'  : %f,"
           "\n}\n",
           account->accountHolder, account->accountNumber, account->accountBalance);
}

void forEach(BankAccount *head, int n, void (*delegate)(BankAccount *))
{
    while (n--)
        delegate(head++);
}

void printNameIfBalanceLessThan200(const BankAccount *account)
{
    if (account->accountBalance < 200)
        printf("%s\n", account->accountHolder);
}

void add100ToAllAbove1000AndPrint(BankAccount *account)
{
    if (account->accountBalance > 1000)
    {
        account->accountBalance += 100;
        printAccountDetails(account);
    }
}

int main()
{
    int nAccounts;

    printf("Number of accounts to enter: ");
    scanf("%d", &nAccounts);

    BankAccount *accounts = (BankAccount *)malloc(sizeof(BankAccount) * nAccounts);

    forEach(accounts, nAccounts, readBankAccountDetails);

    printf("Accounts whose balance less than 200$:\n");
    forEach(accounts, nAccounts, printNameIfBalanceLessThan200);

    printf("After adding 100$ to the following accounts:\n");
    forEach(accounts, nAccounts, add100ToAllAbove1000AndPrint);

    return 0;
}
