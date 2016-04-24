
/*********************************************************************
** Author:	Nicholas Brown
** Date:	8/12/15
** Description:	Patron Class Implementation:
**		Contains all of the Patron Class methods: getIdNum, getName,
**		getCheckedOutBooks, addBook, removeBook, getFineAmount,
**		amendFine, and a default constructor.
*********************************************************************/

#include <vector>		//for vector
#include <string>		//for string
#include "Patron.hpp"	//for Patron Class

using std::string;
using std::vector;

/***********************************************
**Default Constructor Description:
**	constructor which initializes the
**	fineAmount to 0, and sets idNum and name
**	using parameters
***********************************************/
Patron::Patron(string idn, string n)
{
	idNum = idn;
	name = n;
	fineAmount = 0;
}

/***********************************************
**getIdNum Description:
**	returns unique ID number for a Patron
***********************************************/
string Patron::getIdNum()
{
	return idNum;
}

/***********************************************
**getName Description:
**	returns the name for a Patron
***********************************************/
string Patron::getName()
{
	return name;
}

/***********************************************
**getCheckedOutBooks Description:
**	returns a vector of pointers to Books
**	that are currently checked out by the
**	Patron
***********************************************/
vector<Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
}

/***********************************************
**addBook Description:
**	adds a pointer to a Book to a Patron's
**	checkedOutBooks vector
***********************************************/
void Patron::addBook(Book* b)
{
	checkedOutBooks.push_back(b);
}

/***********************************************
**removeBook Description:
**	removes a pointer to a Book from a Patron's
**	checkedOutBooks vector
***********************************************/
void Patron::removeBook(Book* b)
{
	//loop through each book the Patron has checked out
	for (unsigned int bIndex = 0; bIndex < checkedOutBooks.size(); bIndex++)
	{
		//erase the book from the vector if it matches the argument passed
		if (checkedOutBooks[bIndex] == b)
		{
			checkedOutBooks.erase(checkedOutBooks.begin() + bIndex);
			return;
		}
	}
}

/***********************************************
**getFineAmount Description:
**	return total fine due by the Patron
***********************************************/
double Patron::getFineAmount()
{
	return fineAmount;
}


/***********************************************
**amendFine Description:
**	changes total amount of fine using passed
**	argument; adding to, or subracting from
**	the previous fineAmount.
***********************************************/
void Patron::amendFine(double amount)
{
	fineAmount += amount;
}

