#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


// forward declarations for allowing ErrorHandler class to work for friend classes/functions
class Vehicle;
class Chevy;
class Dodge;
class Ferrari;
class Payment;

// class containing methods to handle user input errors
class ErrorHandler{
public:
    //allows methods to be used within other functions containing user input prompts

    friend Vehicle;
    friend Chevy;
    friend Dodge;
    friend Ferrari;
    friend Payment;
    friend string vehicleTypeChoice();
    friend string findVehicleBrand(string chosenType);
protected:
    static int checkError1(int x){
        x = 0;
        while(!(cin >> x && x == 1)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That was an invalid input, please try again! \n";
        }
        return x;
    }
    static int checkError2(int x){
        x = 0;
        while(!(cin >> x && x == 1 || x == 2)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That was an invalid input, please try again! \n";
        }
        return x;
    }
    static int checkError3(int x){
        x = 0;
        while(!(cin >> x && x == 1 || x == 2 || x == 3)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That was an invalid input, please try again! \n";
        }
        return x;
    }

    static int checkErrorPositiveInt(int x){
        x = 0;
        while(!(cin >> x && x > 0 && x <= 365)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That was an invalid input, please try again! \n";
        }
        return x;
    }
    static float checkErrorPositiveFloat(float x){
        x = 0.0;
        while(!(cin >> x && x > 0)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That was an invalid input, please try again! \n";
        }
        return x;
    }

};

// class Chevy, Dodge, Ferrari, and Payment inherit from this class
class Vehicle{
private:
    string status = "Vehicle is for rent";
public:
    friend ErrorHandler;
    string vehicleType;
    string vehicleModel;
    string vehicleBrand;
    float vehicleCost;
};

// Brands of Cars

// Derived Class
class Chevy: public Vehicle{
public:

    Chevy(float cost, string type){
        vehicleType = type;
        vehicleBrand = "Chevy";
        int vehicleTypeChoice;
        if(vehicleType == "Car"){
            cout << "Which type of Chevy " << vehicleType << " would you like? Please enter the "
                                                             "corresponding number below \n";
            cout << "1.) Malibu";
            vehicleTypeChoice = ErrorHandler::checkError1(vehicleTypeChoice);
            switch (vehicleTypeChoice){
                case 1:
                    vehicleModel = "Malibu";
                    vehicleCost = cost + 10;
            }
        }
        if(vehicleType == "Truck"){
            cout << "Which type of Chevy " << vehicleType << " would you like? Please enter the "
                                                             "corresponding number below \n";
            cout << "1.) Colorado \n 2.) Silverado 1500 \n";
            vehicleTypeChoice = ErrorHandler::checkError2(vehicleTypeChoice);
            switch(vehicleTypeChoice){
                case 1:
                    vehicleModel = "Colorado";
                    vehicleCost = cost + 10;
                case 2:
                    vehicleModel = "Silverado 1500";
                    vehicleCost = cost + 15;
            }
        }
        if(vehicleType == "SUV"){
            cout << "Which type of Chevy " << vehicleType << " would you like? Please enter the "
                                                             "corresponding number below \n";
            cout << "1.) Trax \n 2.) Equinox \n";
            vehicleTypeChoice = ErrorHandler::checkError2(vehicleTypeChoice);
            switch(vehicleTypeChoice){
                case 1:
                    vehicleModel = "Trax";
                    vehicleCost = cost + 10;
                case 2:
                    vehicleModel = "Equinox";
                    vehicleCost = cost + 12;
            }
        }
    }
};

// Derived Class
class Dodge: public Vehicle{
public:
    Dodge(float cost, string type){
        vehicleBrand = "Dodge";
        vehicleType = type;
        int vehicleTypeChoice;
        if(vehicleType == "Car"){
            cout << "Which type of Dodge " << vehicleType << " would you like? Please enter the "
                                                             "corresponding number below \n";
            cout << "1.) Challenger \n 2.) Charger \n";
            vehicleTypeChoice = ErrorHandler::checkError2(vehicleTypeChoice);
            switch(vehicleTypeChoice){
                case 1:
                    vehicleModel = "Challenger";
                    vehicleCost = cost + 20;
                case 2:
                    vehicleModel = "Charger";
                    vehicleCost = cost + 15;
            }
        }
        if(vehicleType == "Truck"){
            cout << "Which type of Dodge " << vehicleType << " would you like? Please enter the "
                                                             "corresponding number below \n";
            cout << " 1.) Ram 1500 \n 2.) Ram 2500 \n";
            vehicleTypeChoice = ErrorHandler::checkError2(vehicleTypeChoice);
            switch(vehicleTypeChoice){
                case 1:
                    vehicleModel = "Ram 1500";
                    vehicleCost = cost + 10;
                case 2:
                    vehicleModel = "Ram 2500";
                    vehicleCost = cost + 15;
            }
        }
        if(vehicleType == "SUV"){
            cout << "Which type of Dodge " << vehicleType << " would you like? Please enter the "
                                                             "corresponding number below \n";
            cout << "1.) Durango \n 2.) Journey \n";
            vehicleTypeChoice = ErrorHandler::checkError2(vehicleTypeChoice);
            switch(vehicleTypeChoice){
                case 1:
                    vehicleModel = "Durango";
                    vehicleCost = cost + 10;
                case 2:
                    vehicleModel = "Journey";
                    vehicleCost = cost + 12;
            }
        }
    }
};

//template for vehicle name for Ferrari
template <typename T>
T vehicleName(T x){
    return x;
};

// Derived Class
class Ferrari: public Vehicle{
public:
    Ferrari(float cost, string type){
        vehicleType = type;
        vehicleBrand = "Ferrari";
        if(vehicleType == "Car"){
            int vehicleTypeChoice;
            cout << "Which type of Ferrari " << vehicleType << " would you like? Please enter the "
                                                               "corresponding number below \n";
            cout << "1.) " << vehicleName<int>(458) << endl;
            cout << "2.) " << vehicleName<string>("Purosangue") << endl;
            vehicleTypeChoice = ErrorHandler::checkError2(vehicleTypeChoice);
            switch(vehicleTypeChoice) {
                case 1:{
                    vehicleModel = "458";
                    vehicleCost = cost + 60;
                    break;
                }
                case 2: {
                    vehicleModel = "Purosangue";
                    vehicleCost = cost + 50;
                    break;
                }
            }
        }
    }
};
// Derived Class
class Payment: public Vehicle{
protected:
    string securityCode;
    string cardNumber;

    const float tax = 1.06;
    const float damageWaiver = 24.99;
    const float roadsideProtection = 4.99;
    const float liabilityProtection = 12.99;

    float cashAmount;
    float change;
    float justVehiclePrice;

    int expMonth;
    int expYear;
    int userInput;
    int days;
    int choice;
    int choice2;
    int choice3;
    int wantReceipt;

    bool wantDamageWaiver;
    bool wantRoadsideProtection;
    bool wantLiabilityProtection;

public:
    Payment(Vehicle &userVehicle){
        cout << "How many days would you like to rent your" << " " << userVehicle.vehicleBrand << " "
             << userVehicle.vehicleModel << " " << "for? You can rent a vehicle for a "
                                                   "maximum of 365 days. Please enter as an integer value: ";
        days = ErrorHandler::checkErrorPositiveInt(days);
        userVehicle.vehicleCost *= days;
        justVehiclePrice = userVehicle.vehicleCost;
        cout << "Would you like to add a damage waiver for $24.99? Enter '1' for yes and '2' for no: ";
        choice = ErrorHandler::checkError2(choice);
        if(choice == 1){
            vehicleCost += damageWaiver;
            wantDamageWaiver = true;
        }
        cout << "Would you like to add a Roadside Protection Plan for $4.99? Enter '1' for yes and '2' for no: ";
        choice2 = ErrorHandler::checkError2(choice2);
        if(choice2 == 1){
            vehicleCost += roadsideProtection;
            wantRoadsideProtection = true;
        }
        cout << "Would you like to add a Liability Protection Plan for $12.99? Enter '1' for yes and '2' for no: ";
        choice3 = ErrorHandler::checkError2(choice3);
        if(choice3 == 1){
            vehicleCost += liabilityProtection;
            wantLiabilityProtection = true;
        }
        printf("Your total cost will be: $%.2f", userVehicle.vehicleCost);


        userVehicle.vehicleCost *= tax;
        userVehicle.vehicleCost = floor(userVehicle.vehicleCost * 100.0) / 100.0;
        cout << endl;
        printf("After tax your total comes out to: $%.2f", userVehicle.vehicleCost);
        cout << "\nEnter the number of your payment type: \n 1.) Cash \n 2.) Card \n 3.) Cancel \n";
        justVehiclePrice = floor(justVehiclePrice * 100.0) / 100.0;
        userInput = ErrorHandler::checkError3(userInput);
        switch(userInput){
            case 1:{
                cout << "You have chosen to pay with cash, please enter how much cash you will be using: ";
                cashAmount = ErrorHandler::checkErrorPositiveFloat(cashAmount);
                while(cashAmount < userVehicle.vehicleCost){
                    float addedPayment;
                    cout << "You have not entered enough payment, please choose how much more money you would like"
                            "to add. You still owe " << userVehicle.vehicleCost - cashAmount;
                    cin >> addedPayment;
                    cashAmount += addedPayment;
                }
                change = userVehicle.vehicleCost - cashAmount;
                printf("Your change is: $%.2f", -(change));
                cout << "\n Would you like a receipt for this transaction? Enter '1' for yes and '2' for no";
                wantReceipt = ErrorHandler::checkError2(wantReceipt);
                if(wantReceipt == 1){
                    fstream receipt;
                    receipt.open("User Receipt", ios::trunc | ios::out | ios::in);
                    receipt << "Vehicle Make:               " << userVehicle.vehicleBrand << endl;
                    receipt << "Vehicle Model:              " << userVehicle.vehicleModel << endl;
                    receipt << "Vehicle Type:               " << userVehicle.vehicleType << endl;
                    receipt << "Vehicle Price:              $" << justVehiclePrice << ".00" << endl;
                    if(wantDamageWaiver)
                        receipt << "Damage Waiver Addon:        $" << damageWaiver << endl;
                    if(wantRoadsideProtection)
                        receipt << "Roadside Protection Addon:  $" << roadsideProtection << endl;
                    if(wantLiabilityProtection)
                        receipt << "Liability Protection Addon: $" << liabilityProtection << endl;
                    receipt << "Total:                      $" << userVehicle.vehicleCost << endl;
                    receipt << "Return the vehicle within " << days << " days in order to avoid $100 late fee" << endl;
                    receipt << "Thank you for choosing to rent your car from Generic Car Dealership!";
                    receipt.close();
                }
                else{
                    cout << "Thank you! Have a good rest of your day!";
                }
                break;
            }
            case 2:{
                cout << "You have chosen to pay with card, please enter your card number below (16 digits, no spaces)";
                cin >> cardNumber;
                while(cardNumber.length() != 16){
                    cout << "You have entered an invalid card number. Make sure that you entered 16 digits or check"
                            "your card number. Please try again: ";
                    cin >> cardNumber;
                }
                cout << "Please enter the expiration month for your card:";
                cin >> expMonth;
                while(expMonth > 12 || expMonth <= 0){
                    cout << "You have entered an invalid expiration month. Make sure that you entered the right "
                            "number for the month. Please try again: ";
                    cin >> expMonth;
                }
                cout << "Please enter the expiration year for your card, only enter the two digits (Example 2025, "
                        "enter as '25'):";
                cin >> expYear;
                while(expYear > 99 || expYear < 0){
                    cout << "You have entered an invalid expiration year. Make sure that you entered the right "
                            "number for the month. Please try again: ";
                    cin >> expYear;
                }
                cout << "Please enter the security code for your card (3 digits on the back):";
                cin >> securityCode;
                while(securityCode.length() < 0 || securityCode.length() > 3){
                    cout << "You have entered an invalid expiration month. Make sure that you entered the right "
                            "number for the month. Please try again: ";
                    cin >> expMonth;
                }
                cout << "Thank you for entering all of your card information correctly! Would you like a "
                        "receipt for this transaction? Enter '1' for yes and '2' for no ";
                wantReceipt = ErrorHandler::checkError2(wantReceipt);
                if(wantReceipt == 1){
                    fstream receipt;
                    receipt.open("User Receipt", ios::trunc | ios::out | ios::in);
                    receipt << "Vehicle Make:               " << userVehicle.vehicleBrand << endl;
                    receipt << "Vehicle Model:              " << userVehicle.vehicleModel << endl;
                    receipt << "Vehicle Type:               " << userVehicle.vehicleType << endl;
                    receipt << "Vehicle Price:              $" << justVehiclePrice << ".00" << endl;
                    if(wantDamageWaiver)
                        receipt << "Damage Waiver Addon:        $" << damageWaiver << endl;
                    if(wantLiabilityProtection)
                        receipt << "Liability Protection Addon: $" << liabilityProtection << endl;
                    if(wantRoadsideProtection)
                        receipt << "Roadside Protection Addon:  $" << roadsideProtection << endl;
                    receipt << "Total:                      $" << userVehicle.vehicleCost << endl;
                    receipt << "Return the vehicle within " << days << " days in order to avoid $100 late fee" << endl;
                    receipt << "Thank you for choosing to rent your car from Generic Car Dealership!";
                    receipt.close();
                }
                else{
                    cout << "Thank you! Have a good rest of your day!";
                }
                break;
            }
            case 3:{
                cout << "You have canceled the transaction.";
                break;
            }
        }
    }
};

// asks the user what brand of vehicle they want
string findVehicleBrand(string chosenType){
    int brandChoice;
    cout << "You have indicated that you would like a: " << chosenType << endl;
    cout << "Which brand of " << chosenType << " would you like? Choose from the options below and enter the "
                                               "corresponding number: " << endl;
    if (chosenType == "Car") {
        cout << " 1.) Chevy \n 2.) Dodge \n 3.) Ferrari \n";
        brandChoice = ErrorHandler::checkError3(brandChoice);
        switch(brandChoice) {
            case 1: {
                return "Chevy";
            }
            case 2: {
                return "Dodge";
            }
            case 3: {
                return "Ferrari";
            }
        }
    }
    else {
        cout << " 1.) Chevy \n 2.) Dodge \n";
        brandChoice = ErrorHandler::checkError2(brandChoice);
        switch (brandChoice) {
            case 1: {
                return "Chevy";
            }
            case 2: {
                return "Dodge";
            }
        }
    }
}

// asks the user what type of vehicle they want
string vehicleTypeChoice(){
    cout << "Please enter the number of the type of vehicle you are looking for:" << endl;
    cout << " 1.) Car \n 2.) Truck \n 3.) SUV \n";
    int vehicleChoice;
    vehicleChoice = ErrorHandler::checkError3(vehicleChoice);
    switch(vehicleChoice) {
        case 1:{
            return "Car";
        }
        case 2:{
            return "Truck";
        }
        case 3:{
            return "SUV";
        }
    }
}

//int main (construction of the Vehicle and Payment)
int main() {
    float cost = 0;
    string chosenBrand;
    string chosenType;
    chosenType = vehicleTypeChoice();
    chosenBrand = findVehicleBrand(chosenType);
    if(chosenBrand == "Chevy"){
        if(chosenType == "Car")
            cost = 51.00;
        else if(chosenType == "Truck")
            cost = 71.00;
        else if(chosenType == "SUV")
            cost = 83.00;
        Chevy userVehicle(cost, chosenType);
        Payment thePayment(userVehicle);
    }
    else if(chosenBrand == "Dodge"){
        if(chosenType == "Car")
            cost = 51.00;
        else if(chosenType == "Truck")
            cost = 71.00;
        else if(chosenType == "SUV")
            cost = 83.00;
        Dodge userVehicle(cost, chosenType);
        Payment thePayment(userVehicle);
    }
    else if(chosenBrand == "Ferrari"){
        cost = 150;
        Ferrari userVehicle(cost, chosenType);
        Payment thePayment(userVehicle);
    }
    return 0;
}
