#include <iostream>
#include <cmath>


using namespace std;

int main()
{
    int c;
    c = 0;
    int totalDigit;
    int totalCombinations;
    totalDigit = 4;
    totalCombinations = pow(2,totalDigit);
    int digitArray[totalDigit+1][totalCombinations+1];


    //fill intial composition with zero
    for(int i=totalDigit; i>0; i--)
    {
        digitArray[i][c]=0;
    }

    c++;

    //fill the next
    for(int i=totalDigit; i>0; i--)
    {
        digitArray[i][c]=0;
    }


    //action begins
    while(c<=totalCombinations)
    {
        int steps;
        steps = 0;
        //for loop for general checking
        for(int i=totalDigit; i>0; i--)
        {
            //count the steps needed to reach a zero
         if(digitArray[i][c]!=0)
         {
             steps++;
         }

         //now use it
         else
         {
             int t = totalDigit;

             for(int s=steps ; s>0; s--)
             {
                 digitArray[t][c]=0;
                 t--;
             }

             //it erased all the past 1's into all zeros. now make the final digit, a one
             digitArray[t][c]=1;
             break;
         }


        }

        c++;

        for(int i=totalDigit; i>0; i--)
        {
            digitArray[i][c]=digitArray[i][c-1];
        }

    }


for(int c=totalCombinations; c>0; c-- ) {

    for (int i = 1; i <= totalDigit; i++) {
        cout << digitArray[i][c];
    }
    cout<<"composition number is: "<<c;
    cout << "\n";

}
    return 0;
}