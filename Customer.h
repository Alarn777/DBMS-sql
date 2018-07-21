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
class Store;
class Customer {
public:
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
            PreparedStatement *pstmtForName = con->prepareStatement("SELECT * FROM FullName WHERE SSN = ? ");
            pstmtForName->setString(1, rset->getString("SSN"));
            ResultSet *fullName = pstmtForName->executeQuery();
            if (fullName->rowsCount() == 1) {
                fullName->first();
                cout << "First Name: " + fullName->getString("FName") << endl;
                cout << "Last Name: " + fullName->getString("LName") << endl;
            } else {
                cerr << "No Such Customer Found!" << endl;
            }
            delete fullName;
            delete pstmtForName;
            cout << "Phone Number: " + rset->getString("PhoneNumber") << endl;
            PreparedStatement *pstmtForAddress = con->prepareStatement("SELECT * FROM Address WHERE idAddress = ? ");
            pstmtForAddress->setString(1, rset->getString("SSN"));
            ResultSet *Address = pstmtForAddress->executeQuery();
            if (Address->rowsCount() == 1) {
                Address->first();
                cout << "Address: " +  Address->getString("City");
                cout << "," + Address->getString("Street");
                cout << "," + Address->getString("House") << endl;
                cout << "Books Purchased: " + rset->getString("books_ordered") << endl;
                cout << "-------------------------------------" << endl;
            } else {
                cerr << "No Such Customer Found!" << endl;
            }
            delete pstmtForAddress;
            delete Address;
            all--;
            rset->next();
        }
        delete pstmt;
        delete rset;
        delete con;
    }
};


#endif //DBMS_SQL_CUSTOMER_H
