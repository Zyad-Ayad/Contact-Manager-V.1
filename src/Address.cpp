#include "Address.h"
#include <iostream>
using namespace std;
Address::Address()
{

    string input= "";
    while(!(this->SetPlace(input)))
    {
        cout << "\n\tEnter user Address :  ";
        getline(cin, input);
        cout<<endl;
    }

    input= "";
    while(!(this->SetType(input)))
    {
        cout << "\n\tEnter user Address Type : ";
        getline(cin, input);
        cout<<endl;
    }

    input= "";
    while(!(this->SetDescription(input)))
    {
        cout << "\n\tEnter user Address description : ";
        getline(cin, input);
        cout<<endl;
    }
}

bool Address::SetPlace(string new_place)
{
    if(new_place.size() == 0)
    {
        return false;
    }
    else
    {
        this->place = new_place;
        return true;
    }
}

bool Address::SetType(string new_type)
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



bool Address::SetDescription(string new_description)
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

void Address::Edit()
{
    cin.ignore();
    string input= "";
    cout << "\n\n\t\t  leave blank for no changes!\n\n";


    while(!(this->SetPlace(input)))
    {
        cout << "\n\tEnter user place [ "<< this->place <<" ]:  ";
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
        cout << "\n\tEnter user Address Type [ "<< this->type <<" ] : ";
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
        cout << "\n\tEnter user Address description : ";
        getline(cin, input);
        cout<<endl;
        if(input.size()==0)
        {
            break;
        }
    }
}

Address::~Address()
{
    //dtor
}
