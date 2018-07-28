//
// Created by Michael Rokitko on 10/06/2018.
//


// Include in your project:
//while (userChoise != 9) {
//      userChoise = menu();
//      switch (userChoise) { }
#ifndef PLANES_MENU_H
#define PLANES_MENU_H
#include <iostream>
#include <string>

using namespace std;

int menu(int& menueEnd) {
    int decision = -1;
//    int const menueEnd = 21;

    while (decision != menueEnd) {
        cout << "---------------------------ヽ(ˇヘˇ)ノ----------------------------" << endl;
        cout << "To show all books press                                        1" << endl;
        cout << "To show open all orders press                                  2" << endl;
        cout << "To show all customers press                                    3" << endl;
        cout << "To show all suppliers press                                    4" << endl;
        cout << "To show all transactions from X to Y press                     5" << endl;
        cout << "To show all books with discount press                          6" << endl;
        cout << "To check if book is in the storage press                       7" << endl;
        cout << "To show all suppliers of a book X press                        8" << endl;
        cout << "To see how many copies of X were sold press since Y press      9" << endl;
        cout << "To see how many books has customer X bought since Y press     10" << endl;
        cout << "To see the customer who bought the maximum books press        11" << endl;
        cout << "To see the supplier with maximum supplied books press         12" << endl;
        cout << "To see all orders between dates press                         13" << endl;
        cout << "To see all completed orders between dates press               14" << endl;
        cout << "To see how much money was saved by customer since Y press     15" << endl;
        cout << "To see Q1 Q2 Q3 Q4 and total Yearly income press              16" << endl;
        cout << "To see all the customers who joined since Y press             17" << endl;
        cout << "To see total supplies from supplier X since Y press           18" << endl;
        cout << "To see total sales of worker X press                          19" << endl;
        cout << "To see top-10 selling books press                             20" << endl;
        cout << "To clean screen press                                         22" << endl;
        cout << "To Exit press                                                 23" << endl;
        cout << "----------------------------------------------------------------" << endl;
        do                                                  //protection from wrong intput
        {
            cin >> decision;
            if (decision < 1 || decision > menueEnd) {
                cout << "Not a valid choice, please enter menu number!\n";
                decision = 32;
                cin.clear();
                fflush(stdin);
                char temp[100];
                cin.getline(temp, 100);
                continue;
            }

        } while (decision < 1 || decision > menueEnd);
        return decision;
    }
}
#endif //PLANES_MENU_H
