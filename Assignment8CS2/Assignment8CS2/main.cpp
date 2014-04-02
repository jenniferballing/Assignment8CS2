#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int CountCannonBalls( int levels);
void PrintBinary (int num);
int ComputeSumOfDigits (int num);
void MazeSolver();
bool FindPath(int r, int c);
void Storage();
char** Arr;

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

    cout<<"Testing Problem 4:"<<endl;
    MazeSolver();
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
    
    //MAZE INFO
    fstream fin("maze.txt");    
    getline(fin, RAndC);

    stringstream ss;
    ss.str(RAndC);
    ss>>numRows;
    ss>>numCols;

    Arr= new char *[numRows];
    for(int y=0; y<numCols; y++)
    {
        Arr[y]= new char [numCols];
    }

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
            Arr[k][l]='0';
        }
    }

    for(int i=0; i<numRows; i++)
    {
        getline(fin,line);
        for(j=0; j<numCols; j++)
        {
            Arr[i][j]=line[j];
            if(line[j]=='t')
            {
                treasureR=i;
                treasureC=j;
            }
        }  
    }

    cout<< "Treasure: "<<treasureR<<", "<<treasureC<<endl;
    bool found = FindPath(startR, startC);
    cout<<"FOUND!"<<endl;
    for(int z=0; z<numRows; z++)
    {
        delete Arr[z];
    }
    delete [] Arr;
}
bool FindPath (int r, int c)
{  
    int numRows, numCols;
    string RAndC, line, starting;

    //MAZE INFO
    fstream fin("maze.txt");
    
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
    
    if(FindPath(r, c-1)==true) 
    {
        cout<< "Treasure path: "<<r<<", "<<c<<endl;
        return true;
    }
    if(FindPath(r, c+1)== true) 
    {
        cout<< "Treasure path: "<<r<<", "<<c<<endl;
        return true;
    }
    if(FindPath(r+1, c)==true)
    {
        cout<< "Treasure path: "<<r<<", "<<c<<endl;
        return true;
    }
    if(FindPath(r-1, c)==true) 
    {
        cout<< "Treasure path: "<<r<<", "<<c<<endl;
        return true;
    }    
    Arr[c][r]='X';
    return false;
}

