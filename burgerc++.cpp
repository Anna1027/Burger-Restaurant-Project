#include<iostream>
#include <iomanip>
#include <cctype>
using namespace std;

int main() {
  cout<<"Welcome to Burger House !\n";
  cout<<"What would you like to order ? Please select the burger choices:\n"<<"\n";
  
	double cheeseburgerCost = 2.99, baconburgerCost = 3.99, chickenburgerCost = 4.99;
	double cheeseburgerPrice = 5.99, baconburgerPrice = 6.99, chickenburgerPrice = 7.99, orderTotal = 0.0;
	double deliveryFee = 2.00, tax = 0.15;
	int totalcheeseburgerCount = 0, totalbaconburgerCount = 0, totalchickenburgerCount = 0, cheeseburgerCount = 0, baconburgerCount = 0, chickenburgerCount = 0;
	double  deliveryTotal = 0, taxTotal = 0;

	char orderMore = 'y', choice, orderType;
	cout << fixed;

	// start outside while
	char resturantisOpen = 'y';
	while (resturantisOpen == 'y') {

		cheeseburgerCount = 0, baconburgerCount = 0, chickenburgerCount = 0;
		orderMore = 'y';
		orderTotal = 0;
		// reset customer counts = 0

		while (orderMore == 'y') {
			cout << "Cheeseburger (A):\nBaconburger (B):\nChickenburger (C):"<<"\n";

      cout<<"Please enter a letter to order your burger:";
			cin >> choice;
			choice = toupper(choice);

			if (choice == 'A') {
				cheeseburgerCount++;
				orderTotal += cheeseburgerPrice;

				cout << "Adding cheeseburger to order. Your total is now $" << setprecision(2) << orderTotal << "\n";
			}
			else if (choice == 'B') {
				baconburgerCount++;
				orderTotal += baconburgerPrice;
				cout << "Adding baconburger to order. Your total is now $" << setprecision(2) << orderTotal << "\n";

			}
			else if (choice == 'C') {
				chickenburgerCount++;
				orderTotal += chickenburgerPrice;
				cout << "Adding chickenburger to order. Your total is now $" << setprecision(2) << orderTotal << "\n";

			}
			else {
				cout << "Sorry I do not recognize your selection\n";

			}
			cout << "Would you like to order someting else? (y/n)";
			cin >> orderMore;

			orderMore = tolower(orderMore);
		}

		cout << fixed;
		cout << "Enter your order type: ('t' for takeout, 'd' for dinein)";
		cin >> orderType;


		cout << "\nThank you for your order!\n\n";
		if (cheeseburgerCount > 0)
			cout << "\n" << cheeseburgerCount << " cheeseburger $" << setprecision(2) << cheeseburgerCount*cheeseburgerPrice;

		if (baconburgerCount > 0)
			cout << "\n" << baconburgerCount << " baconburger\t" "$" << setprecision(2) << baconburgerCount*baconburgerPrice;

		if (chickenburgerCount > 0)
			cout << "\n" << chickenburgerCount << " chickenburger\t" "$" << setprecision(2) << chickenburgerCount*chickenburgerPrice;

		if (orderType == 't')
		{
			orderTotal += deliveryFee;
			cout << "\nTax: $ " << tax *orderTotal << endl;
			taxTotal += tax*orderTotal;
			orderTotal += orderTotal*tax;
			

			cout << "\nYour entered takeout!\n";

			cout << "deliveryFee: $ " << deliveryFee << "\n";
			deliveryTotal += deliveryFee;
		}

		if (orderType == 'd')
		{
			cout << "Tax: $ " << tax *orderTotal << endl;
			cout << "dinein:" << tax << endl;
			taxTotal += tax*orderTotal;
			orderTotal += orderTotal*tax;

		}


		cout << "Order Total is $ " << orderTotal << endl;

		totalcheeseburgerCount += cheeseburgerCount;
		totalbaconburgerCount += baconburgerCount;
		totalchickenburgerCount += chickenburgerCount;

		cout << "Is your resturant still open?";
		cin >> resturantisOpen;
	}

	

	// calc profits

	double cheeseProfit = totalcheeseburgerCount*(cheeseburgerPrice - cheeseburgerCost);
	double baconburgerProfit = totalbaconburgerCount*(baconburgerPrice - baconburgerCost);
	double chickenburgerProfit = totalchickenburgerCount*(chickenburgerPrice - chickenburgerCost);
	

	    cout << "\nThe profit for cheeseburger is $" << cheeseProfit<<"\n";
		cout << "\nThe profit for baconburger is $" << baconburgerProfit<<"\n";
		cout << "\nThe profit for chickenburger is $" << chickenburgerProfit<<"\n";

		cout << "\nThe number of cheeseburger ordered is " << totalcheeseburgerCount << "\n";
		cout << "\nThe number of baconburger ordered is " << totalbaconburgerCount << "\n";
		cout << "\nThe number of chickenburger ordered is " << totalchickenburgerCount << "\n";


		cout << "the total profit is $ " << cheeseProfit + baconburgerProfit + chickenburgerProfit << endl;

		cout << "the deliveryTotal is $ " << deliveryTotal << "\n";
		cout << "The taxTotal is $ " << taxTotal;


	

	return 0;
}
