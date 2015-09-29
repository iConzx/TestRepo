#include "mainwindow.h"
#include <QApplication>

#include "Date.h"
#include "Member.h"
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    string memberName;
    int    memberId;
    string memberType;
    int month;
    int day;
    int year;
    int total;
    Member Function;


    ifstream inFile;
    inFile.open("MemberInfo.txt");

    total = 0;

    while(inFile)
    {
        getline(inFile, memberName);
        inFile >> memberId;
        inFile.ignore(10, '\n');
        getline(inFile, memberType);
        inFile >> month;
        inFile.ignore(1, '/');
        inFile >> day;
        inFile.ignore(1, '/');
        inFile >> year;
        inFile.ignore(10, '\n');
        Function.AddMember(memberName, memberId, memberType, month, day, year, total);
    }

    Function.PrintMemberInfo();


    return a.exec();
}
