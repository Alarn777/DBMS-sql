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
    void maxBooksBought()
    {
        int maxCount[2];
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Bookstore.Customer h1\n"
                                                                 "\tINNER JOIN customer_order AS h2\n"
                                                                 "\ton h1.SSN = h2.customer_id \n"
                                                                 "    INNER JOIN Orders as h3\n"
                                                                 "    on h3.idOrder = h2.order_id \n"
                                                                 "    INNER JOIN books_in_order as h4\n"
                                                                 "    on h4.order_id = h3.idOrder\n"
                                                                 "    ORDER BY SSN DESC");
//        pstmt->setString(1,);
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        while (all >= 1) {
            int ssn = rset->getInt("SSN");
            int tempcount = 0;
                while (all > 0 && rset->getInt("SSN") == ssn) {
                    tempcount += rset->getInt("quantity");
                    rset->next();
                    all--;
                }
                if (tempcount > maxCount[0]) {
                    maxCount[0] = tempcount;
                        rset->previous();
                        maxCount[1] = rset->getInt("SSN");
                        rset->next();
                    }


        }
        pstmt = con->prepareStatement("SELECT * FROM Bookstore.Customer INNER JOIN FullName where Customer.SSN = FullName.SSN and Customer.SSN = ?");
        pstmt->setString(1,to_string(maxCount[1]));
        rset = pstmt->executeQuery();
        if(rset->rowsCount() > 0)
        {
            rset->first();
            cout << "-------------------------------------" << endl;
            cout << "Customer: " << rset->getString("FName") << " " << rset->getString("LName")  << " bought " << maxCount[0] << " books. Which is the maximum in our store!" << endl;
            cout << "-------------------------------------" << endl;
        }





        delete pstmt;
        delete rset;
        delete con;
    }
    void moneySavedBySpecificCustomer(string& ssn,string& start){
        Database &db = Database::getInstance();
        float moneySaved = 0,customerDiscount = 1.0;
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement(
                "SELECT * FROM Bookstore.Customer INNER JOIN customer_order where customer_order.customer_id = Customer.SSN and customer_id = ?");
        pstmt->setString(1,ssn);
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t allOrders = rset->rowsCount();
        if(rset->rowsCount() >=1)
        {
            customerDiscount = rset->getInt("Discount");
            double temp = static_cast<float>(rset->getDouble("Discount"));
            string orderId = rset->getString("order_id");
            cout << "";
        }
        while (allOrders >= 1) {
            PreparedStatement *pstmtBooks = con->prepareStatement(
                    "SELECT * FROM Bookstore.books_in_order INNER JOIN Book where Book.ISBN = books_in_order.books_id and order_id = ?");
            pstmtBooks->setString(1,rset->getString("order_id"));
            ResultSet *rsetBooks = pstmtBooks->executeQuery();
            size_t allBooks = rsetBooks->rowsCount();
            rsetBooks->first();
            while(allBooks >=1)
            {
                PreparedStatement *pstmtBookPrice = con->prepareStatement("select * FROM Bookstore.Book INNER JOIN book_price where Book.ISBN = Book_price.idbook and ISBN = ?");
                pstmtBookPrice->setString(1,rsetBooks->getString("ISBN"));
                ResultSet *rsetBookPrice = pstmtBookPrice->executeQuery();
                rsetBookPrice->first();
                float bookPrice = static_cast<float>(rsetBookPrice->getDouble("customer_price"));
                float bookQuantity = static_cast<float>(rsetBooks->getDouble("quantity"));
                float bookDiscount = static_cast<float>(rsetBooks->getDouble("global_discount"));
                float tempMoney = 0;
                moneySaved += (bookPrice * bookQuantity) - bookPrice * bookQuantity * bookDiscount;
                delete pstmtBookPrice;
                delete rsetBookPrice;
                allBooks--;
                rsetBooks->next();
            }
            rset->next();
            allOrders--;
            delete pstmtBooks;
            delete rsetBooks;
        }
        delete pstmt;
        delete rset;
        delete con;
        moneySaved = moneySaved * customerDiscount;
        cout << moneySaved << endl;
    }
};


#endif //DBMS_SQL_CUSTOMER_H
