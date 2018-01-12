#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QDate>

void addStudent(QString lastName, QString firstName, QString birthdate, double average);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Starting SQLite Database ...";
    qDebug() << '\n';

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../Simple_SQLite_Database/Databases/simple_database.sqlite");

    if (!db.open()) {

        qDebug() << "Error. Couldn't open database!" << '\n';

    }
    else {

        qDebug() << "Database opened successfully." << '\n';

    }

    QString query = "CREATE TABLE students ("
                    "LastName VARCHAR(30),"
                    "FirstName VARCHAR(30),"
                    "Birthdate DATE,"
                    "Average double);";

    QSqlQuery qry;
    if (!qry.exec(query)) {

        qDebug() << "Error. Couldn't create table!" << '\n';

    }
    else {

        qDebug() << "Table created successfully." << '\n';

    }

    // Adding students
    addStudent("Smith", "John", "01-02-1994", 8.76);
    addStudent("Mille", "Jeremy", "05-16-1995", 7.14);
    addStudent("Jackson", "Emily", "09-11-1996", 9.34);
    addStudent("Fate", "Tobias", "03-23-1994", 7.89);
    addStudent("Baxter", "Melany", "12-09-1997", 9.78);

    qDebug() << '\n';
    qDebug() << "Closing SQLite Database ...";
    db.close();

    return a.exec();
}




void addStudent(QString lastName, QString firstName, QString birthdate, double average) {

    QSqlQuery qry;

    qry.prepare("INSERT INTO students ("
                "LastName,"
                "FirstName,"
                "Birthdate,"
                "Average)"
                "VALUES (?,?,?,?);");

    qry.addBindValue(lastName);
    qry.addBindValue(firstName);
    qry.addBindValue(QDate::fromString(birthdate, "MM-dd-yyyy"));
    qry.addBindValue(average);

    if (!qry.exec()) {

        qDebug() << "Error. Couldn't add student!";

    }
    else {

        qDebug() << "Student added successfully.";

    }

}






