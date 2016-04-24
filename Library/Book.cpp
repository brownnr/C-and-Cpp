
/*********************************************************************
** Author:	Nicholas Brown
** Date:	8/12/15
** Description:	Book Class Implementation:
**		Contains all of the Book Class methods: getCheckOutLength, 
**		getIdCode, getTitle, getAuthor, getLocation, setLocation, 
**		getCheckedOutBy, setCheckedOutBy, getRequestedBy, 
**		setRequestedBy, getDateCheckedOut, setDateCheckedOut.
*********************************************************************/

#include <string>	//for string
#include "Book.hpp" //for Patron

using std::string;

/***********************************************
**Default Constructor Description:
**	constructor which sets idCode, title and
**	author from parameters, and initializes
**	checkedOutBy, requestedBy to NULL, also
**	setting location to ON_SHELF
***********************************************/
Book::Book(string idc, string t, string a)
{
	checkedOutBy = NULL;
	requestedBy = NULL;
	idCode = idc;
	title = t;
	author = a;
	location = ON_SHELF;
}

/***********************************************
**getCheckOutLength Description:
**	returns how long a Book can be checked out
***********************************************/
int Book::getCheckOutLength()
{	
	return CHECK_OUT_LENGTH;
}

/***********************************************
**getIdCode Description:
**	returns a Book's idCode
***********************************************/
string Book::getIdCode()
{
	return idCode;
}

/***********************************************
**getTitle Description:
**	returns a Book's title
***********************************************/
string Book::getTitle()
{
	return title;
}

/***********************************************
**getAuthor Description:
**	returns a Book's author
***********************************************/
string Book::getAuthor()
{
	return author;
}

/***********************************************
**getLocation Description:
**	returns a Book's Locale
***********************************************/
Locale Book::getLocation()
{
	return location;
}

/***********************************************
**setLocation Description:
**	sets a Book's Locale
***********************************************/
void Book::setLocation(Locale loc)
{
	location = loc;
}

/***********************************************
**getCheckedOutBy Description:
**	returns who checked out the Book
***********************************************/
Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
}

/***********************************************
**setCheckedOutBy Description
**	sets who checked out the Book
***********************************************/
void Book::setCheckedOutBy(Patron* p)
{
	checkedOutBy = p;
}

/***********************************************
**getRequestedBy Description:
**	returns who has requested the Book
***********************************************/
Patron* Book::getRequestedBy()
{
	return requestedBy;
}

/***********************************************
**setRequestedBy Description:
**	sets who is requesting the Book
***********************************************/
void Book::setRequestedBy(Patron* p)
{
	requestedBy = p;
}

/***********************************************
**getDateCheckedOut Description:
**	returns date the Book was checked out
***********************************************/
int Book::getDateCheckedOut()
{
	return dateCheckedOut;
}

/***********************************************
**setDateCheckedOut Description:
**	sets the date the Book was checked out
***********************************************/
void Book::setDateCheckedOut(int d)
{
	dateCheckedOut = d;
}

