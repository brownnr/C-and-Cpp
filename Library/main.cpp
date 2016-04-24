
#include <string>
#include <vector>
#include <iostream>
#include "Library.hpp"

using namespace std;

int main()
{

	Book b1("123", "War and Peace", "Tolstoy");
	Book b2("234", "Moby Dick", "Melville");
	Book b3("345", "Phantom Tollbooth", "Juster");
	Patron p1("abc", "Felicity");
	Patron p2("bcd", "Waldo");
	Library lib;
	lib.addBook(&b1);
	lib.addBook(&b2);
	lib.addBook(&b3);
	lib.addPatron(&p1);
	lib.addPatron(&p2);
	lib.checkOutBook("bcd", "234");
	for (int i = 0; i < 7; i++)
		lib.incrementCurrentDate();
	lib.checkOutBook("bcd", "123");
	lib.checkOutBook("abc", "345");
	for (int i = 0; i < 24; i++)
	{
		lib.incrementCurrentDate();
		cout << p2.getFineAmount() << endl;
	}
        cout << "pay fine of no patron:\n";
	string pay = lib.payFine("gfd", 0.4);
	cout << pay << endl;

        cout << "try to return wrong book\n";
	string retAtt2 = lib.returnBook("567");
	cout << retAtt2 << endl;

        cout << "return real book:\n";
	string retAtt = lib.returnBook("345");
	cout << retAtt << endl;
	
        cout << "request fake book:\n";
	string req2 = lib.requestBook("bcd", "658");
	cout << req2 << endl;

        cout << "fake patron requests book:\n";
	string chreqAtt = lib.requestBook("dfg", "345");
	cout << chreqAtt << endl;

	vector<Book*> p1V = p1.getCheckedOutBooks();
	vector<Book*> p2V = p2.getCheckedOutBooks();

        cout << "title p1 has checked out:\n";
	for (int i = 0; i < p1V.size(); i++)
		cout << p1V[i]->getTitle() << endl;

	cout << endl;

        cout << "titles p2 has:\n";
	for (int i = 0; i < p2V.size(); i++)
		cout << p2V[i]->getTitle() << endl;


	cout << endl << lib.getPatron("abc")->getName() << endl;
	cout << lib.getPatron("bcd")->getName() << endl;
	//cout << lib.getPatron("abc")->getName() << endl;

	cout << fixed << showpoint;
	cout << endl << lib.getPatron("abc")->getFineAmount() << endl;
	cout << lib.getPatron("bcd")->getFineAmount() << endl;
	//cout << lib.getPatron("abc")->getName() << endl;






	cin.get();

	return 0;
}


