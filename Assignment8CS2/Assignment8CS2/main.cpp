#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int CountCannonBalls( int levels);
void PrintBinary (int num);
int ComputeSumOfDigits (int num);
void MazeSolver();
bool FindPath(int r, int c, char arr[][5]);//char ** arr);
void Storage();

int main ()
{
    cout<<"Testing Problem 1: "<<endl;
    cout<<"Should be 55: "<<CountCannonBalls(5)<<endl;
    cout<<"Should be 385: "<<CountCannonBalls(10)<<endl<<endl;

    cout<<"Testing Problem 2: "<<endl;
    cout<<"Should be 11000: ";
    PrintBinary(24);
    cout<<endl;
    cout<<"Should be 11111000: ";
    PrintBinary(248);
    cout<<endl<<endl;

    cout<<"Testing Problem 3: "<<endl;
    cout<<"Should be 28: "<<ComputeSumOfDigits(5698)<<endl;
    cout<<"Should be 18: "<<ComputeSumOfDigits(963)<<endl<<endl;

    MazeSolver();

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
void MazeSolver()
{
    int numRows, numCols, startR, startC, j, treasureR, treasureC;
    string RAndC, line, starting;
    char strArr[5][5];
    //char * strArr = new char [100];
    fstream fin("maze1.txt");    
    getline(fin, RAndC);

    stringstream ss;
    ss.str(RAndC);
    ss>>numRows;
    ss>>numCols;

    getline(fin, starting);

    stringstream st;
    st.str(starting);
    st>>startR;
    st>>startC;

    //Initialize array
    for(int k=0; k<numRows; k++)
    {
        for(int l=0; l<numCols; l++)
        {
            strArr[k][l]='0';
        }
    }

    for(int i=0; i<numRows; i++)
    {
        getline(fin,line);
        for(j=0; j<numCols; j++)
        {
            strArr[i][j]=line[j];
            if(line[j]=='t')
            {
                treasureR=i;
                treasureC=j;
            }
        }  
    }

    cout<< "Treasure: "<<treasureR<<", "<<treasureC<<endl;
    bool found = FindPath(startR, startC, strArr);
    cout<<"FOUND!"<<endl;
}
bool FindPath (int r, int c, char Arr[][5])
{  
    int numRows, numCols;
    string RAndC, line, starting;
    fstream fin("maze1.txt");
    
    getline(fin, RAndC);

    stringstream ss;
    ss.str(RAndC);
    ss>>numRows;
    ss>>numCols;
   
    if(r<0 || r>numRows-1 || c<0 || c>numCols-1) return false;
    
    char charAt;
    charAt=Arr[r][c];    
    
    if(charAt=='t') return true;   
    else if(charAt=='+') return false;
    else if(charAt=='X') return false;
        
    Arr[r][c]='+';
    
    if(FindPath(r, c-1, Arr)==true) 
    {
        cout<< "Treasure path: "<<r<<", "<<c<<endl;
        return true;
    }
    if(FindPath(r, c+1, Arr)== true) 
    {
        cout<< "Treasure path: "<<r<<", "<<c<<endl;
        return true;
    }
    if(FindPath(r+1, c, Arr)==true)
    {
        cout<< "Treasure path: "<<r<<", "<<c<<endl;
        return true;
    }
    if(FindPath(r-1, c, Arr)==true) 
    {
        cout<< "Treasure path: "<<r<<", "<<c<<endl;
        return true;
    }    
    Arr[c][r]='X';
    return false;
}

