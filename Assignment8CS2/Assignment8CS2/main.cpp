#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int CountCannonBalls( int levels);
void PrintBinary (int num);
int ComputeSumOfDigits (int num);
void MazeSolver();
bool FindPath(int r, int c, char arr[][20]);
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
    int numRows, numCols, startR, startC;
    string RAndC, line, starting;
    char strArr[20][20];
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
        for( int j=0; j<numCols; j++)
        {
            strArr[i][j]=line[j];
        }  
    }

    bool found = FindPath(startR, startC, strArr);
}
bool FindPath (int r, int c, char Arr[][20])
{  
    int numRows, numCols;
    string RAndC, line, starting;
    fstream fin("maze1.txt");
    
    getline(fin, RAndC);

    stringstream ss;
    ss.str(RAndC);
    ss>>numRows;
    ss>>numCols;
   
    char charAt;
    charAt=Arr[r][c];

    if(charAt=='D') return false;
    if(charAt=='t') return true;
    if(charAt=='X') return false;
    
    if(c-1>=0)
    {
        cout<<"c-1"<<endl;
        if(FindPath(r, c-=1, Arr)==true) 
        {
            cout<< "Cooordinate: "<<r<<" "<<c<<endl;
            if(Arr[r][c]=='.') Arr[r][c+1]='D';
            for(int i=0; i<numRows; i++)
            {
                for(int j=0; j<numCols; j++)
                {
                    cout<<Arr[i][j];
                }
                cout<<endl;
            }
            return true;
        }
        else 
        {
            c+=1;
            if(Arr[r][c]=='.') Arr[r][c]='D';//Arr[r][c]='D';
            
            for(int i=0; i<numRows; i++)
            {
                for(int j=0; j<numCols; j++)
                {
                    cout<<Arr[i][j];
                }cout<<endl;                
            }            
        }
    }
    if(c+1<numCols-1)
    {
        cout<<"c+1"<<endl;
        if(FindPath(r, c+=1, Arr)== true) 
        {
            cout<< "Cooordinate: "<<r<<" "<<c<<endl;
            if(Arr[r][c]=='.') Arr[r][c-1]='D';
            for(int i=0; i<numRows; i++)
            {
                for(int j=0; j<numCols; j++)
                {
                    cout<<Arr[i][j];
                }
                cout<<endl;
            }
            return true;
        }
        else 
        {
            if(Arr[r][c]=='.') Arr[r][c]='D';//Arr[r][c]='D';
            c-=1;
            for(int i=0; i<numRows; i++)
            {
                for(int j=0; j<numCols; j++)
                {
                    cout<<Arr[i][j];
                }
                cout<<endl;
            }
        }
    }   
    if(r+1<numRows-1)
    {
        cout<<"r+1"<<endl;
        if(FindPath(r+=1, c, Arr)==true)
        {
            cout<< "Cooordinate: "<<r<<" "<<c<<endl;
            if(Arr[r][c]=='.') Arr[r-1][c]='D';
            for(int i=0; i<numRows; i++)
            {
                for(int j=0; j<numCols; j++)
                {
                    cout<<Arr[i][j];
                }
                cout<<endl;
            }
            return true;
        }
       else 
        {
            if(Arr[r][c]=='.') Arr[r][c]='D';
            r-=1;
            for(int i=0; i<numRows; i++)
            {
                for(int j=0; j<numCols; j++)
                {
                    cout<<Arr[i][j];
                }
                cout<<endl;
            }
        }
    }
    if(r-1>=0)
    {
        cout<<"r-1"<<endl;
        if(FindPath(r-=1, c, Arr)==true) 
        {
            cout<< "Cooordinate: "<<r<<" "<<c<<endl;
            if(Arr[r][c]=='.') Arr[r+1][c]='D';
            for(int i=0; i<numRows; i++)
            {
                for(int j=0; j<numCols; j++)
                {
                    cout<<Arr[i][j];
                }
                cout<<endl;
            }
            return true;
        }
        else 
        {
            if(Arr[r][c]=='.') Arr[r][c]='D';//Arr[r][c]='D';
            r+=1;
            for(int i=0; i<numRows; i++)
            {
                for(int j=0; j<numCols; j++)
                {
                    cout<<Arr[i][j];
                }
                cout<<endl;
            }            
        }
    }
    return 0;
}

