#include<iostream>
#include<cmath>
using namespace std;

int check_num(int n) //371
{
    if(n < 0)       //check for negative number
    {
        return 0;
    }

    int temp = n;
    int exp = 0;
    int sum = 0;;

    while(temp != 0)        //finalize the power(number of digit)
    {
        exp++;  //3
        temp /= 10;
    }

    temp = n;

    while(temp != 0)        //sum of every number powered
    {
        int digit = temp%10;
        sum += pow(digit, exp);
        temp /= 10;
    }

    if(n == sum)            //print result
    {
        cout << n << " is Armstrong number" << endl;
    }
    else
    {
        cout << n << " is not Armstrong number" << endl;
    }

    return 0;
}


int main()
{
    int val;
    cout << "Enter number to be checked: ";
    cin >> val;

    check_num(val);

    return 0;
}