// to do list app

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib> // For system()
using namespace std;

void clearScreen();
void mainMenu();
string removeLine(string tasks, int removeIndex);

int main()
{
	// launching graphics
	this_thread::sleep_for(chrono::milliseconds(500)); // 0.5 sec delay
	cout << "     TO__\n";
	this_thread::sleep_for(chrono::milliseconds(500)); // 0.5 sec delay
	cout << "     DO__\n";
	this_thread::sleep_for(chrono::milliseconds(500)); // 0.5 sec delay
	cout << "     LIST\n\n";
	this_thread::sleep_for(chrono::milliseconds(500)); // 0.5 sec delay
	cout << "Developed by: ";
	this_thread::sleep_for(chrono::milliseconds(500)); // 0.5 sec delay
	cout << "\nAbdElrhman Mohamed.\n\n";
	this_thread::sleep_for(chrono::seconds(1)); // 1 sec delay

	mainMenu();
}

string choice;
string tasks = "";

void mainMenu() {
	do {
		clearScreen();
		// display main menue
		cout << "a. View tasks\n";
		cout << "b. Add new task\n";
		cout << "c. Remove task\n";
		cout << "d. Exit\n";
		cout << "Enter your choice: ";
		getline(cin, choice);

		// Handle user choice
		// Check for valid choices
		if (choice != "a" && choice != "A" && choice != "b" && choice != "B" &&
			choice != "c" && choice != "C" && choice != "d" && choice != "D") {
			clearScreen();
			continue; // Skip to the next iteration of the loop
		}
		else if (choice == "a" || choice == "A") {
			// handeling empty lists
			if (tasks == "") {
				clearScreen();
				cout << "Viewing tasks...\n";
				cout << "\nNo tasks to view!\n";

				cout << "\nReturn to main menu (press any button)\n"; // ask user to return to main menu

				string exit_to_menu;
				getline(cin, exit_to_menu);
				if (exit_to_menu == "y" || exit_to_menu == "Y") {
					mainMenu();
				}
			}
			else {
				clearScreen();
				cout << "Viewing tasks...\n";
				cout << tasks; // print all saved tasks
				cout << "\n\nReturn to main menu (press any button)\n"; // ask user to return to main menu

				string exit_to_menu;
				getline(cin, exit_to_menu);
				if (exit_to_menu == " " || exit_to_menu == " ") {
					mainMenu();
				}
				else {
					mainMenu();
				}
			}
		}
		else if (choice == "b" || choice == "B") {
			clearScreen();
			cout << "Adding a new task...\n\n";

			// getting tasks
			bool gettingTasks = true;
			do
			{
				tasks += "\n."; // print new line after taking the second task
				string task; // middle parameter to take input from user and save it

				getline(cin, task); // get parameter task
				tasks += task; // save to list

				cout << "Do you want to add more tasks? (y, n) "; // loop for more inputs
				string answer;
				getline(cin, answer);

				if (answer == "n" || answer == "N") {
					gettingTasks = false;
				}
				else if (answer == "y" || answer == "Y") {
					gettingTasks = true;
				}
				else {

					while (answer != "n" && answer != "N" && answer != "y" && answer != "Y") {
						cout << "Invalid choice. Please try again (y, n): ";
						getline(cin, answer);
					}
					if (answer == "n" || answer == "N") {
						gettingTasks = false;
					}
					else if (answer == "y" || answer == "Y") {
						gettingTasks = true;
					}
				}

			} while (gettingTasks == true);

		}
		else if (choice == "c" || choice == "C") {
			if (tasks == "") {
				clearScreen();
				cout << "Removing a task...\n\n";
				cout << "No tasks to be removed!\n";
				this_thread::sleep_for(chrono::seconds(1));
				mainMenu();
			}
			else {
				clearScreen();
				cout << "Removing a task...\n";
				int removeIndex;
				cout << "\nWhich line do you want to remove (1, 2, 3, ...)? "; // taking the line index
				cin >> removeIndex;

				// Make sure to check if the index is valid
				if (removeIndex > 0) {
					tasks = removeLine(tasks, removeIndex);
					cout << "Task removed!\n";
				}
				else {
					cout << "Invalid index. No task removed.\n";
				}
				this_thread::sleep_for(chrono::seconds(1)); // delay 1 sec till user read the message
			}
		}
		else if (choice == "d" || choice == "D") {
			clearScreen();
			cout << "Exiting the program...Goodbye!\n";
			this_thread::sleep_for(chrono::seconds(1)); // wait 1 sec until the user see the massage then exit
			break;
		}
	} while (choice != "D" && choice != "d");
}

// function for removing tasks
string removeLine(string tasks, int removeIndex)
{
	string updated_tasks = "";
	int indexCounter = 1;
	for (int i = 1; i <= tasks.length(); i++) {
		if (tasks[i] == '\n') {
			indexCounter++;
		}
		else if (indexCounter == removeIndex) {
			continue; // skip all line itirations till indexCounter is updated
		}
		updated_tasks += tasks[i];
	}
	return updated_tasks;
}

// Function to clear the screen
void clearScreen()
{
#ifdef _WIN32
	system("cls");  // Use "cls" on Windows
#else
	system("clear");  // Use "clear" on Linux/macOS
#endif
}