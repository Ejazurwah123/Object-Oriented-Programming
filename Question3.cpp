#include <iostream>
using namespace std;

class String
{
    
    char* Data;
    int Length;
    
public:
    
    // Default Constrcutor
    String() {
        Data = new char[1];
        Data[0] = '\0';
        Length = 0;
    }
    
    // Parametrised Constructor
    
    String( int z ) {
        // z is refering to size
        Data = new char [z];
        //Allocating memory dynamically
        Length = z;
        //length of the string
    }
    
    //Alternate Constructor
    String( char* ptr ) {
        
        int i = 0;
        // finding length
        while( ptr[i] != '\0' ) {
            i++ ;
        }
        Length = i;
        Data = new char[Length];

        int j = 0;
        while ( j<=Length ) {

                                    if ( j<Length ) {

                                        Data[j] = ptr[j];
                                        
                                    }
            
                                    else
                                    {
                                        Data[j] = '\0';
                                    }
            j++ ;

                          }
        
    }
    
    
    // Copy Constructor
    String ( const String &string1 ) {
        
        Length = string1.Length;
        Data = new char[Length];
        
        int j = 0;
        while ( j<Length ) {
            
            Data[j] = string1.Data[j];
            
        }
        
        if ( j == Length) {
            Data[j] = '\0'; // last character would be assigned as null
        }
    }
        
      // Destructor of String 
      ~String() {
        delete[]Data;
      }  

    // <------- Part 1  ------->
      int strLength() {
        return Length;
      }

    // <------- Part 2 ------->

       void clear() {

        delete[]Data;
        //deleting the previous array
        Data = new char[1];
        //making new dynammic array
        Data[0] = '\0' ;
        Length = 0;
        // making everything fresh and deleting the previous content

       }
    // <------- Part 3 ------->

    bool Empty() {

        if ( Length != 0 ) {
            return false;
        }

        else {
            return true;
        }
    }

    // <------- Part 4 ------->
    int charAt (char character) const {

        int result = 0;
        for (int i = 0; Data[i] != '\0'; i++){
            
            if (Data[i] == character){
               result = i; // Returning the index of the character
                break;
            }
            else {
                result = -1;
        }
       // result = -1;
        // If the character is not present in the string then returning -1
    }
        return result;
    }

       
    

    // <------- Part 5 ------->
    char* getdata() {
        return Data;
    }

    // <------- Part 6 ------->
    bool equal( char* ptr ) {

        int j = 0;

        while( ptr[j] != '\0') {
            j++ ;
        }
      int Length_of_string = j;

      if (Length != Length_of_string) {
        return false; // if the length of given string and existing string is not same then return false
      }

      else{

                    int counter = 0;
                    while ( counter < Length ) {


                            if ( Data[counter] != ptr[counter]) {
                                return false;
                            }
                            counter++ ;
                            
                    }
                    return true ;


      }



    }

// <------- Part 7 ------->


        bool equalsIgnoreCase (char* str) const
        {
                
            bool check;
            int j = 0;
            int length_str=0;
            int length_data=0;
            
            
            // length of str
            int i=0;
            while ( *(str+i) != '\0') {
               // length_str++;
                i++;
            }
            length_str = i;
            
            // length of data array
            int q=0;
            while ( Data[q] != '\0') {
               // length_data++ ;
                q++;
            }
            length_data = q;
            
            // if both lengths not equal then false
            if (length_str != length_data ){
                check = false;
            }
           
            int e = 0;
            while ( e<length_str ) {
                
                // check to see that both strings are same at the specified index i
                if (*(str+e) == Data[e] ){
                    e++ ;
                }
                
                
                
                // if strings are not equal then we will check upper case and lower case situation
                
                else {
                    // for str if at i th index it is between lowercase  and if we subtract the asci value 32 from it , and we get a same letter in upper case then check is true
                    if ( *(str+e) >= 'a' && *(str+e)<= 'z') {
                        
                                                                    if (*(str+e)- 32 != Data[e])
                                                                    {
                                                                        check = false;
                                                                        
                                                                    }
//                                                                    else {
//                                                                        check = false;
//                                                                    }
                    }
                    // for str if at i th index it is between uppercase  and if we add the asci value 32 from it , and we get a same letter in lowercase then check is true
                    
                    else if ( *(str+e)>= 'A' && *(str+e)<= 'Z') {
                                                                        if ( *(str+e) + 32 != Data[e])
                                                                        {
                                                                            check = false;
                                                                            
                                                                        }
//                                                                        else {
//                                                                            check = false;
//                                                                        }
                                                            }
                   
                  
                e++ ;
                } // moving to the next index of str and data
            }
            
            check = true;
            // now returning the stored check
            return check;
               
        }
    

// <------- Part 8 ------->    

char* substring(char* substr, int startIndex) {

  //calculating the length of substr
  int i = 0;
  while (substr[i] != '\0') {
    i++ ;
  }

  int Length_of_substr = i ;
    //int Length1 = Data.length ;
    
    int q =0;
    while(Data[q] != '\0') {
        q++;
    }
    int Length1 =q;
    
    for ( int i = startIndex ; i < Length1 ; i++) {
        
        int f = 0;
        while (f < (Length_of_substr && Data[i+f] == substr[f])) {
            f++ ;
        }
               
               if ( f == Length_of_substr ) {
            
            //new length will be the subtraction counter i and length then add one for the null char at last
            char* new_Array = new char[Length1-i+1];
            
            int t = i;
            while(t<Length_of_substr) {
                //storing data it will start from 0 and go till length of itself
                
                new_Array[t-i] = Data[t];
                
                t++;
            }
            new_Array[Length1-i] = '\0';
            // storing null character when the length is achieved
                   return new_Array;
        }
    }
               return NULL;
               }
    
  

    

// <------- Part 9 ------->
char* substring(char* str, int startIndex, int endIndex)  {

    int Length_of_new_string = endIndex - startIndex + 1;
    //adding one to add the space for null character
    char* new_str = new char[Length_of_new_string+1];
    // making a new character array of the new length to store the substring user wants
    
    int counter = 0;
    
    int i = startIndex; // starting the loop from start index and we will put condtion until it reacher end index
    while( i<= endIndex ) {
        
        new_str[counter] = Data[i];
        // new str will be started from counter as it will start storing from index 0 to forwards
        // Data is indexed from i which means the start index and the start index count will stop at end index
        
        
        i++;
        //incrementing the i
        counter++ ;
        //incrementing the counter index of new string
    }
    
    //adding null character at the end of new string
    new_str[counter] = '\0';
    //returning new string
    return new_str;
    
         }


// <------- Part 9 ------->
void print(){

if ( Length == 0) {
    cout<<"NULL \n";

}

else if ( Length>0 ) {

    int i = 0 ;
    while (i<Length) {
        cout<<Data[i];
        i++ ;

    }
//    cout<<"\n";
    cout<<"\n\n";



}

}

};

int main () {

    char* string = new char[100];
    
    cout << "Enter string:  \n";
    cin.getline(string, 100);

    String Sentence(string);
    // Returning the length of the string

    cout << "__________\n" ;
    cout << "Length of Sentence is: " << Sentence.strLength() <<"\n";





// Checking if the string is empty or not
     if (Sentence.Empty()){
        cout << "____________\n";
        cout << "String is empty \n" ;
    }

    else{
        cout << "____________\n";
        cout << "String is not empty \n";
    }



   cout << "____________\n";
   // Checking if the character is found or not

    char find;

    cout << "Enter the character to want to find :  \n";
    cin >> find;

    if ( Sentence.charAt(find)== -1){
        cout << "Character is not found \n";
    }

    else{
        cout <<"Character is found at index: " << Sentence.charAt(find) << "\n";
    }


  cout << "____________\n";
   // Returning the actual string

  cout <<"Original string is: " << Sentence.getdata() << "\n";

    cout << "____________\n";


 // Comparing the strings

   char *ptr = new char[100];

    cout <<"Enter String you want to compare:  \n";

    cin.ignore();      // Clearing the memory where the input is stored so that the getline function can work properly
    cin.getline(ptr, 100);

    if (Sentence.equal(ptr)){
        cout << "The Strings are equal \n" ;
    }

    else{
        cout <<"Strings are not equal \n\n" ;
    }


cout << "____________\n";

 // Comparing the strings while ignoring case
 char* str = new char[100];
    cout <<"Enter  string to be compared : \n\n";
    cin.ignore();
    cin.getline(str, 100);

    if (Sentence.equalsIgnoreCase(str)) {
        cout <<"Strings are equal \n\n" ;
    }

    else{
        cout <<"Strings are not equal \n\n" ;
    }

     cout << "____________\n";


 // Searching for a substring in the string using only start index
  char* ss = new char[100];

    cout <<"Enter the Substring you want to search:  \n\n";
    cin.ignore();
    cin.getline(ss, 100);

    int start_Index = 0;

    cout << "Enter starting index: \n\n";
    cin >> start_Index;

    char* q = Sentence.substring(ss, start_Index);

    if (q == NULL){
        cout << "____________\n";
        cout <<"Substring is not found \n\n";
    }

    else{
         cout << "____________\n";

        cout <<"The substring found: " << q << "\n\n";
    }



  // substring search with start and end index

  char* search = new char[100];

    cout << "____________\n";

    cout << endl << "Enter Substring you want to search: ";
    cin.ignore();
    cin.getline(search, 100);

    int starting_index = 0;
    int ending_index=0;

    cout <<"Enter the starting index:  \n";
    cin >>  starting_index;

    cout << endl << "Enter the end index: ";
    cin >> ending_index;

    char* subis = Sentence.substring(search, starting_index, ending_index);


    if (subis != NULL){
       cout << "____________\n";
         cout <<"Substring found: " << subis<<"\n\n";
    }

    else{
        cout << "____________\n";
        cout <<"Substring is not found" <<"\n\n";

    }


  // Printing the string
    cout <<"String:  ";
    Sentence.print();
    cout << "____________\n";
    

    cout <<"String after clear: ";
    Sentence.clear();
    Sentence.print();
    
    cout<<"\n";



        delete[] string;
        delete[] str;
        delete[] ptr;
        delete[] ss;
        delete[] search;

//      string = NULL;
//      str = NULL;
//      ptr = NULL;
//      ss = NULL;
//      search = NULL;

}


















































































        
        
        
        
        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

