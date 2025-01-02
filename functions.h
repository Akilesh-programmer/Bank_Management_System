struct user *add_user(int iaccountNumber);
struct user *search_user(struct user *users[], int iuserCount, int iaccountNumber);
void display_user_data(struct user *user);
void free_users(struct user *users[], int iuserCount);
int get_user_choice();
int delete_user(struct user *users[], int iuserCount, int iaccountNumber);
int get_account_number();
double check_balance(struct user *users[], int iuserCount, int iaccountNumber);
double withdraw(struct user *users[], int iuserCount, int iaccountNumber, double amount);