#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>

using namespace std;

int a = 0;
int selection = 0;

void option(); /* Menu Option */
void linear(); /* option for Linear Search */
void binary(); /* option for Binary Search */
void interpolation(); /* option for Interpolation Search */
void exit(); /* Exit */

void option() {

    cout << "\nPlease choose from the following options\n";
    cout << " 1. Linear Search\n";
    cout << " 2. Binary Search\n";
    cout << " 3. Interpolation Search\n";
    cout << " 4. Exit\n";
    cout << "Your Option : \t";
    cin >> selection;


    if (selection == 1)
    {
       linear();
    }
        else if (selection == 2)
            {
                binary();
            }
        else if (selection == 3)
            {
                interpolation();
            }
                else if (selection == 4)
                {
                    exit();
                }
}

void linear() {

    int i, num, n, pos;
    int c = 0;
	cout << "\nEnter the array size : ";
	cin >> n;
	int Array[n];
	for(i=0; i<n; i++)
	{
	    cout << "Index of #" << (i+1) << ": ";
		cin >> Array[i];
	}
	cout << endl <<  "Enter the number to be search : ";
	cin >> num;
	for(i=0; i<n; i++)
	{
		if(Array[i] == num)
		{
			c = 1;
			pos = i + 1;
			break;
		}
	}
	if(c == 0)
	{
		cout << endl << num << " Number not found!";
	}
	else
	{
		cout << endl << num << " found in the array at the location " << pos;
	}
}

void binary() {

    int c, i, num, first, last, middle;
	cout << "\nEnter the array size : " ;
    cin >> c;
    int Array[c];

	for(i=0; i<c; i++)
	{
		cout << "Index of #" << (i+1) << ": ";
        cin >> Array[i];
	}
	cout << endl << "Enter the number that you want to search : ";
    cin >> num;

	first = 0;
	last = c - 1;
	middle = (first+last)/2;
	while(first <= last)
	{
	    if(Array[middle] < num)
            {
                first = middle + 1;
                }
                else if(Array[middle] == num)
                    {
                        cout << endl << num << " Found in the Array at the location " << middle+1 << endl;
                        break;
                    }
                    else
                        {
                            last = middle - 1;
                        }
                            middle = (first + last)/2;
	}
	if(first > last)
    {
        cout << endl << num << " Not found in the Array!";
    }
}

int interpolationSearch(int array[], int start, int end, int key) {
    int dist, valRange, indexRange, estimate;
    float fraction;

    while(start <= end && key >= array[start] && key <= array[end]) {
            dist = key - array[start];
            valRange = array[end] - array[start];     //range of value
            fraction = dist / valRange;
            indexRange = end - start;
            estimate = start + (fraction * indexRange);      //estimated position of the key
            if(array[estimate] == key)
                return estimate;
            if(array[estimate] < key)
                start = estimate +1;
            else
                end = estimate - 1;
    }
    return -1;
}

void interpolation() {
    int n, searchKey, loc;
    cout << "\nEnter the array size : ";
    cin >> n;
    int Arr[n];

    for(int i = 0; i< n; i++) {
            cout << "Index of #" << (i+1) << ": ";
            cin >> Arr[i];
    }

    cout << endl << "Enter search key to search in the list : ";
    cin >> searchKey;

    if((loc = interpolationSearch(Arr, 0, n-1, searchKey)) >= 0)
        cout << endl << searchKey << " Found in the Array at the location " << loc << endl;
    else
        cout << endl << searchKey << " Item is not found in the list." << endl;
}

void exit(){
       /* to exit from the program */
       cout << endl;
       cout << " See ya !\n";
       a = 1;
}
int main(){

    cout<<"\nThis Program created by \n";
    cout<<" Okky Dwi Triferyawan    \n";
    cout<<"     012201800005     \n";

    while(true)
    {
        cout << endl;
        if (a == 1)
        {
            break;
        }
        option();
    }
   return 0;
}
