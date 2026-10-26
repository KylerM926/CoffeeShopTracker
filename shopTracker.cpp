#include "shopTracker.h"

#include <algorithm>
#include <cctype>
#include <limits>
#include <stdexcept>

using namespace std;

// validation functions
int get_number(const string& prompt){
	int number;
	while (true)
	{
		cout << prompt;
		if (cin >> number && number > 0){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return number; //valid number
		}

		cout << "Please enter a valid positive number\n";

		if (cin.eof()){
			throw runtime_error("Input stream closed!");
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
}
int get_menu_choice(){
	cout << "\nCOFFEE SHOP TRACKER\n"
		<< "===================\n"
		<< "1. Display all drinks\n"
		<< "2. Search for a drink\n"
		<< "3. Add order\n"
		<< "4. Sort and display order history\n"
		<< "5. Exit\n\n";

		int choice;
		while (true){
			choice = get_number("Choice: ");

			if (choice >= 1 && choice <= 5){
				return choice;
			}

			cout << "Please choose an option between 1 and 5!\n";
		}
}

string get_required_text(const string& prompt){
	string text;

	while (true){
		cout << prompt;

		if (!getline(cin, text)){
			throw runtime_error("Input stream closed!\n");
		}

		if (text.find_first_not_of(" \t\r\n") != string::npos){
			return text;
		}

		cout << "This field cannot be empty!\n";
	}
}

void display_all(const map<string, int>& drinks){
	cout << "\nDRINK SUMMARY\n";

	if (drinks.empty())
	{
		cout << "No orders have been recorded yet.\n";
		return;
	}

	cout << "Drink : Total Orders\n";
	cout << "--------------------\n";

	display_map(drinks);
}
void search_orders(const map<string, int>& drinks){
	if (drinks.empty())
	{
		cout << "No orders to search\n";
		return;
	}

	string searchName = get_required_text("Enter drink name: ");

	auto found = find_if(drinks.begin(), drinks.end(), [&searchName](const auto& item)
	{
		return item.first == searchName;
	});

	if (found != drinks.end())
	{
		cout << "Drink: " << found->first << '\n';
		cout << "Total orders: " << found->second << '\n';
	} else 
	{
		cout << "Drink not found.\n";
	}
}

void add_order(map<string, int>& drinks, vector<string>& orderHistory){
	string drinkName = get_required_text("Enter drink name: ");
	int quantity = get_number("Enter quantity ordered: ");

	drinks[drinkName] += quantity;

	orderHistory.push_back(drinkName + " x " + to_string(quantity));

	cout << quantity << " order(s) of "
		<< drinkName << " added successfully.\n";
}

void sort_order_history(vector<string>& orderHistory){
	if (orderHistory.empty())
	{
		cout << "No order history to sort.\n";
		return;
	}

	sort(orderHistory.begin(), orderHistory.end(), 
	[](const string& first, const string& second)
	{
		return first < second;
	});

	cout << "Order history sorted alphabetically.\n";
}

void display_order_history(const vector<string>& orderHistory){
	cout << "\nORDER HISTORY\n";
	cout << "-------------\n";

	if (orderHistory.empty())
	{
		cout << "No orders have been recorded yet.\n";
		return;
	}

	for (const string& order : orderHistory)
	{
		cout << order << '\n';
	}
}


