/*
 * File Name: automobile.cpp
 * Program Description:
 * The program is for a parking lot. It enables the user to input the data of the parking lot he wishes to enter
 * into. If the parking space is available then the user is prompted to enter the license plate number, his
 * vehicle type and his entry time into the parking lot. Depending on the vehicle type further questions are
 * prompted to the user. Parking lot information is outputed if the user wishes to view and lastly depending
 * upon the vehicle type cost for parking is calculated for each parking slot.
 */

//Import of Libraries
#include <iostream>   //Standard Input/Output Library
#include <string>	  // String Type Library

using namespace std; //Using basic cout,cin,etc. with ease

class automobile  // Class (Parent) Creation
{
public:           //Class type and variable
	int license_plate;    //Integer to get license plate number
	float enter_time;    // Floating value for time
	void plate()   //Function to get initial details
	{
		cout<<"Enter your vehicle License plate number: ";
		cin>>license_plate;
		cout<<"Input your entry time: ";
		cin>>enter_time;
	}
	void display()  //Display function
	{
		cout<<"License Plate is "<<license_plate<<endl;
		cout<<"Entry Time is "<<enter_time<<endl;
	}
};
class bus : public automobile   //Child Class Creation
{
public:
	int passenger,time;  // Input Variables for passenger and finding time
	int exit_time,total_time,cost;  //Time calculation Variables
	void bus_capacity()     //Function for bus capacity Input
	{
		cout<<"Your current cost is $ 2"<<endl;  // Basic Cost Print
		cout<<"How many passengers are you allowed to carry: "; // Output for user to enter no of passengers he has
		cin>>passenger; // Storage of value
	}
	void payment()   //Payment Calculation Function
	{
		cout<<"Enter your entry time";  // Enter the entry time
		cin>>enter_time;               // Store the entry time
		cout<<"Enter your exit time";   // Enter the exit time
		cin>>exit_time;                 // Storage of exit time
		total_time=exit_time-enter_time;  // Calculate the waiting time in parking slot
		if (total_time>=1)  //Calculate the cost of parking
		{
			cost=total_time*2; // Total cost the consumer has to pay for using parking as bus vehicle
			cout<<"You have to pay: $ "<<cost<<endl;  // Print the statement
		}

	}
};
//end of child class bus
class car : public automobile   //Child Class Creation
{
public:
	string brand;  // Varibale for storing brand name of the car
	int exit_time,total_time,cost;   // Value storage as intergers variable declaration
	int enter_time;  // Variable declaration
	void car_brand()   // function to get brand name of car
	{
		cout<<"Your current cost is $ 1"<<endl;  //Basic car parking cost
		cout<<"What Brand is your car: ";  // Brand name prompt
		cin>>brand; // storage of the brand inputted
	}
	void payment()  // Payment function similar as declared in bus class
	{
		cout<<"Enter your entry time";
		cin>>enter_time;
		cout<<"Enter your exit time";
		cin>>exit_time;
		total_time=exit_time-enter_time;
		if (total_time>=1)   //Calculate the cost of parking
		{
			cost=total_time*1;
			cout<<"You have to pay: $ "<<cost<<endl;
		}

	}
};
//end of child class car
class truck : public automobile   //Child Class Creation
{
public:  // Class type
	// Varibale declaration
	int load;
	int exit_time,total_time,cost;
	int enter_time;
	void truck_load() //Function to ask how much load the truck carries
	{
		cout<<"Your current cost is $ 3"<<endl; //Basic truck parking cost
		cout<<"How many load your truck carries: ";  // Prompt to enter the load of the truck
		cin>>load;
	}
	void payment()  // Payment calculation similar as declared in bus class
	{
		cout<<"Enter your entry time";
		cin>>enter_time;
		cout<<"Enter your exit time";
		cin>>exit_time;
		total_time=exit_time-enter_time;
		if (total_time>=1)   //Calculate the cost of parking
		{
			cost=total_time*3;
			cout<<"You have to pay: $ "<<cost<<endl;
		}
	}

};
//end of child class car
//Main program begins here
int main()
{
	int i,choice;   // Varibale declaration to store integer values
	char vehicle_type[100];  // Variable declaration to store characters
	automobile A1[100];   //Object declaration for automobile class
	bus B1[100],B2[100];   // Objects declared for bus class
	car C1[100],C2[100],C3;  // Objects declared for car class
	truck T1[100],T2[100];  // Objects declared for truck class
	int space_avaliable=5,parked_vehicles;  // interger variables declared with size of the parking as 5 maximum and parked vehicles entered by user
	// Start of the logic
	do
	{
		// Menu display for the user
		cout<<"Enter the following numbers to perform the operation required: \n";
		cout<<"1 - To enter the details of the vehicle \n";
		cout<<"2 - To know details of the parking lot\n";
		cout<<"3 - To know the income \n";
		cin>>choice; // Store the user choice from the menu
		// As per user choice perform the task as programmed using switch statement
		switch (choice)
		{
		case (1):  // To enter the vehicle details
				cout<<"How many vehicle data you wish to enter\n";
				cin>>parked_vehicles;
				// If parking space avaliable then,
				if (parked_vehicles<=space_avaliable)
				{
					//Iteration loop storing one information at a time
					for (i=1;i<=parked_vehicles;i++)
					{
						cout<<"Parking Space No.: "<<i<<endl;
						A1[i].plate(); // Function call of class automobile
						end: // Label Declaration
						cout<<"Enter vehicle type (c for car, b for bus and t for truck): "<<endl;
						cin>>vehicle_type[i];
						switch (vehicle_type[i])
						{
						case ('b'): // if bus is the vehicle the user wishes to park
								B1[i].bus_capacity();
								break;
						case ('c'):  // If car is the vehicle the user wishes to park
								C1[i].car_brand();
								break;
						case ('t'):  // if truck has to be parked
								T1[i].truck_load();
								break;
						default:  // Any other option entered
							goto end;  // Jump to end label as declared in the code
						}
					}
				}
				else  // if no parking space avaliable
				{
					cout<<"No Space Available"<<endl;
				}
				break;
		case (2):  // Displays parking lot data
				cout<<"Displaying Data of Parking Lot";
				for (i=1;i<=parked_vehicles;i++)
				{
					cout<<"Parking Space No.: "<<i<<endl;
					A1[i].display();
					cout<<"Vehicle Type is: "<<vehicle_type[i]<<endl;
				}
				break;
		case (3): // Payment of parking lot
				{
				for (i=1;i<=parked_vehicles;i++) // for all the cars present
				{
					if (vehicle_type[i]=='b') //Bus payment function call condition
					{
						B2[i].payment();
					}
					else if (vehicle_type[i]=='c') // Car payment function call condition
					{
						C2[i].payment();
					}
					else if (vehicle_type[i]=='t') // truck payment function call condition
					{
						T2[i].payment();
					}
				}

				}

		}
	}
	// continue to excute the program until 1=0; Infinite looping condition
while (1);
}
// End of the program
