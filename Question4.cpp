#include <iostream> 
using namespace std;

class Matrix 
{

        int rows;
        int cols;
        int** matrix;

    public:

    Matrix (int ro, int co) {
            rows = ro;
            cols = co;
            matrix = new int*[rows];

            // Allocating memory dynamically  to each row  & column
            int i = 0;
            while ( i< rows ) {

                    matrix[i] = new int [cols];
                    i++ ;
            }

            // initiliazing whole matrix with 0
            for(int r = 0; r < rows; r++)
            {
                for(int c = 0; c < cols; c++)
                {
                    matrix[r][c] = 0;
                }
            }
    }
    // <------ Part 1 -----> 
        Matrix(int n1, int n2, int n3, int n4, int row = 2, int col = 2)
        {
            rows = row;
            cols = col;
            
            // allocating new memory for 2x2 matrix
            matrix = new int*[rows];

            for(int r = 0; r < rows; r++)
            {
                matrix[r] = new int[cols];
            }

            *(*(matrix+0)+0) = n1;
            *(*(matrix+0)+1) = n2;
            *(*(matrix+1)+0) = n3;
            *(*(matrix+1)+1) = n4;
           
        }

// <----- Part 2 ------->
Matrix (int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int
row = 3,int col = 3) {

            rows = row;
            cols = col;
                 // allocating new memory for 3x3 matrix
                matrix = new int*[rows];
                int r = 0;
                while(r<rows) {
                        matrix[r] = new int[cols];
                        r++ ;
                 }
             // initializing the matrix with the given arguments passed
            *(*(matrix+0)+0) = n1;
            *(*(matrix+0)+1) = n2;
            *(*(matrix+0)+2) = n3;
            *(*(matrix+1)+0) = n4;
            *(*(matrix+1)+1) = n5;
            *(*(matrix+1)+2) = n6;
            *(*(matrix+2)+0) = n7;
            *(*(matrix+2)+1) = n8;
            *(*(matrix+2)+2) = n9;

}

// <------ Part 3 -----> 
Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11,int n12, int n13, int n14, int n15, int n16, int row = 4, int col = 4)
        {
            rows = row;
            cols = col;
            // allocating new memory for 4x4 matrix
            matrix = new int*[rows];

            
            int r = 0;
            while(r<rows) 
            {
                matrix[r] = new int[cols];
                r++ ;
            }
            // initializing the matrix with the given arguments passed
            *(*(matrix+0)+0) = n1;
            *(*(matrix+0)+1) = n2;
            *(*(matrix+0)+2) = n3;
            *(*(matrix+0)+3) = n4;
            *(*(matrix+1)+0) = n5;
            *(*(matrix+1)+1) = n6;
            *(*(matrix+1)+2) = n7;
            *(*(matrix+1)+3) = n8;
            *(*(matrix+2)+0) = n9;
            *(*(matrix+2)+1) = n10;
            *(*(matrix+2)+2) = n11;
            *(*(matrix+2)+3) = n12;
            *(*(matrix+3)+0) = n13;
            *(*(matrix+3)+1) = n14;
            *(*(matrix+3)+2) = n15;
            *(*(matrix+3)+3) = n16;
        }
// <-----Part 4 ------> 
 Matrix (const Matrix &m)   
        {
            rows = m.rows;
            cols = m.cols;
            // allocating memory for the matrix 
            matrix = new int*[rows];
                int i = 0 ;
           
           while( i<rows )
            {
                matrix[i] = new int[cols];
                i++ ;
            }
                //copying the contents of the matrix m in to original matrix 
                int t = 0 ;
                while ( t<rows )
            {
                for(int j = 0; j < cols; j++)
                {
                    *(*(matrix+t)+j) = m.matrix[t][j];
                }
                t++ ;
            }
        }

//<-----Part 5 ------>
~Matrix() {

// deallocating the dynamic memory 
        int d = 0;
     while(d<rows)
            {
                delete[] matrix[d];
                d++ ;
            }
            delete[] matrix;
}

//<----Part 6----->
int getRow()
{
 return rows;
}
//<----Part 7----->
int getCol()
{
    return cols;
}
//<----Part 8 ----->

int getValue(int row, int col) {

    return  *(*(matrix+row)+col) ;
}

//<-----Part 9 ----->
void setValue(int row, int col, int value) {

    *(*(matrix+row)+col) = value ;


}

//<---- Part 10 ----->
int Total() {
// this function is calculating the sum of all the values in the matrix
int sum = 0;
                int r = 0;
                while ( r<rows )
            {
                for (int c = 0; c < cols; c++)
                {
                    sum += *(*(matrix+r)+c) ;
                }
                r++ ;
            }

            return sum;

}

//<---- Part 11 ---->
// Calculates average of all the values in the array.
double Average() {
        double sum = 0;
        int count_of_value = 0;

        int r = 0;
        while( r<rows ) {

                    for (int c=0; c<cols; c++) {
                            sum = sum + *(*(matrix+r)+c) ;
                            count_of_value++ ;
                    }

            r++ ;
        }
        // dividing sum with the number of values in the matrix will give average
        double result = sum / count_of_value ;
        return result ;
}

//<<------ Part 12 -------->
int RowTotal(int row) {
// Calculates total/sum of the values in the specified row. 
int sum_of_rows = 0;
int s = 0;
while ( s < cols ) {
    sum_of_rows = sum_of_rows + matrix[rows][s];
    s++ ;
}

return sum_of_rows ;
}

//<----- Part 13 ------>
//Calculates total/sum of the values in the specified column.
int ColumnTotal(int col)
        {
            int sum_of_cols = 0;
            int r = 0;
            while ( r< rows ) 
           
            {
               sum_of_cols = sum_of_cols +  *(*(matrix+r)+col);
                r++ ;
            }

            return sum_of_cols;
        }

//<------ Part 14 ------->
int HighestInRow(int row) {
//Finds highest value in the specified row of the array. 
int HIGHEST =   *(*(matrix+row)+0);

int counter = 1;
// starting a loop for all elements to be compared in a specified row with the initiliased highest value and once the highest value get updates it returns that 
while (counter<cols) {

    if (*(*(matrix+row)+counter) > HIGHEST)  {
        HIGHEST = *(*(matrix+row)+counter);
    }
    counter++;
}
return HIGHEST ;

}


//<------ Part 15 ------->
int LowestInRow(int row) {
//Finds lowest value in the specified row of the array.
int LOWEST =   *(*(matrix+row)+0);
int counter2 = 1;
// starting a loop for all elements to be compared in a specified row with the initiliased highest value and once the highest value get updates it returns that 
while (counter2<cols) {

    if (*(*(matrix+row)+counter2) < LOWEST)  {
        LOWEST = *(*(matrix+row)+counter2);
    }
    counter2++;
}
return LOWEST ;
}

//<----Part 16 ----->
 Matrix Transpose() {

    int swap=0;
    int i = 0;
    int j = 0;
    
    while(i<rows) {

        while ( j<cols )
        {
            // swapping the values of rows and colums to get transpose
              swap = *(*(matrix+i)+j);
              *(*(matrix+i)+j) =  *(*(matrix+j)+i);
              *(*(matrix+j)+i) = swap ;
              j++ ;

        }
        i++ ;
    }
    return *this ; 

 }
//<-----Part 17---->
int LeftDiagonalTotal() {

int Sum_Left = 0;
int counter = 0;

            while (counter<rows)
            {   //same row and column number are diagonals
                Sum_Left = Sum_Left + *(*(matrix+counter)+counter) ;
                counter=counter+1 ;
               
            }

            return Sum_Left;
}

//<-----Part18---->
int RightDiagonalTotal() {
// Calculates total/sum of the values in the right Diagonal of array.
int Sum_Right = 0;
int Right_counter = 0;
while (Right_counter < rows ) {
    // row and column number are same but we are doing it from opposite direction hence we will start from last row
    Sum_Right = Sum_Right +  *(*(matrix+Right_counter)+(cols-Right_counter-1)) ;
    Right_counter =  Right_counter+1 ;
}
return Sum_Right ;
}

//<---Part19---->
Matrix Add(Matrix m) {
    //adds the calling object matrix with the one passed as an argument and returns a resultant matrix
    Matrix Swap(rows,cols);
    int ro = 0;
    int cl =0;
   // int i = 0;
   // int j = 0;
        while(ro<rows) {
                           while(cl<cols) {
                                            //initliazing new object with 0 so that it adds the values in zero rather than garbage values
                                        Swap.matrix[ro][cl] = 0;
                                         cl++ ;
                                          }
            ro++ ;
            
        }
if ( (rows == m.rows) || (cols == m.cols) ) {
    
    for(int i = 0; i<rows; i++){
                                   // while (j<cols )
        for(int j = 0; j<cols ;j++)     {
                                Swap.matrix[i][j] = matrix[i][j] + m.matrix[i][j] ;
                               // j++ ;
                            }
        
    }
int r_disp = 0;
int c_disp = 0;
while(r_disp<rows) {
                            while(c_disp<cols) {
                                cout<<Swap.matrix[r_disp][c_disp];
                                cout<<" ";
                                c_disp++ ; }
    cout<<"\n";
    r_disp++; }}
else {
   cout<<"Addition Operation is not possible. Matrix must have equal rows and columns \n";
   
}
    return Swap;
}

//<-----Part20---->
Matrix Subtract(Matrix m) {

     //adds the calling object matrix with the one passed as an argument and returns a resultant matrix
    Matrix Swap(rows,cols);
    int ro = 0;
    int cl =0;
    int i = 0;
    int r_disp = 0;
    int c_disp = 0;
    
    while(ro<rows) {
                       while(cl<cols) {
                                        //initliazing new object with 0 so that it subtracts the values in zero rather than garbage values 
                                    Swap.matrix[ro][cl] = 0;
                                     cl++ ;
                                      }
        ro++ ;
                  }

if ( (rows == m.rows) || (cols == m.cols) ) {


while ( i<rows ) {
                           
    for(int j=0;j<cols;j++) {
                        *(*(Swap.matrix+i)+j) = *(*(matrix+i)+j) - m.matrix[i][j] ;
                               
                            }

    i++ ;
}

while(r_disp<rows) {
                            while(c_disp<cols) {

                                cout<<Swap.matrix[r_disp][c_disp];
                                cout<<" ";
                                c_disp++ ;
                            }


    cout<<"\n";
    r_disp++;
}

//return Swap;

}


else {
    cout<<"Subtraction Operation is not possible. Matrix must have equal rows and columns \n";
}
    return Swap;

}

//<----Par21--->
Matrix Multiply(Matrix m) {

/* multiplies the calling object matrix with the one passedas an argument and returns a resultant matrix */

Matrix Multiply(rows,cols);
int i = 0;
int j = 0;
    int r_disp = 0;
    int c_disp = 0;
   // int ro = 0;
   // int cl = 0;
    //int scale = 0;

// initiliazing matrix with 0 to avoid garbadge values 
while(i<rows) {
                    while( j<cols ) {
                        Multiply.matrix[i][j] = 0;
                        j++ ;
                    }


    i++ ;
}

if ( cols == m.rows )  {

//while ( ro<rows )
    for(int ro=0; ro<rows; ro++)
{
                           // while (cl<m.cols)
                                for(int cl=0; cl<cols;cl++)
                            {

                              for(int scale=0; scale<cols; scale++) {

                                                         Multiply.matrix[ro][cl] = Multiply.matrix[ro][cl] + ( *(*(matrix+ro)+scale) * m.matrix[scale][cl]);

                                                     
                                                                     }


                               // cl++;
                            }


   // ro++ ;

}


while(r_disp<rows) {

            while(c_disp<cols) {
                    cout<<Multiply.matrix[r_disp][c_disp];
                    cout<<" ";
                    c_disp++;
            }
            cout<<"\n";
            r_disp++;
}
}

else {
    cout<<"Mulitplication is not Possible if the number of cols are not equal to numbers of rows \n";
}
    return Multiply;

}

//<----Part22---->
int FindkSmallest(int k) {

/* a function that finds the k th smallest element in the matrix.If k is 1, return the smallest element. If k is 2 return the second smallest element andso on. */
int size = rows * cols ;
int* Small = new int [size];
int Pos = 0 ;
int Swap = 0;
int ro = 0;
int cl = 0;
int s_ro = 0;
int s_cl = 0;
while ( ro<rows ) {

                while(cl<cols) {
                    //storing values 
                    *(Small+Pos) = *(*(matrix+ro)+cl);
                    Pos=Pos+1;
                    cl++;
                }
                    ro++;
}
while(s_ro<size) {
                        while(s_cl<size) {
                             //Sorting Arrray 
                                            if (   *(Small+s_ro) > *(Small+s_cl)   ) {
                                                    Swap =  *(Small+s_ro);
                                                     *(Small+s_ro) =  *(Small+s_cl);
                                                     *(Small+s_cl) = Swap;
                                            }
                            s_cl = s_cl + 1;
                        }
    s_ro = s_ro + 1;
}

return Small[k-1];

}

//<----Part23----->
int FindkLargest(int k) {

int size = rows * cols ;
int* Small = new int [size];
int Pos = 0 ;
int Swap = 0;
int ro = 0;
int cl = 0;
int s_ro = 0;
int s_cl = 0;
while ( ro<rows ) {

                while(cl<cols) {
                    *(Small+Pos) = *(*(matrix+ro)+cl);
                    Pos=Pos+1;
                    cl++;
                }
                    ro++;
}
while(s_ro<size) {
                        while(s_cl<size) {
                            //Sorting Arrray 
                                            if (    *(Small+s_ro) < *(Small+s_cl)   ) {
                                                    Swap =  *(Small+s_ro);
                                                     *(Small+s_ro) =  *(Small+s_cl);
                                                     *(Small+s_cl) = Swap;
                                            }
                            s_cl = s_cl + 1;
                        }
    s_ro = s_ro + 1;
}
//once sorted then k-1 will return the highest terms
return Small[k-1];

}

//<----Part24---->
 Matrix merge(Matrix m) {
   
   Matrix Marge(rows,cols);
   int ro = 0;
   int cl = 0;
   int i = 0;
   int j = 0;
   int copy_row = 0;
   int copy_col = 0;
   int merge_row = 0;
   int merge_col = 0;
   int r_disp = 0;
   int c_disp = 0;

    while ( i<rows ) {

        while(j<cols) {
            Marge.matrix[i][j] = 0;

            j=j+1;
        }

        i =i +1;
    }

    if ( ro==m.rows || cl==m.cols ) {

            while(copy_row<rows) {

                 while(copy_col<cols) {
                    Marge.matrix[copy_row][copy_col] = matrix[copy_row][copy_col];
                    copy_col++;
                 }
                copy_row++;
            }

            while(merge_row<rows) {
                while(merge_col<cols) {
                    Marge.matrix[merge_row][merge_col]  = m.matrix[merge_row][merge_col-cols] ;
                    merge_col++;
                }
                merge_row++;
            }

            while (r_disp<rows ) {

                while(c_disp<cols) {
                    cout<<Marge.matrix[r_disp][c_disp]<<" ";

                    c_disp++;
                }

                cout<<"\n";
                r_disp++;
            }

           
    }

    else {
        cout<<"Merge not Possible! TRy again with different inputs \n";
    }
     
     return Marge;
 }

//<---Displaying Matrix
void Display() {

    for(int i =0; i<rows; i++ ) {
        for(int j =0; j<rows; j++) {
            cout<< matrix[i][j]<<" ";
            
        }
        cout<<endl;
    }
    
}
    
    
    
    
    
}; //class wala bracket



int main() {
   
int k ;
Matrix Matrix1(4, 5, 6, 7);


   // Matrix1.Display();
   //cout << "Matrix consist of  " << Matrix1.getRow() << "x" << Matrix1.getCol() << "\n"; //perfect
  // cout << "Sum of the values in Matrix is: " << Matrix1.Total() << "\n";  //perfect
  //  cout << "Average of the values used in Matrix is:  " << Matrix1.Average() << "\n"; //perfect
   // cout << "Total of Row One " << Matrix1.RowTotal(1) <<"\n";
   // cout << "Total of Column One " << Matrix1.ColumnTotal(1) << "\n";
//cout << "The highest value in first Row: " << Matrix1.HighestInRow(0) << "\n";   //perfect
 //   cout << "The lowest value in Second Row " << Matrix1.LowestInRow(1) << "\n"; //perfect
 //   cout << "Total of left Diagonal is:  " << Matrix1.LeftDiagonalTotal() <<  "\n"; //perfect
//cout << "Total of Right Diagonal is: " << Matrix1.RightDiagonalTotal() <<  "\n";  //perfect
  //  cout << "Transpose of your Matrix is:" << "\n"; //perfect
   // Matrix1.Transpose(); //perfect
   //  Matrix1.Display(); //perect
//   cout<<"Performing Basic Operations on the Matrices \n";   //perfect
//    Matrix Matrix2(8, 9, 10, 11);  //perfect
//    cout << "Addition:" << "\n";  //perfect
//    Matrix Matrix3 = Matrix1.Add(Matrix2); //perfect
//    Matrix3.Display();  //perfect
//
   // cout << "Subtraction: " <<  "\n";  //perfect
    Matrix Matrix2(8, 9, 10, 11);  //perfect
  //  Matrix Matrix4 = Matrix1.Subtract(Matrix2); //perfect
   // Matrix4.Display();  //perfect
//
   //cout<<"Multiplication:"<<endl;    //working perfect
    Matrix Multi=Matrix1.Multiply(Matrix2);  //working perfect
   // Multi.Display();
//
//
//    cout<<"Enter Largest kth Element in the matrix you want to find "<<"\n";
//    cin>>k;
//    cout<<Matrix1.FindkLargest(k);
//
//    cout<<"Enter Smallest kth Element in the matrix you want to find "<<"\n";
//    cin>>k;
//    cout<<Matrix1.FindkSmallest(k);
//
    cout << "The merged matrices are :" <<  "\n";
    Matrix1.merge(Matrix2);
//

                       














            }









    
