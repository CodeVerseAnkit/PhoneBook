#include <iostream>
#include <map>
using namespace std;
// ---------- PhoneBook -----------
// Author: Ankit
// Date: 22_6_2025
// Project: PhoneBook
// Description: Simple phonebook app for simple use

//-----> App Interface (menu)
void menu()
{
	cout << " -------------------- PHONEBOOK -------------------- " << endl;
	cout << " 1. View contact \n 2. Add new contact \n 3. Delete contact \n 4. Search for contact \n 5. Dial contact \n 6. Exit PhoneBook\n " << endl;
}

//-----> using map with some default values
map<string, long long int> contact = {{"Police", 100}, {"Ambulance", 108}, {"Emergency", 112}};

//-----> 1. View Contact
void view_contact()
{
	cout << "Contact name    Contact number " << endl;
	for (auto c : contact)
	{
		cout << c.first << ":  " << c.second << endl;
	}
}

//-----> 2. Add New Contact
void add_new_contact()
{
	string name;
	long long int number;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter number: ";
	cin >> number;
	contact.emplace(name, number);
	cout << "Saving contact•••••\nSuccessfully saved in contact list " << endl;
}

//-----> 3. Delete Contact
void delete_contact()
{
	string name;
	cout << "To delete a contact from your contact list\nEnter person name: ";
	cin >> name;
	contact.erase(name);
	cout << "Deleting contact•••••\nSuccessfully deleted " << endl;
}

//-----> 4. Search for contact
void search_contact()
{
	string name;
	cout << "To search contact_\nEnter name: ";
	cin >> name;
	auto it = contact.find(name);
	if (it != contact.end())
	{
		cout << "Searching for contact••••• \nContact found successfully\nContact name= " << (*it).first << "; Contact number= " << (*it).second << endl;
	}
	else
	{
		cout << "Finding for contact•••••\nContact not found " << endl;
	}
}

//-----> 5. Dial contact
void dial_contact()
{
	long long int number;
	cout << "Dial number: ";
	cin >> number;
	for (int i = 0; i < 5; i++)
	{
		cout << "Calling " << number << "..... " << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << "Ringing..... " << endl;
	}
	cout << "Person is on another call, please wait...\nor Call back later " << endl;
}

//------> Main function
int main()
{
	int ch;
	do
	{
		menu();
		cout << "Select option: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			view_contact();
			break;
		case 2:
			add_new_contact();
			break;
		case 3:
			delete_contact();
			break;
		case 4:
			search_contact();
			break;
		case 5:
			dial_contact();
			break;
		case 6:
			cout << "Exiting PhoneBook•••••" << endl;
			break;
		default:
			cout << "Please Select available option! " << endl;
		}

	} while (ch != 6);
	return 0;
}