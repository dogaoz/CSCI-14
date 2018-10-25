//
// program2.cpp
//
// Doga Oz, Ray Cao
// April 12, 2018
// Lab 9 - Program 2
// Gets 50 integers, stores in them array and sorts them
// It prints both in normal and reversed order
// Then it shows the smallest, largest, sum, and average
//

#include <iostream>
#include <iomanip>
using namespace std;

bool checkIfStatisticsExist(int i);
float getInfo(int numbers[], int n, int option);
int printNumbers(int numbers[], int n, int option);
int printNumber(int numbers[], int index);
void sortNumbers(int numbers[], int n);
int getMinNumInTestingSeq(int curKey, int n, int i);
void swapNumbers(int &curArrayItem, int testArrayItem);

const int MAX = 50;
int main()
{
    int numbers[50] = {0};

    for(int i = 0;i < MAX;i++)
    {
      if (i != 0 && numbers[i-1] < 0)
      {
          numbers[i] = -1;
      }
      else
      {
      cout << "Please enter 50 numbers: ";
      cin >> numbers[i];
      }
    }

    if (checkIfStatisticsExist(numbers[0]))
    {
        cout << "Largest number is " << getInfo(numbers, MAX, 0) << endl;
        cout << "Smallest number is " << getInfo(numbers, MAX, 1) << endl;
        cout << "Sum of numbers is " << getInfo(numbers, MAX, 2) << endl;
        cout << "Average of numbers is " << getInfo(numbers, MAX, 3) << endl;

        cout << "Printing Numbers in entered order..." << endl;
        printNumbers(numbers, MAX, 0);
        cout << "Printing Numbers in reverse order..." << endl;
        printNumbers(numbers, MAX, 1);
        sortNumbers(numbers, MAX);
        cout << "Printing Numbers after sorted..." << endl;
        printNumbers(numbers, MAX, 0);
    }
    else
    {
        cout << "There are no statistics." << endl;
    }
    return 0;
}

bool checkIfStatisticsExist(int i)
{
    if (i == -1)
        return false;
    else
        return true;
}

float getInfo(int numbers[], int n, int option)
{
    if (checkIfStatisticsExist(numbers[0]))
    {
        float temp = numbers[0];
        int i;
        for(i = 1;i < n && numbers[i] != -1;i++)
        {
            // Find largest number
            if (numbers[i] > temp && option == 0)
                temp = numbers[i];
            // Find smallest number
            else if (numbers[i] < temp && option == 1)
                temp = numbers[i];
            // Sum OR average of numbers
            else if (option == 2 || option == 3)
                temp += numbers[i];
        }

        if (option == 3)
            temp /= i;

        return temp;
    }
    else
        return -1;
}

int printNumbers(int numbers[], int n, int option)
{
    switch (option)
    {
        case 0:
            for(int i = 0;i < n && numbers[i] != -1;i++)
                printNumber(numbers,i);
        break;
        case 1:
            for(int i = n-1;i >= 0;i--)
                printNumber(numbers,i);
        break;
    }
    cout << endl;
}

int printNumber(int numbers[], int index)
{
    if ( (index+1) % 10 == 0 )
    {
        cout << endl;
    }
    else
    {
        cout << setw(5);
    }
    if (numbers[index] != -1)
    {
        cout << numbers[index];
    }

}
// Sorting numbers using selection search.
void sortNumbers(int numbers[], int n)
{
    for(int i = 0;i < n && numbers[i] != -1;i++)
    {
        swapNumbers(numbers[i], getMinNumInTestingSeq(numbers[i], n, i));
    }

}

int getMinNumInTestingSeq(int curKey, int n, int i)
{
    for(int j = i+1;j < n && numbers[j] != -1;j++)
    {
        if (numbers[j] < curKey)
        {
           curKey = numbers[j];
        }
    }
    return curKey;
}

void swapNumbers(int &curArrayItem, int testArrayItem)
{
    if (testArrayItem < curArrayItem)
    {
        int temp = curArrayItem;
        curArrayItem = testArrayItem ;
        testArrayItem = temp;
    }
}
