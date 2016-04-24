
/*********************************************************************
** Author:	Nicholas Brown
** Date:	8/12/15
** Description:	Library Class Implementation:
**		Contains the Library Class methods addBook, addPatron
**		checkOutBook, returnBook, requestBook, payFine,
**		incrementCurrentDate, getPatron, getBook, and a default
**		constructor.
*********************************************************************/

#include <vector>
#include <string>
#include "Library.hpp"

using std::string;
using std::vector;

/***********************************************
**Default Constructor Description:
**	constructor which sets currentDate to 0
***********************************************/
Library::Library()
{
	currentDate = 0;
}

/***********************************************
**addBook Description:
**	method that adds a new Book to the vector of
**	holdings
***********************************************/
void Library::addBook(Book* b)
{
	holdings.push_back(b);
}

/***********************************************
**addPatron Description:
**	method that adds a new Patron to vector of
**	members
***********************************************/
void Library::addPatron(Patron* p)
{
	members.push_back(p);
}

/*******************************************************
**checkOutBook Description:
**	if the specified Book is not in the Library,
**		return "book not found"
**	if the specified Patron is not in the Library,
**		return "patron not found"
**	if the specified Book is already checked out,
**		return "book already checked out"
**	if the specified Book is on hold by another
**		Patron, return "book on hold by other patron"
**	otherwise update the Book's checkedOutBy,
**		dateCheckedOut and Location; if the Book
**		was on hold for this Patron, update requestedBy;
**		update the Patron's checkedOutBooks; return
**		"check out successful"
*******************************************************/
string Library::checkOutBook(string pID, string bID)
{
	//find if Book and/or Patron exist//
	if (getBook(bID) == NULL)
		return "Book not found.";
	

	if (getPatron(pID) == NULL)
		return "Patron not found.";
	else
	{
		//initiate local pointers if Book and Patron exist//
		Book* bPtr = getBook(bID);
		Patron* pPtr = getPatron(pID);

		//find location of Book//
		if (bPtr->getLocation() == CHECKED_OUT)
			return "Book already checked out.";
		else if (bPtr->getLocation() == ON_HOLD_SHELF && 
				bPtr->getRequestedBy() != pPtr)
			return "Book is on hold by another Patron.";
		
		//set Book's checkedOutBy, dateCheckedOut, location & requestedBy//
		else
		{
			bPtr->setCheckedOutBy(pPtr);
			bPtr->setDateCheckedOut(currentDate);
			bPtr->setLocation(CHECKED_OUT);
			bPtr->setRequestedBy(NULL);

			//add Book to Patron's checkedOutBooks//
			pPtr->addBook(bPtr);

			//check out was successful//
			return "Check out successful.";
		}
	}
}


/*******************************************************
**returnBook Description:
**	if the specified Book is not in the Library, return
**		"book not found"
**	if the Book is not checked out, return "book already
**		in library"
**	update the Patron's checkedOutBooks; update the
**		Book's location depending on whether another
**		Patron has requested it; update the Book's
**		checkedOutBy; return "return successful"
*******************************************************/
string Library::returnBook(std::string bID)
{
	//find if Book exists//
	if (getBook(bID) == NULL)
		return "Book was not found.";
	
	//find if Book //
	if (getBook(bID)->getLocation() != CHECKED_OUT)
		return "Book is already in Library.";
	else
	{
		//initiate local pointers if Book exists and is not CHECKED_OUT//
		Book* bPtr = getBook(bID);
		Patron* pPtr = bPtr->getCheckedOutBy();

		//remove Book from Patron's checkOutBooks//
		pPtr->removeBook(bPtr);

		//set Book's location based on request status//
		if (bPtr->getRequestedBy() == NULL)
			bPtr->setLocation(ON_SHELF);
		else
			bPtr->setLocation(ON_HOLD_SHELF);

		//set Book's checkedOutBy//
		bPtr->setCheckedOutBy(NULL);

		//return was successful//
		return "Return successful.";
	}
}

/*******************************************************
**requestBook Description:
**	if the specified Book is not in the Library, return
**		"book not found"
**	if the specified Patron is not in the Library, return
**		"patron not found"
**	if the specified Book is already requested by another
**		Patron, return "book on hold by other patron"
**	update the Book's requestedBy; if the Book is on the
**		shelf, update its location to on hold; return
**		"request successful"
*******************************************************/
string Library::requestBook(std::string pID, std::string bID)
{
	//find if Book exists//
	if (getBook(bID) == NULL)
		return "Book not found.";
	
	//find if Patron exists//
	if (getPatron(pID) == NULL)
		return "Patron not found.";

	//set Book's requestedBy and/or location//
	//based on current location//
	if (getBook(bID)->getLocation() == ON_HOLD_SHELF)
		return "Book on hold by another Patron.";
	else
	{
		//initiate local pointers if Book is not already on hold//
		Patron* pPtr = getPatron(pID);
		Book* bPtr = getBook(bID);

		//set Book's requestedBy and location//
		bPtr->setRequestedBy(pPtr);
		if (bPtr->getLocation() == ON_SHELF)
		{
			bPtr->setLocation(ON_HOLD_SHELF);
		}

		//request was successful//
		return "Request successful.";
	}
}

/*******************************************************
**payFine Description:
**	takes as a parameter the amount that is being paid
**		(not the negative of that amount)
**	if the specified Patron is not in the Library, return
**		"patron not found"
**	use amendFine to update the Patron's fine; return
**		"payment successful"
*******************************************************/
string Library::payFine(std::string pID, double payment)
{
	//find if Patron exists//
	if (getPatron(pID) == NULL)
		return "Patron not found.";
	else
	{
		//make payment negative here so it will be//
		//subtracted rather than added in amendFine//
		payment = 0 - payment;

		//apply payment to Patron's fine//
		getPatron(pID)->amendFine(payment);

		//payment was successful//
		return "Payment successful.";
	}
}

/*******************************************************
**incrementCurrentDate Description:
**	increment current date; increase each Patron's fines
**		by 10 cents for each overdue Book they have
**		checked out (using amendFine)
**	If a book is checked out on day 0, then on day 1,
**		the patron has had it for 1 day.  On day 21, the
**		patron has had it for 21 days, so it is still not
**		overdue.  On day 22, the book is overdue and
**		fines will be charged.
*******************************************************/
void Library::incrementCurrentDate()
{
	//increment currentDate first//
	currentDate++;

	//loop through Patrons//
	for (unsigned int pIndex = 0; pIndex < members.size(); pIndex++)
	{
		//set local pointer and vector only if the//
		//Patron has at least one Book checked out//
		if (members[pIndex]->getCheckedOutBooks().size() > 0)
		{
			Patron* pPtr = members[pIndex];
			vector<Book*> bVector = pPtr->getCheckedOutBooks();

			//loop through Patron's checkedOut Books//
			for (unsigned int bIndex = 0; bIndex < bVector.size(); bIndex++)
			{
				

				//initiate local variables//
				int date = bVector[bIndex]->getDateCheckedOut();
				int chOutDate = bVector[bIndex]->getCheckOutLength();

				//add fine if Book is overdue//
				if (currentDate > chOutDate + date)
					pPtr->amendFine(.10);
			}
		}
	}
}

/***********************************************
**getPatron Description:
**	method that returns a pointer to the Patron
**	corresponding to the ID parameter, or NULL
**	if no such Patron is a member
***********************************************/
Patron* Library::getPatron(string pID)
{
	//loop through the Patrons//
	for (unsigned int pIndex = 0; pIndex < members.size(); pIndex++)
	{
		//return the Patron if they exist//
		if (members[pIndex] != NULL && members[pIndex]->getIdNum() == pID)
			return members[pIndex];
	}

	//return NULL if not found//
	return NULL;
}

/***********************************************
**getBook Description:
**	method that returns a pointer to the Book
**	corresponding to the ID parameter, or NULL
**	if no such Book is in the holdings
***********************************************/
Book* Library::getBook(string bID)
{
	//loop through the Patrons//
	for (unsigned int bIndex = 0; bIndex < holdings.size(); bIndex++)
	{
		//return the Patron if they exist//
		if (holdings[bIndex] != NULL && holdings[bIndex]->getIdCode() == bID)
			return holdings[bIndex];
	}

	//return NULL if not found//
	return NULL;
}

