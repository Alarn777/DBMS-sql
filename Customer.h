//
// Created by Michael Rokitko on 21/07/2018.
//

#ifndef DBMS_SQL_CUSTOMER_H
#define DBMS_SQL_CUSTOMER_H
//#include "Database.h"
#include "Store.h"
#include <iostream>

#define CON Database &db = Database::getInstance();Connection *con = db.getConnection();
using namespace std;

class Customer : public Store {
    void showAllCustomersInStore() {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Customer");
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        while (all >= 1) {
            cout << "-------------------------------------" << endl;
            cout << "SSN: " + rset->getString("SSN") << endl;
            PreparedStatement *pstmtForName = con->prepareStatement("SELECT * FROM Customer WHERE id= ?");
            pstmt->setString(1, rset->getString("SSN"));
            ResultSet *fullName = pstmt->executeQuery();
            fullName->first();
            cout << "First Name: " + fullName->getString("FName") << endl;
            cout << "Last Name: " + fullName->getString("LName") << endl;
            cout << "Phone Number: " + rset->getString("PhoneNumber") << endl;
            PreparedStatement *pstmtForAddress = con->prepareStatement("SELECT * FROM Address WHERE id= ?");
            pstmt->setString(1, rset->getString("SSN"));
            ResultSet *Address = pstmt->executeQuery();
            Address->first();
            cout << "Books Purchased: " + rset->getString("books_ordered");
            cout << "Books Purchased: " + rset->getString("books_ordered");
            cout << "Books Purchased: " + rset->getString("books_ordered") << endl;
            cout << "Books Purchased: " + rset->getString("books_ordered") << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
            all--;
        }
        delete pstmt;
        delete rset;
        delete con;
    }
};


#endif //DBMS_SQL_CUSTOMER_H
