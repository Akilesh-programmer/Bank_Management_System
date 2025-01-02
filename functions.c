// Including the required header files
#include "user_structure.h"
#include <stdlib.h>
#include <stdio.h>

/*
    This is a function to add user to the users array, the function will
    return the pointer to the user structure if the user is added successfully,
    otherwise it will return NULL.
*/
struct user *add_user(int iaccountNumber) {
    struct user *newUser = (struct user *)malloc(sizeof(struct user));
    newUser->iaccountNumber = iaccountNumber;

    printf("Enter first name: ");
    scanf("%s", newUser->acFirstName);

    printf("Enter last name: ");
    scanf("%s", newUser->acLastName);

    printf("Enter age: ");
    scanf("%d", &newUser->iage);
    if(newUser->iage<18) {
        printf("User must be 18 years or older\n");
        return NULL;
    }

    printf("Enter phone number: ");
    scanf("%s", newUser->acPhoneNumber);

    printf("Enter email id: ");
    scanf("%s", newUser->acEmailId);

    newUser->dbalance = 0.0;

    printf("\n\n");
    printf("*****************\n");
    printf("User added SUCCESSFULLY\n");
    printf("Account number: %d\n", newUser->iaccountNumber);
    printf("*****************\n");
    printf("\n\n");

    return newUser;
}

/*
    This is a function to search user in the users array, the function will
    return the pointer to the user structure if the user is found successfully,
    otherwise it will return NULL.
*/
struct user *search_user(struct user *users[], int iuserCount, int iaccountNumber) {
    for(int i=0; i<iuserCount; i++) {
        if(users[i]!=NULL && users[i]->iaccountNumber == iaccountNumber) {
            return users[i];
        }
    }
    return NULL;
}


/*
    This is a function to display user data, the function will
    display the user data if the user is found successfully,
    otherwise it will display "User not found".
*/
void display_user_data(struct user *user) {
    if(user == NULL) {
        printf("\n\n");
        printf("***************\n");
        printf("User not found\n");
        printf("***************\n");
        printf("\n\n");
    } else {
        printf("\n\n");
        printf("***************\n");
        printf("User details\n");
        printf("***************\n");
        printf("First name: %s\n", user->acFirstName);
        printf("Last name: %s\n", user->acLastName);
        printf("Age: %d\n", user->iage);
        printf("Phone number: %s\n", user->acPhoneNumber);
        printf("Email id: %s\n", user->acEmailId);
        printf("Account number: %d\n", user->iaccountNumber);
        printf("Balance: %lf\n", user->dbalance);
        printf("***************\n");
        printf("\n\n");
    }
}


/*
    This is a function to free the memory allocated to the users array, the function will
    free the memory allocated to the users array.
*/
void free_users(struct user *users[], int iuserCount) {
    for(int i=0; i<iuserCount; i++) {
        if(users[i] != NULL) {
            free(users[i]);
        }
    }
}


/*
    This is a function to get the user choice, the function will
    return the user choice.
*/
int get_user_choice() {
    int iuserChoice;
    printf("\n\n");
    printf("*****************\n");
    printf("1. Add user\n");
    printf("2. Search user\n");
    printf("3. Delete user\n");
    printf("4. Withdraw\n");
    printf("5. Check Balance\n");
    printf("6. Deposit\n");
    printf("7. Exit\n");
    printf("*****************\n");
    printf("Enter your choice: ");
    scanf("%d", &iuserChoice);
    return iuserChoice;
}


/*
    This is a function to delete user from the users array, the function will
    delete the user from the users array,
*/
int delete_user(struct user *users[], int iuserCount, int iaccountNumber) {
    for(int i=0; i<iuserCount; i++) {
        if(users[i]!=NULL && users[i]->iaccountNumber == iaccountNumber) {
            free(users[i]);
            users[i] = NULL;
            return 1;
        }
    }
    return 0;
}


/*
    This is a function to get the account number, the function will
    return the account number.
*/
int get_account_number() {
    int iaccountNumber;
    printf("Enter account number: ");
    scanf("%d", &iaccountNumber);
    return iaccountNumber;
}


/*
    This is a function to check balance of the user, the function will
    return the balance of the user if the user is found successfully,
    otherwise it will return -1.
*/
double check_balance(struct user *users[], int iuserCount, int iaccountNumber) {
    for(int i=0; i<iuserCount; i++) {
        if(users[i]!=NULL && users[i]->iaccountNumber == iaccountNumber) {
            return users[i]->dbalance;
        }
    }
    return -1;
}


/*
    This is a function to withdraw amount from the user, the function will
    return the balance of the user if the user is found successfully and
    the amount is withdrawn successfully, otherwise it will return -1 if
    the user is found but the amount is insufficient and it will return -2
    if the user is not found.
*/
double withdraw(struct user *users[], int iuserCount, int iaccountNumber, double amount) {
    for(int i=0; i<iuserCount; i++) {
        if(users[i]!=NULL && users[i]->iaccountNumber == iaccountNumber) {
            if(users[i]->dbalance >= amount) {
                users[i]->dbalance -= amount;
                return users[i]->dbalance;
            } else {
                return -1;
            }
        }
    }
    return -2;
}


/*
    This is a function to deposit amount to the user, the function will
    return the balance of the user if the user is found successfully and
    the amount is deposited successfully, otherwise it will return -1 if
    the user is not found.
*/
double deposit(struct user *users[], int iuserCount, int iaccountNumber, double amount) {
    for(int i=0; i<iuserCount; i++) {
        if(users[i]!=NULL && users[i]->iaccountNumber == iaccountNumber) {
            users[i]->dbalance += amount;
            return users[i]->dbalance;
        }
    }
    return -1;
}