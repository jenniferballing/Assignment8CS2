#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int CountCannonBalls( int levels);
void PrintBinary (int num);
int ComputeSumOfDigits (int num);


int main ()
{
    cout<<"Testing Problem 1: "<<endl;
    cout<<"Should be 55: "<<CountCannonBalls(5)<<endl;
    cout<<"Should be 385: "<<CountCannonBalls(10)<<endl;

    cout<<"Testing Problem 2: "<<endl;
    cout<<"Should be 11000: ";
    PrintBinary(24);
    cout<<endl;
    cout<<"Should be 11111000: ";
    PrintBinary(248);
    cout<<endl;

    cout<<"Testing Problem 3: "<<endl;
    cout<<"Should be 28: "<<ComputeSumOfDigits(5698)<<endl;
    cout<<"Should be 18: "<<ComputeSumOfDigits(963)<<endl;



    system("pause");
    return 0;
}

int CountCannonBalls ( int levels)
{
    int total=0;

    if(levels==0) return total;

    else
    {
        total += (levels*levels)+ CountCannonBalls(levels-1);
    }
    return total;
}
void PrintBinary (int num)
{

    if(num==0)
    {
        return;
    }
     
    else 
    {        
        PrintBinary(num/2);
    }
    cout<<num%2;   
}
int ComputeSumOfDigits (int num)
{
    int total=0;
    if(num==0) return total;
    
    else
    {
        total=num%10+ ComputeSumOfDigits (num/10);
    }
    return total;
}
