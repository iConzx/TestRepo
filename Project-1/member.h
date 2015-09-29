#ifndef MEMBER_H
#define MEMBER_H

#include "Date.h"

class Member {
public:
    Member();
    ~Member();
    void SetInfo(string mName, int mNum, string mType, int mMonth, int mDay, int mYear, int mTotal);
    void AddMember(string mName, int mNum, string mType, int mMonth, int mDay, int mYear, int mTotal);
    void SetName(string mName);
    void SetNum(int mNum);
    void SetType(string mType);
    void SetTotal(int mTotal);

    void PrintMemberInfo() const;
    string GetName () const;
    int    GetNum  () const;
    string GetType () const;
    int    GetTotal() const;






private:
    string name;
    int num;
    string type;
    Date date;
    int total;
    Member *head;
    Member *tail;
    Member *next;
};

#endif // MEMBER_H
