#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int CountCannonBalls( int levels);
void PrintBinary (int num);
int ComputeSumOfDigits (int num);
void MazeSolver(int r, int c);
bool findPath(int r, int c);
void North(int r, int c);
void South(int r, int c);
void East(int r, int c);
void West(int r, int c);

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

    //MazeSolver();


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
/*void MazeSolver(int r, int c)
{
    //read in first line of file for bounds
    int numRows=0, numCols=0, startRows=0, startCols=0;
    string RAndC;
    string startPos;
    
    fstream fin("maze1.txt");    
    getline(fin, RAndC);

    stringstream ss;
    ss.str(RAndC);
    ss>>numRows;
    ss>>numCols;
    
    //read inn second line for starting pos
    getline(fin, startPos);
    stringstream st (startPos);
    st>>startRows;
    st>>startCols;

    //checker from online...that takes current location and had file info
    char charAt;
    if(r>numRows || r<0 || c<0 ||c>numCols) return false;
    if(charAt=='t') return true;



}*/
bool findPath (int r, int c)
{    
    int numRows, numCols;
    string RAndC, line;
    string strArr[20];
    fstream fin("maze1.txt");    
    getline(fin, RAndC);

    stringstream ss;
    ss.str(RAndC);
    ss>>numRows;
    ss>>numCols;

    for(int i=0; i<numRows; i++)
    {
        getline(fin,line);
        strArr[i]=line;
    }
    return 0;
    

    /*

    char tempChar;

    char* TwoD [50];
    fstream file("maze1.txt");
    for(int i=0; i<numRows; i++)
    {
        for(int j=0; j<numCols; j++)
        {
            file>>tempChar;
            TwoD[i][j]=tempChar;
        }
    }
    //getline (file, 
    
    char charAt;
    if(charAt==' ') return false;
    if(charAt=='t') return true;
    if(charAt=='X') return false;
    charAt='S';//file io
    if(findPath(North(r, c)==true) return true;
    if(findPath(South(r,c)== true) return true;
    if(findPath(East(r, c)==true) return true;
    if(findPath(West(r, c)==true) return true;
    charAt='.';//file io*/

}
void North(int r, int c)
{
    c-=1;
}
void South(int r, int c)
{
    c+=1;
}
void East(int r, int c)
{
    r+=1;
}
void West(int r, int c)
{
    r-=1;
}

