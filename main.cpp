#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int binaryCompositionGenerator(int totalDigit, int digitNumber,int compositionNumber)
{

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    int c;
    c = 0;
    int totalCombinations;
    totalCombinations = pow(2,totalDigit);
    cout<<"total combination is supposed to be: "<<totalCombinations<<endl;
    int digitArray[totalDigit+1];


    //fill intial composition with zero
    for(int i=totalDigit; i>0; i--)
    {
        digitArray[i]=0;
    }

    c++;

    //fill the next
    for(int i=totalDigit; i>0; i--)
    {
        digitArray[i]=0;
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
            if(digitArray[i]!=0)
            {
                steps++;
            }

                //now use it
            else
            {
                int t = totalDigit;

                for(int s=steps ; s>0; s--)
                {
                    digitArray[t]=0;
                    t--;
                }

                //it erased all the past 1's into all zeros. now make the final digit, a one
                digitArray[t]=1;
                break;
            }


        }

        //now we need to operate for next composition
        c++;

        for(int c=totalCombinations; c>0; c-- ) {

            for (int i = 1; i <= totalDigit; i++)
            {
                if(digitArray[i]==1)
                {
                    SetConsoleTextAttribute(h,10);
                    cout << digitArray[i];
                }
                else
                {
                    SetConsoleTextAttribute(h,15);
                    cout << digitArray[i];
                }

            }
            SetConsoleTextAttribute(h,4);
            cout<<"  composition number is: "<<c;
            cout << "\n";


    }





    }
 return digitArray[digitNumber];
}



int main()
{
   int test = binaryCompositionGenerator(9,5,3);
   cout<<test<<"wow"<<endl;
    return 0;
}