#include <iostream>
#include <vector>
#include <iomanip>
#include<string>
using namespace std;

// Structure to represent an expense
struct Expense {
    string category;
    double amount;
    string description;
};

// Class to manage expenses
class ExpenseTracker {
private:
    vector<Expense> expenses;

public:
    // Function to add an expense
    void addExpense(string category, double amount, string description) {
        Expense newExpense = { category, amount, description };
        expenses.push_back(newExpense);
        cout << "Expense added successfully!\n";
    }

    // Function to display all expenses
    void viewExpenses() {
        if (expenses.empty()) {
            cout << "No expenses recorded yet.\n";
            return;
        }

        cout << "\n--- Expense History ---\n";
        cout << setw(15) << left << "Category"
            << setw(10) << "Amount"
            << "Description\n";
        cout << "-----------------------------------------\n";

        for (const auto& expense : expenses) {
            cout << setw(15) << left << expense.category
                << setw(10) << expense.amount
                << expense.description << endl;
        }
    }

    // Function to calculate the total expenses
    void calculateTotal() {
        double total = 0.0;
        for (const auto& expense : expenses) {
            total += expense.amount;
        }
        cout << "Total Expenses: " << total << endl;
    }
};

// Main function
int main() {
    ExpenseTracker tracker;
    int choice;

    do {
        cout << "\n--- Expense Tracker ---\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Calculate Total Expenses\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string category, description;
            double amount;
            cout << "Enter category (e.g., Food, Travel, Shopping): ";
            cin.ignore(); // Clear input buffer
            getline(cin, category);
            cout << "Enter amount: ";
            cin >> amount;
            cin.ignore(); // Clear input buffer
            cout << "Enter description: ";
            getline(cin, description);

            tracker.addExpense(category, amount, description);
            break;
        }
        case 2:
            tracker.viewExpenses();
            break;
        case 3:
            tracker.calculateTotal();
            break;
        case 4:
            cout << "Exiting the program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
