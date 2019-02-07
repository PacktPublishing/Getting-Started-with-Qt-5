#include <QApplication>
#include <QtSql>
#include <QDebug>


/*
  use contact_db;
    CREATE TABLE IF NOT EXISTS contacts (
    id INT AUTO_INCREMENT,
    last_name VARCHAR(255) NOT NULL,
    first_name VARCHAR(255) NOT NULL,
    phone_number VARCHAR(255) NOT NULL,
    PRIMARY KEY (id)
)  ENGINE=INNODB;
 */

int main(int argc, char *argv[]) {
    // Setup db connection

    QSqlDatabase db_conn =
            QSqlDatabase::addDatabase("QMYSQL", "contact_db");

    db_conn.setHostName("127.0.0.1");
    db_conn.setDatabaseName("contact_db");
    db_conn.setUserName("root");
    db_conn.setPassword("");
    db_conn.setPort(3306);

    // Error checks
    if (!db_conn.open()) {
        qDebug() << db_conn.lastError();
        return 1;
    } else {
        qDebug() << "Database connection established !";
    }


    // Create table
    QString table_definition = "use contact_db;\n"
                            "    CREATE TABLE IF NOT EXISTS contacts (\n"
                            "    id INT AUTO_INCREMENT,\n"
                            "    last_name VARCHAR(255) NOT NULL,\n"
                            "    first_name VARCHAR(255) NOT NULL,\n"
                            "    phone_number VARCHAR(255) NOT NULL,\n"
                            "    PRIMARY KEY (id)\n"
                            ")  ENGINE=INNODB;";


    QSqlQuery table_creator(table_definition, db_conn);


    // Issue SELECT statement
    QSqlQuery statement("SELECT * FROM contacts", db_conn);
    QSqlRecord record = statement.record();

    while (statement.next()){
        QString firstName = statement.value(record.indexOf("first_name")).toString();
        QString lastName = statement.value(record.indexOf("last_name")).toString();
        QString phoneNumber = statement.value(record.indexOf("phone_number")).toString();

        qDebug() << firstName << " - " << lastName << " - " << phoneNumber;
    }


    // Insert new contacts
    QSqlQuery insert_statement(db_conn);
    insert_statement.prepare("INSERT INTO contacts (last_name, first_name, phone_number)"
                             "VALUES (?, ?, ?)");
    insert_statement.addBindValue("Sidle");
    insert_statement.addBindValue("Sara");
    insert_statement.addBindValue("+14495849555");
    insert_statement.exec();



    //QSqlQuery insert_statement(db_conn);
    insert_statement.prepare("INSERT INTO contacts (last_name, first_name, phone_number)"
                             "VALUES (?, ?, ?)");
    insert_statement.bindValue(2, "+144758849555");
    insert_statement.bindValue(1, "Brass");
    insert_statement.bindValue(0, "Jim");
    insert_statement.exec();




    insert_statement.prepare("INSERT INTO contacts (last_name, first_name, phone_number)"
                             "VALUES (:last_name, :first_name, :phone_number)");
    insert_statement.bindValue(":last_name", "Brown");
    insert_statement.bindValue(":first_name", "Warrick");
    insert_statement.bindValue(":phone_number", "+7494588594");
    insert_statement.exec();



    // Delete a record
    QSqlQuery delete_statement(db_conn);
    delete_statement.exec("DELETE FROM contacts WHERE first_name = 'Warrick'");
    qDebug() << "Number of rows affected: " << delete_statement.numRowsAffected();


    // Update a record
    QSqlQuery update_statement(db_conn);
    update_statement.exec("UPDATE contacts SET first_name='Jude' WHERE id=1 ");
    qDebug() << "Number of rows affected: " << update_statement.numRowsAffected();




}


