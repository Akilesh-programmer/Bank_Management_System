// Including the required header files
#include <stdio.h>
#include "constants.h"
#include "user_structure.h"
#include "functions.h"

int main() {

	// Array of pointers to the user structures
	struct user *users[MAX_USERS] = {NULL};
	int iuserCount = 0;

	/*
		Getting user choice continuously until the user chooses to exit.
		Until then based on the user choice, the respective function will be called.
	*/
	int iuserChoice = TRUE;
	int iaccountNumberToSearch;
	int iaccountNumberToDelete;
	int iresult;
	int iaccountNumberToWithdraw;
	double iamount;
	double iwithdrawResult;
	int iaccountNumberToCheckBalance;
	double dBalance;
	int iaccountNumberToDeposit;
	double ddepositAmount;



	while(iuserChoice) {
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
				iaccountNumberToSearch = get_account_number();
				struct user *searchedUser = search_user(users, iuserCount, iaccountNumberToSearch);
				display_user_data(searchedUser);
				break;
			case 3:
				iaccountNumberToDelete = get_account_number();
				iresult = delete_user(users, iuserCount, iaccountNumberToDelete);
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
				iaccountNumberToWithdraw = get_account_number();
				iamount = 0;
				printf("Enter amount to withdraw: ");
				scanf("%lf", &iamount);
				iwithdrawResult = withdraw(users, iuserCount, iaccountNumberToWithdraw, iamount);
				if(iwithdrawResult != -1 && iwithdrawResult != -2) {
					printf("\n\n");
					printf("*****************\n");
					printf("Withdrawn amount: %lf\n", iamount);
					printf("Amount Remaining: %lf\n", iwithdrawResult);
					printf("*****************\n");
					printf("\n\n");
				} else if(iwithdrawResult == -2) {
					printf("\n\n");
					printf("*****************\n");
					printf("User not found\n");
					printf("*****************\n");
					printf("\n\n");
				} else {
					printf("\n\n");
					printf("*****************\n");
					printf("Insufficient balance\n");
					printf("*****************\n");
					printf("\n\n");
				}
				break;
			case 5:
				iaccountNumberToCheckBalance = get_account_number();
				dBalance = check_balance(users, iuserCount, iaccountNumberToCheckBalance);
				if(dBalance != -1) {
					printf("\n\n");
					printf("*****************\n");
					printf("Balance: %lf\n", dBalance);
					printf("*****************\n");
					printf("\n\n");
				} else {
					printf("\n\n");
					printf("*****************\n");
					printf("User not found\n");
					printf("*****************\n");
					printf("\n\n");
				}
				break;
			case 6:
				iaccountNumberToDeposit = get_account_number();
				ddepositAmount = 0;
				printf("Enter amount to deposit: ");
				scanf("%lf", &ddepositAmount);
				double ddepositResult = deposit(users, iuserCount, iaccountNumberToDeposit, ddepositAmount);
				if(ddepositResult != -1) {
					printf("\n\n");
					printf("*****************\n");
					printf("Amount deposited: %lf\n", ddepositResult);
					printf("*****************\n");
					printf("\n\n");
				} else {
					printf("\n\n");
					printf("*****************\n");
					printf("User not found\n");
					printf("*****************\n");
					printf("\n\n");
				}
				break;
			case 7:
				iuserChoice = FALSE;
				break;
			default:
				printf("\n\n");
				printf("**************\n");
				printf("Invalid choice\n");
				printf("**************\n");
				printf("\n\n");
		}
	}

	printf("\n\n");
	printf("***********************************\n");
	printf("Thank you for using the application\n");
	printf("***********************************\n");

	// Free the memory allocated to the users
	free_users(users, iuserCount);

	return 0;
}