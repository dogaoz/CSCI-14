//
// program1.cpp
//
// Doga Oz, Ray Cao
// April 12, 2018
// Lab 9 - Program 1
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
int getMinNumInTestingSeq(int numbers[], int n, int i);
void swapNumbers(int &curArrayItem, int &testArrayItem);

const int MAX = 50;
int main()
{
    int numbers[50] = {0};

    for(int i = 0;i < MAX;i++)
    {
      cout << "Please enter 50 numbers: ";
      cin >> numbers[i];
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
    int cnt = 0;
    for(int i = 0;i < n;i++)
    {
        switch (option)
        {
            case 0:
                if ( i != 0 && i % 10 == 0  && numbers[i] != -1)
                {
                    cout << endl;
                }
                else if (i != 0)
                {
                    cout << setw(5);
                }
                if (numbers[i] != -1)
                {
                    cout << numbers[i];
                }
                break;
            case 1:
                if (cnt == 10)
                {
                    cout << endl;
                    cnt = 0;
                }
                else if (cnt != 0)
                {
                    cout << setw(5);
                }
                if (numbers[49-i] != -1)
                {
                    cout << numbers[49-i];
                    cnt++;
                }
                break;
        }
    }
    cout << endl;
}

// Sorting numbers using selection search.
void sortNumbers(int numbers[], int n)
{
    for(int i = 0;i < n && numbers[i] != -1;i++)
    {
        swapNumbers(numbers[i], numbers[getMinNumInTestingSeq(numbers, n, i)]);
    }

}

int getMinNumInTestingSeq(int numbers[], int n, int i)
{
    int min_test_seq_item = i;
    for(int j = i+1;j < n && numbers[j] != -1;j++)
    {
        if (numbers[j] < numbers[min_test_seq_item])
        {
            min_test_seq_item = j;
        }
    }
    return min_test_seq_item;
}

void swapNumbers(int &curArrayItem, int &testArrayItem)
{
    if (testArrayItem < curArrayItem)
    {
        int temp = curArrayItem;
        curArrayItem = testArrayItem ;
        testArrayItem = temp;
    }
}
