# CoffeeShopTracker

## Description
The Coffee Shop Tracker is a C++ console application that manages coffee shop orders. Users can view 
drink totals, search for drinks, add orders, and sort and display order history. 
The program also validates user input and handles errors using exceptions.

### STL Containers
map<string, int>:Stores drink names and their total order quantities. A map keeps drink names 
sorted alphabetically and makes it easy to update totals.

vector<string>:Stores individual orders as strings, such as "Latte x 2". 
A vector can grow as new orders are added and allows the history to be sorted.

### STL Algorithms
find_if():Searches the map for a drink matching the name entered by the user.
sort():Sorts the order history alphabetically using a comparison lambda.

### Lambda Expressions
I used two lambda expressions in my program.

The lambda in search_orders() is [&searchName](const auto& item). It captures searchName by 
reference, accepts a map, and returns true if the drink name matches the search.

The lambda in sort_order_history() is [](const string& first, const string& second). it 
accepts two strings, captures no outside variables, and returns true when the first string 
comes before the second string alphabetically.

### Programming Decisions
I separated the code into header, implementation, and main files to keep it organized.
I also created input-validation functions to prevent repeated code and used
exception handling to manage input errors.
