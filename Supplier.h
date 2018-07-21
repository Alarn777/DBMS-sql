//
// Created by Michael Rokitko on 21/07/2018.
//

#ifndef DBMS_SQL_SUPPLIER_H
#define DBMS_SQL_SUPPLIER_H

#include "Database.h"
#include <iostream>

#define CON Database &db = Database::getInstance();Connection *con = db.getConnection();
using namespace std;


class Supplier {
public:
    void showAllSuppliers() {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Supplier");
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        while (all >= 1) {
            cout << "-------------------------------------" << endl;
            cout << "Supplier ID: " + rset->getString("idSupplier") << endl;
            cout << "Supplier Name: " + rset->getString("name") << endl;
            cout << "Phone Number: " + rset->getString("phone") << endl;
            PreparedStatement *pstmtForAddress = con->prepareStatement(
                    "SELECT * FROM Supplier_address WHERE idSupplier_address = ? ");
            pstmtForAddress->setString(1, rset->getString("idSupplier"));
            ResultSet *Address = pstmtForAddress->executeQuery();
            Address->first();
            cout << "Address: " + Address->getString("City");
            cout << "," + Address->getString("Street");
            cout << "," + Address->getString("House") << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
            all--;
        }
        delete pstmt;
        delete rset;
        delete con;
    }

    void checkAllSuppliersOfABook(int isbn) {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM supplier_books WHERE book_isbn = ? ");
        pstmt->setString(1, to_string(isbn));
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        if (all < 1) {
            cout << "-------------------------------------" << endl;
            cout << "ISBN: " << isbn;
            cout << " Is not valid!" << endl;
            cout << "-------------------------------------" << endl;
        } else {
            cout << "-------------------------------------" << endl;
            cout << "Book with ISBN: " + rset->getString("book_isbn") << endl;
            cout << "Can be provided by: " << endl;
            while (all >= 1) {
                PreparedStatement *pstmtForSupplier = con->prepareStatement(
                        "SELECT * FROM Supplier WHERE idSupplier = ? ");
                pstmtForSupplier->setString(1, rset->getString("id_supplier"));
                ResultSet *rsetForSupplier = pstmtForSupplier->executeQuery();
                rsetForSupplier->first();
                cout << rsetForSupplier->getString("name") << endl;
                rset->next();
                all--;
            }
            cout << "-------------------------------------" << endl;
        }
        delete pstmt;
        delete rset;
        delete con;
    }
};


#endif //DBMS_SQL_SUPPLIER_H