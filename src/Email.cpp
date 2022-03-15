#include <iostream>
using namespace std;
#include "Email.h"

Email::Email()
{

    string input= "";
    while(!(this->SetEmail(input)))
    {
        cout << "\n\tEnter user Email :  ";
        getline(cin, input);
        cout<<endl;
    }

    input= "";
    while(!(this->SetType(input)))
    {
        cout << "\n\tEnter user Email Type : ";
        getline(cin, input);
        cout<<endl;
    }

    input= "";
    while(!(this->SetDescription(input)))
    {
        cout << "\n\tEnter user Email description : ";
        getline(cin, input);
        cout<<endl;
    }
}

bool Email::SetEmail(string new_email)
{
    size_t aat = new_email.find('@');
    size_t dot = new_email.find('.');
    if (aat == string::npos || dot == string::npos)
    {
        return false;
    }
    else if (dot-1 <= aat || dot+3 >= new_email.size())
    {
        return false;
    }
    else
    {
        this->email = new_email;
        return true;
    }
}


bool Email::SetType(string new_type)
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



bool Email::SetDescription(string new_description)
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


void Email::Edit()
{
    cin.ignore();
    string input= "";
    cout << "\n\n\t\t  leave blank for no changes!\n\n";


    while(!(this->SetEmail(input)))
    {
        cout << "\n\tEnter user Email [ "<< this->email <<" ]:  ";
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
        cout << "\n\tEnter user Email Type [ "<< this->type <<" ] : ";
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
        cout << "\n\tEnter user Email description : ";
        getline(cin, input);
        cout<<endl;
        if(input.size()==0)
        {
            break;
        }
    }
}

Email::~Email()
{
    //dtor
}
