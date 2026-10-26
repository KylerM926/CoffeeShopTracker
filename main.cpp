#include <iostream>
#include <stdexcept>
#include "shopTracker.h"

using namespace std;

int main()
{
	map<string, int> drinks;
	vector<string> orderHistory;

	try 
	{
		int choice = 1;

		while (choice != 5){

		choice = get_menu_choice();

			switch(choice){
				case 1:
					display_all(drinks);
					break;
				case 2: 
					search_orders(drinks);
					break;
				case 3: 
					add_order(drinks, orderHistory);
					break;
				case 4:
					sort_order_history(orderHistory);
					display_order_history(orderHistory);
					break;
				case 5:
					cout << "Goodbye!\n";
					break;
			}
		}
	}
	catch (const runtime_error& e){
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}
