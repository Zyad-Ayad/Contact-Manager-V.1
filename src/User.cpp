#include "User.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
int User::NextUserId = 1;

User::User()
{
    this->id = this->NextUserId++;

    auto t = time(nullptr);
    auto tm = *localtime(&t);
    this->AddedDate = to_string(tm.tm_year+1900) + " - " + to_string(tm.tm_mon+1) + " - " + to_string(tm.tm_mday);

    cout << "\n\n\t\tNew User Added! ID: [ "<<this->id<<" ]\n\n";
    cin.ignore();
    string input= "";
    while(input.size()==0)
    {
        cout << "\n\tEnter user FirstName :  ";
        getline(cin, input);
        cout<<endl;
    }
    this->FirstName=input;

    input= "";
    while(input.size()==0)
    {
        cout << "\n\tEnter user LastName :  ";
        getline(cin, input);
        cout<<endl;
    }
    this->LastName=input;

    input= "";
    while(input!= "male" && input!= "female")
    {
        cout << "\n\tEnter user Gender [male | female] :  ";
        getline(cin, input);
        cout<<endl;
    }
    this->gender = input;

    input= "";
    while(input.size()==0)
    {
        cout << "\n\tEnter user city :  ";
        getline(cin, input);
        cout<<endl;
    }
    this->city = input;




    phones[0]= new Phone;
    emails[0]=new Email;
    addresses[0]=new Address;
    phonesCount=1;
    emailsCount=1;
    addressesCount=1;

    cout << "\n\t\tDone!\n";


}

void User::Show()
{
    cout << "\n\n===============================================\n"
    << "\nUser ID : "<<this->id
    << "\nFirst Name  : "<<this->FirstName
    << "\nLast Name   : " << this->LastName
    << "\nFull Name   : " << this->FirstName<<' '<<this->LastName
    << "\nGender      : " << this->gender
    << "\nCity        : "<<this->city
    << "\nAdded Date  : " << this->AddedDate
    << "\n\t\t------------=[ Phones ]=------------";
    for(int i=0;i<this->phonesCount;i++)
    {
        cout<< "\nPhone ["<<i+1<<"]       : "<< this->phones[i]->GetPhone()
        << "\nType ["<<i+1<<"]       : "<< this->phones[i]->GetType()
        << "\nDescription ["<<i+1<<"] : "<< this->phones[i]->GetDescription();
        cout <<"\n\t\t\t------";
    }
    cout<< "\n\t\t------------=[ Emails ]=------------";
    for(int i=0;i<this->emailsCount;i++)
    {
        cout<< "\nEmail ["<<i+1<<"]       : "<< this->emails[i]->GetEmail()
        << "\nType ["<<i+1<<"]       : "<< this->emails[i]->GetType()
        << "\nDescription ["<<i+1<<"] : "<< this->emails[i]->GetDescription();
        cout <<"\n\t\t\t------";
    }
    cout << "\n\t\t------------=[ Addresses ]=------------";
    for(int i=0;i<this->addressesCount;i++)
    {
        cout<< "\nAddress ["<<i+1<<"]       : "<< this->addresses[i]->GetPlace()
        << "\nType ["<<i+1<<"]       : "<< this->addresses[i]->GetType()
        << "\nDescription ["<<i+1<<"] : "<< this->addresses[i]->GetDescription();
        cout <<"\n\t\t\t------";
    }
    cout << "\n\n===============================================\n";

}

void User::Edit()
{

    cout << "\n\t\tChoose data to edit!..\n"
    << "\n\t[ 1 ] - General data\n"
    << "\n\t[ 2 ] - Phones data\n"
    << "\n\t[ 3 ] - Emails data\n"
    << "\n\t[ 4 ] - Addresses data\n\t>> ";
    string str;
    cin >>str;
    string input = "";
    if(str == "1")
    {
        cin.ignore();
        cout << "\n\t\tEnter new data or leave blank for no changes\n";
        cout << "\n\tFirst Name [ "<<this->FirstName<<" ] : ";
        getline(cin, input);
        if(input.size() != 0)
        {
            this->FirstName = input;
        }
        input = "";

        cout << "\n\tLast Name [ "<<this->LastName<<" ] : ";
        getline(cin, input);
        if(input.size() != 0)
        {
            this->LastName = input;
        }
        input = "";
        cout << "\n\tGender [ "<<this->gender<<" ] : ";
        getline(cin, input);
        if(input.size() != 0)
        {
            this->gender = input;
        }

        cout << "\n\tCity [ "<<this->city<<" ] : ";
        getline(cin, input);
        if(input.size() != 0)
        {
            this->city = input;
        }

    }else if (str == "2")
    {

        cout << "\n\tChoose ..\n";
        cout << "\n[ 1 ]- Edit existing phone";
        cout << "\n[ 2 ]- Add new phone";
        cout << "\n[ 3 ]- Remove existing phone number";
        cout << "\n[ 0 ]- Back";

        int input=-1;
        while(input < 0 || input >3)
        {
            cout << "\n\n>> ";
            cin>>input;
        }

        switch(input)
        {
        case 1:
            {
                cout << "\nEnter Phone number to edit >> ";
                string pte;
                cin >> pte;
                bool found = false;
                for(int i=0;i<phonesCount;i++)
                {
                    if(phones[i]->GetPhone() == pte)
                    {
                        phones[i]->Edit();
                        found=1;
                        break;
                    }
                }
                if(!found)
                {
                    cout << "\n\n\t\tPhone not found!\n";
                }

            }
            break;
        case 2:
            {
                if(phonesCount<5)
                {
                    phones[phonesCount]=new Phone;
                    phonesCount++;
                }
                else
                {
                    cout << "\n\n\tThis user has maximum number of phone numbers which is [5]\n";
                }
            }
            break;
        case 3:
            {
                cout << "\nEnter Phone number to delete >> ";
                string ptd;
                cin >> ptd;
                bool found = false;
                for(int i=0;i<phonesCount;i++)
                {
                    if(phones[i]->GetPhone() == ptd)
                    {
                        delete phones[i];
                        phones[i] = phones[phonesCount-1];
                        phonesCount--;
                        found=1;
                        break;
                    }
                }
                if(!found)
                {
                    cout << "\n\n\t\tPhone not found!\n";
                }
            }
            break;
        }



    }
    else if (str == "3")
    {
        cout << "\n\tChoose ..\n";
        cout << "\n[ 1 ]- Edit existing Email";
        cout << "\n[ 2 ]- Add new Email";
        cout << "\n[ 3 ]- Remove existing Email";
        cout << "\n[ 0 ]- Back";

        int input=-1;
        while(input < 0 || input >3)
        {
            cout << "\n\n>> ";
            cin>>input;
        }

        switch(input)
        {
        case 1:
            {
                cout << "\nEnter Email address to edit >> ";
                string ete;
                cin >> ete;
                bool found = false;
                for(int i=0;i<emailsCount;i++)
                {
                    if(emails[i]->GetEmail() == ete)
                    {
                        emails[i]->Edit();
                        found=1;
                        break;
                    }
                }
                if(!found)
                {
                    cout << "\n\n\t\Email not found!\n";
                }

            }
            break;
        case 2:
            {
                if(emailsCount<5)
                {
                    emails[emailsCount]=new Email;
                    emailsCount++;
                }
                else
                {
                    cout << "\n\n\tThis user has maximum number of Email addresses which is [5]\n";
                }
            }
            break;
        case 3:
            {
                cout << "\nEnter Email address to delete >> ";
                string etd;
                cin >> etd;
                bool found = false;
                for(int i=0;i<emailsCount;i++)
                {
                    if(emails[i]->GetEmail() == etd)
                    {
                        delete emails[i];
                        emails[i] = emails[emailsCount-1];
                        emailsCount--;
                        found=1;
                        break;
                    }
                }
                if(!found)
                {
                    cout << "\n\n\t\tEmail address not found!\n";
                }
            }
            break;
        }
    }
    else if (str == "4")
    {
        cout << "\n\tChoose ..\n";
        cout << "\n[ 1 ]- Edit existing Address";
        cout << "\n[ 2 ]- Add new Address";
        cout << "\n[ 3 ]- Remove existing Address";
        cout << "\n[ 0 ]- Back";

        int input=-1;
        while(input < 0 || input >3)
        {
            cout << "\n\n>> ";
            cin>>input;
        }

        switch(input)
        {
        case 1:
            {
                cout << "\nEnter Address[place] to edit >> ";
                string ate;
                cin >> ate;
                bool found = false;
                for(int i=0;i<addressesCount;i++)
                {
                    if(addresses[i]->GetPlace() == ate)
                    {
                        addresses[i]->Edit();
                        found=1;
                        break;
                    }
                }
                if(!found)
                {
                    cout << "\n\n\tAddress not found!\n";
                }

            }
            break;
        case 2:
            {
                if(addressesCount<5)
                {
                    addresses[addressesCount]=new Address;
                    addressesCount++;
                }
                else
                {
                    cout << "\n\n\tThis user has maximum number of Addresses which is [5]\n";
                }
            }
            break;
        case 3:
            {
                cout << "\nEnter address to delete >> ";
                string atd;
                cin >> atd;
                bool found = false;
                for(int i=0;i<addressesCount;i++)
                {
                    if(addresses[i]->GetPlace() == atd)
                    {
                        delete addresses[i];
                        addresses[i] = addresses[addressesCount-1];
                        addressesCount--;
                        found=1;
                        cout << "\n\n\t\tAddress Deleted!\n";
                        break;
                    }
                }
                if(!found)
                {
                    cout << "\n\n\t\tAddress not found!\n";
                }
            }
            break;
        }

    }

}


bool User::Search(string kword) const
{
    if(this->city == kword)
    {
        return true;
    }
    else if(this->FirstName == kword)
    {
        return true;
    }
    else if(this->LastName == kword)
    {
        return true;
    }
    else if(this->gender == kword)
    {
        return true;
    }


    for(int i=0;i<addressesCount;i++)
    {
        if(kword == this->addresses[i]->GetPlace() || kword == this->addresses[i]->GetType() || kword == this->addresses[i]->GetDescription())
            return true;
    }

    for(int i=0;i<emailsCount;i++)
    {
        if(kword == this->emails[i]->GetEmail() || kword == this->emails[i]->GetType() || kword == this->emails[i]->GetDescription())
            return true;
    }

    for(int i=0;i<phonesCount;i++)
    {
        if(kword == this->phones[i]->GetPhone() || kword == this->phones[i]->GetType() || kword == this->phones[i]->GetDescription())
            return true;
    }

    return false;
}

void User::saveintofile(string filename)
{

    ofstream file;
    file.open(filename, ios::app);

    file << "\n\n===============================================\n"
    << "\nUser ID : "<<this->id
    << "\nFirst Name  : "<<this->FirstName
    << "\nLast Name   : " << this->LastName
    << "\nFull Name   : " << this->FirstName<<' '<<this->LastName
    << "\nGender      : " << this->gender
    << "\nCity        : "<<this->city
    << "\nAdded Date  : " << this->AddedDate
    << "\n\t\t------------=[ Phones ]=------------";
    for(int i=0;i<this->phonesCount;i++)
    {
        file<< "\nPhone ["<<i+1<<"]       : "<< this->phones[i]->GetPhone()
        << "\nType ["<<i+1<<"]       : "<< this->phones[i]->GetType()
        << "\nDescription ["<<i+1<<"] : "<< this->phones[i]->GetDescription();
        file <<"\n\t\t\t------";
    }
    file<< "\n\t\t------------=[ Emails ]=------------";
    for(int i=0;i<this->emailsCount;i++)
    {
        file<< "\nEmail ["<<i+1<<"]       : "<< this->emails[i]->GetEmail()
        << "\nType ["<<i+1<<"]       : "<< this->emails[i]->GetType()
        << "\nDescription ["<<i+1<<"] : "<< this->emails[i]->GetDescription();
        file <<"\n\t\t\t------";
    }
    file << "\n\t\t------------=[ Addresses ]=------------";
    for(int i=0;i<this->addressesCount;i++)
    {
        file<< "\nAddress ["<<i+1<<"]       : "<< this->addresses[i]->GetPlace()
        << "\nType ["<<i+1<<"]       : "<< this->addresses[i]->GetType()
        << "\nDescription ["<<i+1<<"] : "<< this->addresses[i]->GetDescription();
        file <<"\n\t\t\t------";
    }
    file << "\n\n===============================================\n";

    file.close();

}


User::~User()
{
    //dtor
}
