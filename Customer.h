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
    void bookOredredByCustomerSince(string& ssn,string &start) {
        int booksQuantity = 0;
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT Customer.SSN ,customer_order.order_id FROM Customer RIGHT JOIN customer_order ON Customer.SSN=customer_order.customer_id WHERE Customer.SSN= ?;");
        pstmt->setString(1, ssn);
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        if (all < 1) {
            cout << "-------------------------------------" << endl;
            cerr << "Invalid SSN!" << endl;
            cout << "-------------------------------------" << endl;
            delete pstmt;
            delete rset;
            delete con;
            return;
        }
        while (all >= 1) {
            PreparedStatement *pstmtOrder = con->prepareStatement("SELECT Orders.idOrder,books_in_order.quantity FROM Orders RIGHT JOIN books_in_order ON Orders.idOrder=books_in_order.order_id  where date > ? and idOrder = ?");
            pstmtOrder->setString(1, start);
            pstmtOrder->setString(2, rset->getString("order_id"));
            ResultSet *rsetOrder = pstmtOrder->executeQuery();
            rsetOrder->first();
            size_t allOrder = rsetOrder->rowsCount();
            while (allOrder >= 1) {
                booksQuantity += rsetOrder->getInt("quantity");
                allOrder--;
                rsetOrder->next();
            }

            all--;
            rset->next();

        }
        cout << "-------------------------------------" << endl;
        cout << "Customer: " << ssn  << " bought: " << booksQuantity << " books since: " << start << endl;
        cout << "-------------------------------------" << endl;
        delete pstmt;
        delete rset;
        delete con;
    }
};


#endif //DBMS_SQL_CUSTOMER_H
