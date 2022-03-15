#include <iostream>
using namespace std;
#include "Phone.h"

Phone::Phone()
{

    string input= "";
    while(!(this->SetPhone(input)))
    {
        cout << "\n\tEnter user Phone [01xxxxxxxxxx]:  ";
        getline(cin, input);
        cout<<endl;
    }

    input= "";
    while(!(this->SetType(input)))
    {
        cout << "\n\tEnter user Phone Type : ";
        getline(cin, input);
        cout<<endl;
    }

    input= "";
    while(!(this->SetDescription(input)))
    {
        cout << "\n\tEnter user Phone description : ";
        getline(cin, input);
        cout<<endl;
    }
}

bool Phone::SetPhone(string new_phone)
{
    if(new_phone.size() != 11 || new_phone.substr(0,2) != "01")
    {
        return false;
    }
    else
    {
        this->phone = new_phone;
        return true;
    }
}

bool Phone::SetType(string new_type)
{
    if(new_type.size() == 0)
    {
        return false;
    }
    else
    {
        this->type = new_type;
        return true;
    }
}



bool Phone::SetDescription(string new_description)
{
    if(new_description.size() == 0)
    {
        return false;
    }
    else
    {
        this->description = new_description;
        return true;
    }
}

void Phone::Edit()
{
    cin.ignore();
    string input= "";
    cout << "\n\n\t\t  leave blank for no changes!\n\n";


    while(!(this->SetPhone(input)))
    {
        cout << "\n\tEnter user Phone [ "<< this->phone <<" ]:  ";
        getline(cin, input);
        cout<<endl;
        if(input.size()==0)
        {
            break;
        }
    }

    input= "";
    while(!(this->SetType(input)))
    {
        cout << "\n\tEnter user Phone Type [ "<< this->type <<" ] : ";
        getline(cin, input);
        cout<<endl;
        if(input.size()==0)
        {
            break;
        }
    }

    input= "";
    while(!(this->SetDescription(input)))
    {
        cout << "\n\tEnter user Phone description : ";
        getline(cin, input);
        cout<<endl;
        if(input.size()==0)
        {
            break;
        }
    }
}




Phone::~Phone()
{
    //dtor
}
