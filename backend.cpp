#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Item Structure / Class (OOP Implementation)
class Item {
public:
    int id;
    string title;
    double price;
    double originalPrice;
    string seller;
    string trust;
    string category;
    string status;

    // Constructor
    Item(int i, string t, double p, double op, string s, string tr, string cat, string stat) {
        id = i;
        title = t;
        price = p;
        originalPrice = op;
        seller = s;
        trust = tr;
        category = cat;
        status = stat;
    }

    // Display item details (Console / Backend log)
    void display() const {
        cout << "ID: " << id << " | Title: " << title 
             << " | Price: Rs." << price << " | Seller: " << seller 
             << " | Status: " << status << endl;
    }
};

// Item Manager Class implementing DSA & Core Logic
class ItemCatalogManager {
private:
    vector<Item> items;

public:
    // Add new item to the catalog
    void addItem(int id, string title, double price, double op, string seller, string trust, string category, string status) {
        items.push_back(Item(id, title, price, op, seller, trust, category, status));
    }

    // Display all items
    void showAllItems() {
        cout << "\n--- Campus Exchange Catalog ---" << endl;
        for (const auto& item : items) {
            item.display();
        }
    }

    // DSA Feature: Search Item by Title/Keyword
    void searchItem(string keyword) {
        cout << "\n--- Search Results for: \"" << keyword << "\" ---" << endl;
        bool found = false;
        for (const auto& item : items) {
            if (item.title.find(keyword) != string::npos) {
                item.display();
                found = true;
            }
        }
        if (!found) cout << "No items found matching the keyword." << endl;
    }

    // DSA Feature: Sort Items by Price (Low to High)
    void sortByPrice() {
        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.price < b.price;
        });
        cout << "\n--- Items Sorted by Price (Low to High) ---" << endl;
        showAllItems();
    }

    // Output JSON format (useful if connecting to a web frontend via API)
    void generateJSON() {
        cout << "\n[\n";
        for (size_t i = 0; i < items.size(); ++i) {
            cout << "  {\n"
                 << "    \"id\": " << items[i].id << ",\n"
                 << "    \"title\": \"" << items[i].title << "\",\n"
                 << "    \"price\": " << items[i].price << ",\n"
                 << "    \"seller\": \"" << items[i].seller << "\",\n"
                 << "    \"trust\": \"" << items[i].trust << "\",\n"
                 << "    \"status\": \"" << items[i].status << "\"\n"
                 << "  }" << (i == items.size() - 1 ? "" : ",") << "\n";
        }
        cout << "]\n";
    }
};

int main() {
    ItemCatalogManager manager;

    // Inserting sample college items
    manager.addItem(1, "Data Structures in C++ (Sahni)", 350.0, 650.0, "Kanav Arora", "4.9/5", "books", "Lowest Price!");
    manager.addItem(2, "Scientific Calculator (Casio fx-991ES)", 600.0, 900.0, "Paridhi Sachan", "4.8/5", "lab", "Available");
    manager.addItem(3, "Engineering Chemistry Lab Coat", 150.0, 300.0, "Rohan Chaudhary", "4.7/5", "stationery", "Lowest Price!");

    // Demonstrating Backend Operations for Evaluation
    manager.showAllItems();

    // Test Searching
    manager.searchItem("C++");

    // Test Sorting
    manager.sortByPrice();

    // Test JSON API Data Generation
    cout << "\n--- JSON Output for Frontend Integration ---";
    manager.generateJSON();

    return 0;
}