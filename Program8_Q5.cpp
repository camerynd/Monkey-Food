#include<iostream>
using namespace std;
const int ROW = 3, COLUMN = 5;//constants to hold number of rows and columns
void get_monkey_data(double data[][COLUMN], string name[], string day[], double& total);//function prototypes
double average_the_data(double total);
double get_lowest_number(double data[][COLUMN]);
double get_highest_number(double data[][COLUMN]);
void report(double average, double least, double most);
int main()
{
    double monkeyData[ROW][COLUMN], totalFoodEaten;//declaring 2d array that holds data on the monkeys
    string monkeyName[ROW] = {"Curious George", "Moon Watcher", "Donkey Kong"};//array to hold three monkey names
    string dayOfWeek[COLUMN] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};// array to hold five week days
    get_monkey_data(monkeyData, monkeyName, dayOfWeek, totalFoodEaten);//function call
    double dailyAverage = average_the_data(totalFoodEaten);//functions being called and assigning returned values ti new variables
    double leastFoodEaten = get_lowest_number(monkeyData);
    double mostFoodEaten = get_highest_number(monkeyData);
    report(dailyAverage, leastFoodEaten, mostFoodEaten);//displaying data
    return 0;
}
void get_monkey_data(double data[][COLUMN], string name[], string day[], double& total)//function to get user input and assign 
{                                                                                      //to elements of monkeydata array
    int countOne, countTwo;
    for(countOne = 0; countOne < ROW; countOne++)//double for loop to fill a 2d array
    {   for(countTwo = 0; countTwo < COLUMN; countTwo++)
        {   cout << "Please enter the pounds of food eaten by " << name[countOne] << " on " << day[countTwo] << ": ";//displays 
            cin >> data[countOne][countTwo];                                                             //correct name and day of week
            if(data[countOne][countTwo] < 0)//input validation
            {   cout << endl << "ERROR: POSITIVE NUMBERS ONLY" << endl << "Please enter the pounds of food eaten by ";
                cout << name[countOne] << " on " << day[countTwo] << ": ";
                cin >> data[countOne][countTwo];
            }
            total += data[countOne][countTwo];//adding each piece of input to be used later
        } 
        cout << endl;
    }
}
double average_the_data(double total)//function whichtakes the totl from previous function and divides by number of data 
{                                         //items to get average
    int inputAmount = 15;
    double average = total / inputAmount;
    return average;//returns average
}
double get_lowest_number(double data[][COLUMN])//function to determine what the lowest number in the set of data is
{
    double low = data[0][0];//sets low to first item in array
    int countOne, countTwo;
    for(countOne = 0; countOne < ROW; countOne++)//double for loop to test each element of the two dimensional array
    {   for(countTwo = 0; countTwo < COLUMN; countTwo++)
        {   if(data[countOne][countTwo] < low)
            {   low = data[countOne][countTwo];//resets value of low if its lower than the previous lowest value
            }
        }
    }
    return low;//returns lowest of all values
}
double get_highest_number(double data[][COLUMN])//function to determine what the highest numbr in a set of data is
{
    double high = 0;//sets high to 0
    int countOne, countTwo;
    for(countOne = 0; countOne < ROW; countOne++)//double for loop to read each element of the two dimensional array
    {   for(countTwo = 0; countTwo < COLUMN; countTwo++)
        {   if(data[countOne][countTwo] > high)
            {   high = data[countOne][countTwo];//sets data to high if its higher than the previous highest value
            }
        }
    }
    return high;//returns highest value
}
void report(double average, double least, double most)//displays results
{
    cout << "The average amount of food eaten daily by all the monkeys was " << average << " lbs. " << endl;
    cout << "The least amount of food eaten on any day by one monkey was " << least << " lbs, " << endl;
    cout << "and the most was " << most << " lbs." << endl << endl;
}
