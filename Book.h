//
// Created by Michael Rokitko on 21/07/2018.
//

#ifndef DBMS_SQL_BOOK_H
#define DBMS_SQL_BOOK_H


#include "Database.h"
#include <iostream>
#include "Store.h"
#define CON Database &db = Database::getInstance();Connection *con = db.getConnection();
using namespace std;

class Book {
public:
    Book() {};
    void showAllBooksInStore() {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Book");
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t allBooks = rset->rowsCount();
        while (allBooks >= 1) {
            cout << "-------------------------------------" << endl;
            cout << "ISBN: " + rset->getString("ISBN") << endl;
            cout << "Book Name: " + rset->getString("book_name") << endl;
            cout << "Price per unit: " + rset->getString("Price") << endl;
            cout << "Quantity: " + rset->getString("Quantity") << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
            allBooks--;
        }
        delete pstmt;
        delete rset;
        delete con;
    }



private:

};


#endif //DBMS_SQL_BOOK_H
