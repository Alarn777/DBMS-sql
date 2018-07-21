//
// Created by Michael Rokitko on 21/07/2018.
//

#ifndef DBMS_SQL_ORDER_H
#define DBMS_SQL_ORDER_H
#include "Database.h"
#include <iostream>

#define CON Database &db = Database::getInstance();Connection *con = db.getConnection();
using namespace std;

class Order {
public:
    Order() {};
    void showAllOrdersInStore() {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Orders");
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t allBooks = rset->rowsCount();
        while (allBooks >= 1) {
            cout << "-------------------------------------" << endl;
            cout << "Order Number: " + rset->getString("idOrder") << endl;
            cout << "Date and Time: " + rset->getString("date") << endl;
            cout << "Order status: " + rset->getString("status") << endl;
            cout << "Total Price: " + rset->getString("TotalPrice") << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
            allBooks--;
        }
        delete pstmt;
        delete rset;
        delete con;
    }
};


#endif //DBMS_SQL_ORDER_H
