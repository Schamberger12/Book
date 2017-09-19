#include "../../std_lib_facilities.h"

class Book {
public:
	enum Genre {fiction, nonfiction, children, periodical, biography};

	Book(int ISBN, int copyright, string title, string author, bool checked, Genre genre) {}
	vector <Book> books;
	void check_out() { checked = true; }
	void check_in() { checked = false; }
	void book_input_loop(int );
	friend ostream& operator<<(ostream& os, const Book& justdoit);
private:
	int ISBN, copyright;
	string title, author;
	bool checked;
	Genre genre;
};

vector <Book> books;


ostream& operator<< (ostream& os, Book const& justdoit) {
	os << justdoit.author << '\t';
	os << justdoit.title << '\t';
	os << justdoit.ISBN<< '\t';
	os << justdoit.copyright << '\t';
	if (justdoit.checked == true)
		os << "Checked out" << endl;
	else
		os << "Not checked out" << endl;
	return os;
	
}



void print_out_loop()
{
	for (int i = 0; i < books.size(); ++i) {
		cout << i + 1 << ". " << books[i] << endl;
	}
}

//inputting the info for each book.
void Book::book_input_loop(int numbooks) { 

	string tit, auth;
	int copyr;
	int isnumb;
	char checkchar;
	bool check;
	int bookGenreChoice;
	Genre bookGenre;

	for (int i = 0; i < numbooks; ++i) {
		cout << "What is the title and author of the book?" << endl;
		cin >> tit >> auth;
		cout << "What is the copyright year for this book?" << endl;
		cin >> copyr;
		cout << "What is the ISBN for this book?" << endl;
		cin >> isnumb;
		cout << "What genre is this book?" << endl << "1 for fiction, 2 for nonfiction, 3 for children's, 4 for perodical, 5 for biography." << endl;
		cin >> bookGenreChoice;
		switch (bookGenreChoice) {
		case '1':	bookGenre = fiction;
					break;
		case '2':	bookGenre = nonfiction;
					break;
		case '3':	bookGenre = children;
					break;
		case '4':	bookGenre = periodical;
					break;
		case '5':	bookGenre = biography;
					break;
		default:	break;
		}
		cout << "Is the book checked out?(y/n)" << endl;
		cin >> checkchar;
		if (checkchar == 'y')
			check = true;
		else
			check = false;


		Book justdoit(isnumb, copyr, tit, auth, check, bookGenre);
		books.push_back(justdoit);
	}	

	return; 
	
	
}



//function to choose a book to manipulate and report back with the book

int choose_book() {

	int book_choice;

	cout << "Which book would you like to do that to?" << endl;
	print_out_loop();
	
	cin >> book_choice;

	if ((book_choice > books.size()) || (book_choice < 0))
		cout << "That is not a valid choice, please try again" << endl;
	else 
		cout << books[book_choice - 1] << endl
		<< "This is book you wanted." << endl; 

	return book_choice;

}

void library_choice() {
	
	char library_choice;
	
	
	cout << "What would you like to do next?" << endl;
	
	

	cout << "1. Check out a book(c)" << endl;
	cout << "2. Return a book(r)" << endl;
	cout << "3. Leave the library(l)" << endl;
	
	cin >> library_choice;
	
	int book_choice = choose_book();
	
	if (library_choice == 'r') {
		books[book_choice - 1].check_in();
		cout << books[book_choice - 1];
	}
	else if (library_choice == 'c') {
		books[book_choice - 1].check_out();
		cout << books[book_choice - 1];
	}
	else if (library_choice == 'l')
		exit(0);
	else
		cout << "Not a valid choice, try again " << endl;
		
}





int main() {
	
	int numbooks;	 //determine what the patron would like to do with the books listed.
	Book justdoit();

	cout << "How many books would you like to place in this library?" << endl;
	cin >> numbooks;

	justdoit().book_input_loop(numbooks);
	
	library_choice();

	return 0;


}