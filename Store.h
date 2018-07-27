//
// Created by Michael Rokitko on 21/07/2018.
//

#ifndef DBMS_SQL_STORE_H
#define DBMS_SQL_STORE_H
#include "Database.h"
#include <iostream>

#define CON Database &db = Database::getInstance();Connection *con = db.getConnection();
using namespace std;

class Store {
public:
    Store() {}
    void showAllCustomers();
    void showAllTransactions(string& start,string& end){
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM resupply where date_time between ? and ? ");
        pstmt->setString(1, start);
        pstmt->setString(2, end);
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        while (all >= 1) {
            cout << "-------------------------------------" << endl;
            cout << "Resupply ID: "<< rset->getInt("resupply_id") << endl;
            cout << "Total Price paid: " << rset->getInt("total_price") << endl;
            cout << "Status: " << rset->getString("status") << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
            all--;
        }
        pstmt = con->prepareStatement("SELECT * FROM Orders where date between ? and ? ");
        pstmt->setString(1, start);
        pstmt->setString(2, end);
        rset = pstmt->executeQuery();
        rset->first();
        all = rset->rowsCount();
        while (all >= 1) {
            cout << "-------------------------------------" << endl;
            cout << "Purchase ID: "<< rset->getInt("idOrder") << endl;
            cout << "Total Money received: " << rset->getInt("TotalPrice") << endl;
            cout << "Status: " << rset->getString("status") << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
            all--;
        }

        delete pstmt;
        delete rset;
        delete con;
    }

    void showYearlyEarning(string& year){
        string qs[4] = {"Q1","Q2","Q3","Q4"};
        string qsVal[8] = {"01-03","03-30","04-01","06-30","07-01","09-30","10-01","12-31"};
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        int i = 0,j = 0;
        while (i < 4) {
            int money_earned = 0, money_spent = 0;
            PreparedStatement *pstmt = con->prepareStatement(
                    "SELECT * FROM Bookstore.orders where date between ? and ? and status = 'Closed'");
            string temp =  year + "-" + qsVal[j];
            pstmt->setString(1, year + "-" + qsVal[j]);
            temp =   year + "-" + qsVal[j+1];
            pstmt->setString(2, year + "-" + qsVal[j+1]);
            ResultSet *rset = pstmt->executeQuery();
            rset->first();
            size_t all = rset->rowsCount();
            while (all >= 1) {
                money_earned += rset->getInt("TotalPrice");
                rset->next();
                all--;

            }
            pstmt = con->prepareStatement("SELECT * FROM Bookstore.resupply where date_time between ? and ? and status = 'supplied'");
            pstmt->setString(1, year + "-" + qsVal[j]);
            pstmt->setString(2, year + "-" + qsVal[j+1]);
            rset = pstmt->executeQuery();
            rset->first();
            all = rset->rowsCount();
            while (all >= 1) {
                money_spent += rset->getInt("total_price");
                rset->next();
                all--;
            }
            delete pstmt;
            delete rset;
            cout << "Total " + qs[i] + " earnings are: " << money_earned - money_spent << endl;
            i++;
            j +=2;
        }
        delete con;
    }

    ~Store() {}
private:

};


#endif //DBMS_SQL_STORE_H
