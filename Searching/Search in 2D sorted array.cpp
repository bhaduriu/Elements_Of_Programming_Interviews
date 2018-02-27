/*
start from 1st row's last column
if element > mat[row][column]
  move down;
else
  move left;
*/

#include <iostream>
#define R 6
#define C 5
using namespace std;

int main()
{
    int mat[R][C]={ -1,2,4,4,6,
                    1,5,5,9,21,
                    3,6,6,9,22,
                    3,6,8,10,24,
                    6,8,9,12,25,
                    8,10,12,13,40
                  };
                  
    int x;cin>>x;int flag=0;
    int row=0,col=C-1;
    while(row<R && col>=0)
    {
        if(x==mat[row][col])
        {
            cout<<"Found at: "<<"("<<row<<","<<col<<")"<<endl;
            flag++;
        }
        if(x>mat[row][col])
            row++;
        else
            col--;
    }
    if(!flag)
        cout<<"Not Found"<<endl;
    return 0;
}
