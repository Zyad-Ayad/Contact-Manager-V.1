#include "Contact.h"
#include <iostream>
#include<fstream>

Contact::Contact()
{
    "\t\tNew contact created!\n\n";
    usersCount = 0;
}

void Contact::AddUser()
{
    if(usersCount<100)
    {
        User* newuser = new User;
        users[usersCount] = newuser;
        usersCount++;
    }else
    {
        cout << "\n\n\rError: you reached the maximum number of contacts which is [100]!\n";
    }
}

bool Contact::EditUser()
{
    cout << "\n\tEnter user id to edit : ";
    int id;
    cin>>id;
    for(int i=0;i<usersCount;i++)
    {
        if(users[i]->GetID() == id)
        {
            users[i]->Edit();
            return true;
        }
    }
    return false;
}

bool Contact::DeleteUser()
{
    int id;
    cout << "\n\tEnter user id to delete : ";
    cin>>id;
    for(int i=0;i<usersCount;i++)
    {
        if(users[i]->GetID() == id)
        {
            cout << "\n\tAre you really want to delete [ " << users[i]->GetFirstName() << ' ' << users[i]->GetLastName() << " ] ";
            cout << "\n\t [ y / n ]>>  ";
            string input;
            cin.ignore();
            getline(cin, input);
            if(input ==  "y" || input == "yes")
            {
                delete users[i];
                users[i] = users[usersCount-1];
                usersCount--;
                return true;
            }
            else if (input == "n" || input == "no")
            {
                return true;
            }
            else
                return false;
        }
    }
    return false;
}

void Contact::SearchUser() const
{
    bool found=0;
    cout << "\n\n\tEnter keyword[one word] to search for: ";
    string kword;
    cin>>kword;
    for(int i=0;i<usersCount;i++)
    {
        if(users[i]->Search(kword))
        {
            users[i]->Show();
            found=1;
        }
    }

    if(found)
    {
        cout << "\n\t\tDone !\n";
    }
    else
        cout << "\n\t\tNo users found\n";


}


void Contact::ShowAll() const
{
    for(int i=0;i<usersCount;i++)
    {
        users[i]->Show();
    }
}


void Contact::saveintofile() const
{
    cout << "\n\n\tEnter file name : ";
    string filename;
    // create file and if it already exist replace it using trunc
    cin>>filename;
    filename+=".txt";
    ofstream file;
    file.open(filename, ios::trunc);
    file.close();
    //file is ready !

    for(int i=0;i<usersCount;i++)
    {
        users[i]->saveintofile(filename);
    }

}


Contact::~Contact()
{
    //dtor
}
