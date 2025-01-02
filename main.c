#include <stdio.h>
#include "constants.h"
#include "user_structure.h"
#include "functions.h"

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
					printf("User not added\n");
					printf("*****************\n");
					printf("\n\n");
				}
				break;
			case 2:
				int iaccountNumberToSearch = get_account_number();
				struct user *searchedUser = search_user(users, iuserCount, iaccountNumberToSearch);
				display_user_data(searchedUser);
				break;
			case 3:
				int iaccountNumberToDelete = get_account_number();
				int iresult = delete_user(users, iuserCount, iaccountNumberToDelete);
				if(iresult == 1) {
					printf("\n\n");
					printf("*****************\n");
					printf("User deleted\n");
					printf("*****************\n");
					printf("\n\n");
				} else {
					printf("\n\n");
					printf("*****************\n");
					printf("User not deleted\n");
					printf("*****************\n");
					printf("\n\n");
				}
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