#include "menu.h"
#include "ohms_calculator.h"
#include "resistor_decoder.h"
#include "op_amp_calculator.h"  // Include operational amplifier header

using namespace std;

/* 
Function:       print_main_menu
Input:          None
Output:         None
Description:    Prints the main menu to the console.
*/
void print_main_menu() 
{
    cout << "\n----------- Main menu -----------\n";
    cout << "|\t\t\t\t|\n";
    cout << "|\t1. Menu item 1\t\t|\n";
    cout << "|\t2. ohms_calculator\t|\n";
    cout << "|\t3. Menu item 3\t\t|\n";
    cout << "|\t4. resistor_decoder\t|\n";
    cout << "|\t5. Operational Amplifier Calculations\t|\n";  // Renamed for op-amp calculations
    cout << "|\t6. Exit\t\t\t|\n";
    cout << "|\t\t\t\t|\n";
    cout << "---------------------------------\n";
}

/* 
Function:       get_user_input
Input:          None
Output:         int       input       // A valid menu item number (1 to 5).
Description:    Prompts the user to select a menu item and validates the input.
*/
void main_menu() 
{
    // No input, no return value. Displays the main menu and gets user input.
    print_main_menu();
    int input = get_user_input();
    select_menu_item(input);
}

/* 
Function:       get_user_input
Input:          None
Output:         int       input       // A valid menu item number (1 to 5).
Description:    Prompts the user to select a menu item and validates the input.
*/
int get_user_input() {
    // No explicit input, returns the selected menu item number (1 to 6).
    int input;
    string input_string;
    bool valid_input = false;
    int menu_items = 6;       // Menu items limit

    do {
        cout << "\nSelect item: ";
        cin >> input_string;  // Input: user-provided menu option string
        valid_input = is_integer(input_string);
        if (valid_input == false) 
        {
            cout << "Enter an integer!\r\n";  // Output: prompt to enter an integer
        } 
        else 
        {
            input = stoi(input_string);  // Convert string to integer
            if (input >= 1 && input <= menu_items) 
            {
                valid_input = true;
            } 
            else 
            {
                cout << "Invalid menu item!\r\n";  // Output: prompt to enter a valid menu item
                valid_input = false;
            }
        }
    } 
    while (valid_input == false);

    return input;  // Return: a valid integer value representing the menu option
}

/* 
Function:       select_menu_item
Input:          int input             // User's menu selection
Output:         None
Description:    Calls the appropriate function based on the user's menu selection.
*/
void select_menu_item(int input) {
    switch (input) {
        case 1:
            menu_item_1();
            break;
        case 2:
            menu_item_2();             // Ohms Calculator
            break;
        case 3:
            menu_item_3();
            break;
        case 4:
            menu_item_4();
            break;
        case 5:
            menu_item_5();             // Operational Amplifier Calculations
            break;
        default:
            exit(1);  // Input 6: Exit the program
            break;
    }
}

/* 
Function:       is_integer
Input:          string    num         // String representation of a number
Output:         bool      is_valid    // True if the string is a valid integer
Description:    Checks if the input string represents a valid integer.
*/
bool is_integer(string num) {
    // Input: string num, representing the user input.
    // Return: boolean, true if num is a valid integer.
    return regex_match(num, regex("[+-]?[0-9]+"));
}

/* 
Function:       go_back_to_main
Input:          None
Output:         None
Description:    Prompts the user to input 'b' or 'B' to return to the main menu.
*/
void go_back_to_main() {
    // No explicit input, no return value. Prompts the user to input 'b' or 'B' to return to the main menu.
    std::string input;
    do {
        std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
        std::cin >> input;  // Input: user-provided character
    } while (input != "b" && input != "B");
    main_menu();  // Call: return to main menu
}

/* 
Function:       menu_item_1
Input:          None
Output:         None
Description:    Executes the functionality for menu item 1 and returns to the main menu.
*/
void menu_item_1()
{
    // No input, no return value. Executes Menu item 1's functionality and returns to the main menu.
    cout << "\n>> Menu 1\r\n";
    cout << "function performance \r\n";
    cout << "output\r\n";
    go_back_to_main();
}

/* 
Function:       menu_item_2
Input:          None
Output:         None
Description:    Executes the functionality for menu item 2 and returns to the main menu.
*/
void menu_item_2()
{
    // No input, no return value. Executes Menu item 2's functionality and returns to the main menu.
    cout << "\n>> ohms_calculator\r\n";
    calculateOhmsLaw();
    go_back_to_main();
}

/* 
Function:       menu_item_3
Input:          None
Output:         None
Description:    Executes the functionality for menu item 3 and returns to the main menu.
*/
void menu_item_3()
{
    // No input, no return value. Executes Menu item 3's functionality and returns to the main menu.
    cout << "\n>> Menu 3\n";
    cout << "function performance \n";
    cout << "output\r\n";
    go_back_to_main();
}

/* 
Function:       menu_item_4
Input:          None
Output:         None
Description:    Executes the functionality for menu item 4 and returns to the main menu.
*/
void menu_item_4()
{
    // No input, no return value. Executes Menu item 4's functionality and returns to the main menu.
    cout << "\n>> resistor_decoder\n";
    decodeResistorColor();
    go_back_to_main();
}

/* 
Function:       menu_item_5
Input:          None
Output:         None
Description:    Executes the functionality for menu item 5 and returns to the main menu.
*/
void menu_item_5()
{
    // No input, no return value. Executes operational amplifier calculations and returns to the main menu.
    cout << "\n>> Operational Amplifier Calculations\n";
    op_amp_main_menu();  // Call operational amplifier main menu function
    go_back_to_main();
}
