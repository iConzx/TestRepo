#include "member.h"

Member::Member() {
    // TODO Auto-generated constructor stub
    tail = NULL;
    head = NULL;
    num = 0;
    total = 0;
}

void Member::SetInfo(string mName, int mNum, string mType, int mMonth, int mDay, int mYear, int mTotal){
    num = 0;
    total = 0;
    name = " ";
    type = " ";

}

Member::~Member() {
    // TODO Auto-generated destructor stub

}

void Member::AddMember(string mName, int mNum, string mType,
        int mMonth, int mDay, int mYear, int mTotal){


    Member *Memberptr;
    Memberptr = new Member;
    Memberptr->SetName(mName);
    Memberptr->SetNum(mNum);
    Memberptr->SetType(mType);
    Memberptr->date.SetDate(mMonth, mDay, mYear);

    cout  << right;

    if (head == NULL)
    {
        Memberptr->next = head;
        head = Memberptr;
        Memberptr->next = tail;
        tail = Memberptr;
    }
    //ELSE - If at least one node is currently connected, adds current
    //		 node to the tail of list
    else
    {
        Memberptr->next = tail->next;	//if at least one node has been created
        tail->next = Memberptr;
    }


}

void Member::SetName(string mName)
{
    name = mName;
}

void Member::SetNum(int mNum)
{
    num = mNum;
}

void Member::SetTotal(int mTotal)
{
    total = mTotal;
}

void Member::SetType(string mType)
{
    type = mType;
}

void Member::PrintMemberInfo() const
{
    const int NAME_WIDTH = 26;
    const int ID_WIDTH   =  7;
    const int TYPE_WIDTH = 17;
    const int DATE_WIDTH = 18;


    Member* memberPtr;
    memberPtr = head;

    cout << left;
    cout << "Bulk Club Members\n" << "-----------------\n\n";

    cout << setw(NAME_WIDTH) << "Member Name"
            << setw(ID_WIDTH)   << "ID"
            << setw(TYPE_WIDTH) << "Membership Type"
            << setw(DATE_WIDTH) << "Expiration Date" << endl;

    cout << setw(NAME_WIDTH) << "-----------"
            << setw(ID_WIDTH)   << "------ "
            << setw(TYPE_WIDTH) << "---------------"
            << setw(DATE_WIDTH) << "---------------" << endl;

    while(memberPtr != NULL)
    {
        cout << left;
        cout << setw(NAME_WIDTH) << memberPtr->GetName()
                                     << setw(ID_WIDTH)   << memberPtr->GetNum()
                                     << setw(TYPE_WIDTH) << memberPtr->GetType();

        memberPtr->date.DisplayDate();
        cout  << right;
        memberPtr = memberPtr->next;
    }
}

string Member::GetName() const
{
    return name;
}

int Member::GetNum() const
{
    return num;
}

int Member::GetTotal() const
{
    return total;
}

string Member::GetType() const
{
    return type;
}

