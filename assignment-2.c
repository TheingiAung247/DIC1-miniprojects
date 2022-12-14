//
// Created by TheinGiAung on 11/20/2022.
//  Bus E-Ticket mini project
//

#include <stdio.h>

char user_name_db[1000];
int password_db[1000];
int dbMoney[1000];
int main()
{
    int key = 1;
    char user_name;
    int flag = 0;
    int age = 0;
    int password;
    int confirm_password;
    int userIndex = 0;
    int passwordIndex = 0;
    int global_flag = 0;
    int login_flag = 0;
    int option = 0;
    int user_money = 0;
    char plus_minus = 0;
    int times = 0;
    int moneyIndex = 0;

    printf("\n ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("^^^^^^^Welcome to our bus e-ticket community.^^^^^^^\n");
    printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");

    while(key == 1) {
        printf("\t\tPlease press 1 to Register.\n");
        printf("\t\tPlease press 2 to Login.\n");
//        printf("\t\tPlease press 3 to Back.\n");
        printf("\t\tPlease press 4 to Quit completely.\n\n");
        printf("\t\t\t>>>");
        scanf("%d", &option);

        if(option == 1) {
            // Registration Page
            printf("\n\t^^^^^^^Welcome to Registration Page.^^^^^^^\n");
            while('true') {
                if(global_flag == 1) break;
                printf("\n\t\tEnter Your Name.\n");
                printf("\n\t\t(Please use one character, if not you will get an error. Thank You.\n\n");
                printf("\t\t\t>>>");
                scanf(" %c", &user_name); // currently use character(to change string)
                for(int i = 0; i < 1000; i++) {
                    if(user_name_db[i] == user_name) {
                        flag = 1;
                    }
                }
                if(flag == 1) {
                    printf("\tYour enter user name has already taken\n");
                } else {
                    user_name_db[userIndex] = user_name;
                    userIndex++;
                    printf("\n\t\tEnter Your Age.\n\n");
                    printf("\t\t\t>>>");
                    scanf("%d", &age);
                    if(age >= 10 ) {
                        // password
                        while('true') {
                            printf("\n\t\tEnter Your Password.\n");
                            printf("\t(You password must be 6 digits).\n\n");
                            printf("\t\t\t>>>");
                            scanf("%d", &password);
                            if(password >= 0 && password <= 9) {
                                printf("\tYour password needs more five digits. Please fill again.\n");
                            } else if(password > 9 && password <= 99) {
                                printf("\tYour password needs more four digits. Please fill again.\n");
                            } else if(password > 99 && password <= 999) {
                                printf("\tYour password needs more three digits. Please fill again.\n");
                            } else if(password > 999 && password <= 9999) {
                                printf("\tYour password needs more two digits. Please fill again.\n");
                            } else if(password > 9999 && password <= 99999) {
                                printf("\tYour password needs more one digit. Please fill again.\n");
                            } else if(password > 99999 && password <= 999999){
                                printf("\n\t\tConfirm your password.\n\n");
                                printf("\t\t\t>>>");
                                scanf("%d", &confirm_password);
                                if(password == confirm_password) {
                                    password_db[passwordIndex] = password;
                                    passwordIndex++;
                                    global_flag = 1;
                                    break;
                                } else {
                                    printf("\tYour password doesn't match. Try again\n");
                                }
                            } else {
                                printf("\tYour password number exceeds limit. Please fill again.\n");
                            }
                        }
                    } else {
                        printf("\n\tSorry. You can't register.\n\tYour age is not older than or equal 10.\n");
                        printf("\tOur community limits age in making ticket.\n");
                        printf("\tIf you want to make e-ticket, your age must be older than or equal 10.\n");
                        printf("\tCome back when you reach 10.\n");
                        printf("\tWe will be waiting your here.\n");
                        printf("\t\tThanks You.\n\n");
                        break;
                    }
                }
            }
            printf("\n\tYour Registration Completely Successful\n\n");

                // Home Page
                printf("\t^^^^^^^Welcome to Our Home Page^^^^^^^\n\n");
                printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                printf("\t\tYour Money\t%d kyats\n", user_money);
                printf("\n\t\tTo bill   \t%d left\t\n", times);
                printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
                while('true') {
                printf("\tIf you want to add your money, please enter 'i' or 'I'\n");
                printf("\tIf you want to pay your money, please enter 'e' or 'E'\n");
//                printf("\tIf you want to back, please enter 3.\n ");
                printf("\tIf you want to quit, please enter 4.\n");
                printf("\n\t\t\t>>>");
                scanf(" %c", &plus_minus);
                if(plus_minus == 'i' || plus_minus == 'I') {
                    printf("\n\t\t\tEnter Your Money.\n");
                    printf("\n\t\t\t>>>");
                    scanf("%d", &user_money);
                    printf("\n ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                    dbMoney[moneyIndex] += user_money;
                    printf("\t\tYour Money\t%d kyats\n", dbMoney[moneyIndex]);
                    times = dbMoney[moneyIndex]/200;
                    printf("\n\t\tTo bill   \t%d left\t\n", times);
                    printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
                } else if(plus_minus == 'e' || plus_minus == 'E'){
                    while('true') {
                        printf("\n\t\t\tEnter Your Password.\n");
                        printf("\n\t\t\t>>>");
                        scanf("%d", &password);
                        for(int i = 0; i < 1000; i++) {
                            if(password_db[i] == password) {
                                flag = 1;
                            }
                        }
                        if(flag == 1) {
                            printf("\n\t\t\tYour pay was successful\n");
                            printf("\n ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                            dbMoney[moneyIndex] = dbMoney[moneyIndex] - 200;
                            printf("\t\tYour Money\t%d kyats\n", dbMoney[moneyIndex]);
                            times = dbMoney[moneyIndex] / 200;
                            printf("\n\t\tTo bill   \t%d left.\n", times);
                            printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
                            break;
                            // to continue(if not enough money)
                        } else {
                            printf("\tYour password not incorrect.\n\t\tTry Again.\n");
                            // to continue
                        }
                    }
                } else if(plus_minus == '4') {
                        break;
//                } else if(plus_minus == '3') {
//                    global_flag = 1;
//                     break;
                } else{
                    printf("\n\tSorry. Your enter number is invalid. Try Again.\n\n");
                }
            }
        } else if(option == 2) {
            // Login Page
            printf("\n\t^^^^^^^Welcome to Login Page.^^^^^^^.\n");
            while('true') {
                printf("\n\t\tEnter Your Name.\n");
                printf("\n\t\t(Please use one character, if not you will get an error. Thank You.\n");
                printf("\n\t\t\t>>>");
                scanf(" %c", &user_name);
                printf("\n\t\tEnter Your Password.\n");
                printf("\n\t\t\t>>>");
                scanf(" %d", &password);
                for(int i = 0; i < 1000; i++) {
                    if(user_name_db[i] ==  user_name && password_db[i] == password) {
                        login_flag = 1;
                    }
                }
                if(login_flag == 1) {
                    break;
                } else{
                    printf("\n\tYour enter user name or password is incorrect.\n\n");
                    printf("\tIf you want to try again to login, please press 2.\n");
                    printf("\t\t\t(or)\n");
                    printf("\tIf you want to register, please press 1.\n");
                    printf("\n\t\t\t>>>");
                    scanf("%d", &option);
                    if(option == 1) {
                        // Registration Page
                        printf("\n\t^^^^^^^Welcome to Registration Page.^^^^^^^\n");
                        while('true') {
                            if(global_flag == 1) break;
                            printf("\n\t\tEnter Your Name.\n\n");
                            printf("\t\t\t>>>");
                            scanf(" %c", &user_name);
                            for(int i = 0; i < 1000; i++) {
                                if(user_name_db[i] == user_name) {
                                    flag = 1;
                                }
                            }
                            if(flag == 1) {
                                printf("\tYour enter user name has already taken\n");
                            } else {
                                user_name_db[userIndex] = user_name;
                                userIndex++;
                                printf("\n\t\tEnter Your Age.\n\n");
                                printf("\t\t\t>>>");
                                scanf("%d", &age);
                                if(age >= 10 ) {
                                    // password
                                    while('true') {
                                        printf("\n\t\tEnter Your Password.\n");
                                        printf("\t(You password must be 6 digits).\n\n");
                                        printf("\t\t\t>>>");
                                        scanf("%d", &password);
                                        if(password >= 0 && password <= 9) {
                                            printf("\tYour password needs more five digits. Please fill again.\n");
                                        } else if(password > 9 && password <= 99) {
                                            printf("\tYour password needs more four digits. Please fill again.\n");
                                        } else if(password > 99 && password <= 999) {
                                            printf("\tYour password needs more three digits. Please fill again.\n");
                                        } else if(password > 999 && password <= 9999) {
                                            printf("\tYour password needs more two digits. Please fill again.\n");
                                        } else if(password > 9999 && password <= 99999) {
                                            printf("\tYour password needs more one digit. Please fill again.\n");
                                        } else if(password > 99999 && password <= 999999){
                                            printf("\n\t\tConfirm your password.\n\n");
                                            printf("\t\t\t>>>");
                                            scanf("%d", &confirm_password);
                                            if(password == confirm_password) {
                                                password_db[passwordIndex] = password;
                                                passwordIndex++;
                                                global_flag = 1;
                                                break;
                                            } else {
                                                printf("\tYour password doesn't match. Try again\n");
                                            }
                                        } else {
                                            printf("\tYour password number exceeds limit. Please fill again.\n");
                                        }
                                    }
                                } else {
                                    printf("\n\tSorry. You can't register.\n\tYour age is not older than or equal 10.\n");
                                    printf("\tOur community limits age in making ticket.\n");
                                    printf("\tIf you want to make e-ticket, your age must be older than or equal 10.\n");
                                    printf("\tCome back when you reach 10.\n");
                                    printf("\tWe will be waiting your here.\n");
                                    printf("\t\tThanks You.\n\n");
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
            }
            printf("\n\tYour Login Completely Successful.\n\n");

                // Home Page
                printf("\t^^^^^^^Welcome to Our Home Page^^^^^^^\n\n");
                printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                printf("\t\tYour Money\t%d kyats\n", user_money);
                printf("\n\t\tTo bill   \t%d left\t\n", times);
                printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
                while('true') {
                printf("\tIf you want to add your money, please enter 'i' or 'I'\n");
                printf("\tIf you want to pay your money, please enter 'e' or 'E'\n");
//                printf("\tIf you want to back, please enter 3.\n ");
                printf("\tIf you want to quit, please enter 4\n");
                printf("\n\t\t\t>>>");
                scanf(" %c", &plus_minus);
                if(plus_minus == 'i' || plus_minus == 'I') {
                    printf("\n\t\t\tEnter Your Money.\n");
                    printf("\n\t\t\t>>>");
                    scanf("%d", &user_money);
                    printf("\n ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                    dbMoney[moneyIndex] += user_money;
                    printf("\t\tYour Money\t%d kyats\n", dbMoney[moneyIndex]);
                    times = dbMoney[moneyIndex]/200;
                    printf("\n\t\tTo bill   \t%d left\t\n", times);
                    printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
                } else if(plus_minus == 'e' || plus_minus == 'E'){
                    while('true') {
                        printf("\n\t\t\tEnter Your Password.\n");
                        printf("\n\t\t\t>>>");
                        scanf("%d", &password);
                        for(int i = 0; i < 1000; i++) {
                            if(password_db[i] == password) {
                                flag = 1;
                            }
                        }
                        if(flag == 1){
                            printf("\n\t\t\tYour pay was successful\n");
                            printf("\n ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                            dbMoney[moneyIndex] = dbMoney[moneyIndex] - 200;
                            printf("\t\tYour Money\t%d kyats\n", dbMoney[moneyIndex]);
                            times = dbMoney[moneyIndex]/200;
                            printf("\n\t\tTo bill   \t%d left.\n", times);
                            printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
                            break;
                        } else {
                            printf("\tYour password not incorrect.\n\t\tTry Again.\n");
                        }
                    }
                } else if(plus_minus == '4') {
                    break;
//                } else if(plus_minus == '3') {
//                    global_flag = 1;
//                     break;
                } else{
                    printf("\tSorry. Your enter number is invalid. Try Again.\n\n");
                }
            }
        } else if(option == 4) {
            break;
        } else {
            printf("\n\tYour enter number is invalid. Please try again.\n");
        }
    }
    return 0;
}