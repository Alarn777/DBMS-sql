//
// Created by Michael Rokitko on 10/06/2018.
//

#ifndef PLANES_MENU_H
#define PLANES_MENU_H
#include <iostream>
#include <string>

using namespace std;

int menu() {
    int decision = -1;
    int const menueEnd = 10;

    while (decision != menueEnd) {
        cout << "----------------ヽ(ˇヘˇ)ノ-------------------" << endl;
        cout << "To Create new Bill press                   1" << endl;
        cout << "To Add Coffee to bill press                2" << endl;
        cout << "To Add Ice Cream to bill press             3" << endl;
        cout << "To Add Bread to bill press                 4" << endl;
        cout << "To Print Bill press                        5" << endl;
        cout << "To Exit press                              10" << endl;
        cout << "--------------------------------------------" << endl;
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
