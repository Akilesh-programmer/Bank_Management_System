#include "user_structure.h"
#include <stdlib.h>
#include <stdio.h>

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
