#pragma once
#ifndef MEHLHOFF_SHOPTRACKER_H
#define MEHLHOFF_SHOPTRACKER_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

template <typename Key, typename Value>

void display_map(const map<Key, Value>& items)
{
    if (items.empty())
    {
        cout << "No data available.\n";
        return;
    }

    for (const auto& item : items)
    {
        cout << item.first << " : " << item.second << '\n';
    }
}

int get_number(const string& prompt);
int get_menu_choice();
string get_required_text(const string& prompt);

void display_all(const map<string, int>& drinks);
void search_orders(const map<string, int>& drinks);
void add_order(map<string, int>& drinks, vector<string>& orderHistory);
void sort_order_history(vector<string>& orderHistory);
void display_order_history(const vector<string>& orderHistory);

#endif
