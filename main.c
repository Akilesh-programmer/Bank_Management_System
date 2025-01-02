#include <stdio.h>
#include "constants.h"
#include "user_structure.h"
#include "functions.h"

int get_user_choice();
void free_users(struct user *users[], int iuserCount);

int main() {

	struct user *users[MAX_USERS] = {NULL};
	int iuserCount = 0;

	int iuserChoice;
	do {
		iuserChoice = get_user_choice();

		switch(iuserChoice) {
			case 1:
				users[iuserCount] = add_user(iuserCount);
				if(users[iuserCount] != NULL) {
					iuserCount++;
				} else {
					printf("\n\n");
					printf("*****************\n");
					printf("User not added\n");
					printf("*****************\n");
					printf("\n\n");
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			default:
				printf("\n\n");
				printf("**************\n");
				printf("Invalid choice\n");
				printf("**************\n");
				printf("\n\n");
		}
	} while(iuserChoice != 7);

	printf("\n\n");
	printf("***********************************\n");
	printf("Thank you for using the application\n");
	printf("***********************************\n");

	free_users(users, iuserCount);
	
	return 0;
}

int get_user_choice() {
	int ichoice;
	printf("1. Add user\n");
	printf("2. Search user\n");
	printf("3. Delete user\n");
	printf("4. Check balance\n");
	printf("5. Deposit\n");
	printf("6. Withdraw\n");
	printf("7. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &ichoice);
	return ichoice;
}

void free_users(struct user *users[], int iuserCount) {
	for(int i=0; i<iuserCount; i++) {
		free(users[i]);
	}
}
