# Object-Oriented-Programming
Applications of basic to advanced level concepts of object oriented programming

## Question 2
Grouping Two-Dimensional Data Points in C++
This C++ program performs grouping of a set of two-dimensional data points into 3 clusters using an iterative approach to adjust the cluster centroids until convergence. The program demonstrates Object-Oriented Programming (OOP) concepts including classes, objects, and encapsulation.

## Question 3
Implement your own string class using only primitive data types. Your string class should
contain some of the same functionality as the string class in C++.

Your class should have the following member variables:
1. char *data: holds the character array that constitutes the string
2. int length: the current length of the string that the object contains (number of characters
in data)

1. String() default constructor
2. String(int size): alternate constructor that initializes length to size and initializes data to a
new char array of size.
3. String(char* str): alternate constructor that initializes length to size of str, initializes data
to a new char array of size length and fills the contents of data with the contents of str.
Note: You can assume that any character array that is sent as str will be
terminated by a null character (‘\0’)
4. String(const String &str): copy constructor.
5. ~String(): destructor in which you should delete your data pointer.
Your class should have the following functions:
1. int strLength():returns the length of the string in the object.
2. void clear(): should clear the data in your string class (data and length)
3. bool empty(): this method should check to see if data within the String class is empty or
not.
4. int charAt(char c): this method returns the first index at which this character occurs in the
string
5. char* getdata(): a getter to get the actual string.
6. bool equals(char*str): this method compares if the data in the calling string object is
equal to str.

7. bool equalsIgnoreCase(char* str): this method compares the calling string object data
with the data in str without considering the case.
8. char* substring(char* substr, int startIndex) : this method should search for substr in
data within the calling String object starting from the startIndex. The method should search
for the substring from the startIndex and return the substring from the position found till
the end. For example, if you had the string “awesome” and you wanted to find the
substring ‘es’ starting from the beginning of the string (startIndex = 0). Your function
should return “esome”. Returns NULL if substring is not found.
9. char* substring(char* substr, int startIndex, int endIndex) : this method should search
for substr in data within the calling String object between the startIndex and endIndex. For
example, if you had the string “awesome” and you wanted to find the substring ‘es’
starting from startIndex=2 and endIndex=5. Your function should return “esom”. Returns
NULL if substring is not found.
10. void print(): a function that will output the contents of the character array within the
object. If the contents of the String are empty (length == 0) then you should print
“NULL”.
Additional Specifications:
● Your program should have NO memory leaks
● You should not use the built-in C++ string class anywhere in your object.
● You must appropriately use the const keyword (you need to decide which functions
will be constantly qualified and which will not).
● You may define additional helper functions as needed.



## Question 4

Implement a class Matrix to create matrices of 2x2, 3x3 and 4x4 with the following private
datamembers:
1. int **matrix – a double pointer of type integer to create a 2D array (matrix)
2. int row – an integer to store the rows in the matrix

3. int col – an integer to store the columns in the matrix.
The class shall have the following public member functions:
1. Matrix (int n1, int n2, int n3, int n4, int row = 2, int col = 2) – a
parametrized constructor for a 2x2 matrix
2. Matrix (int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int
row = 3,int col = 3) – a parametrized constructor for a 3x3 matrix
3. Matrix (int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int
n10, intn11, int n12, int n13, int n14, int n15, int n16, int row = 4, int col = 4)
– a parametrized constructor for a 4x4 matrix
4. Matrix(const Matrix &m) – a copy constructor
5. ~Matrix() – a destructor
6. int getRow() – a getter for rows
7. int getCol() – a getter for columns
8. int getValue(int row, int col) – a function to get the value at the given
row and column of a matrix
9. void setValue(int row, int col, int value) – a function to set the value at a given
rowand column index of a matrix.
10. int Total() - Calculate the total/sum of all the values in the matrix.
11. double Average() - Calculates average of all the values in the array.
12. int RowTotal(int row) - Calculates total/sum of the values in the specified row.
13. int ColumnTotal(int col) - Calculates total/sum of the values in the specified
column.
14. int HighestInRow(int row) - Finds highest value in the specified row of the array.
15. int LowestInRow(int row) - Finds lowest value in the specified row of the array.
16. Matrix Transpose() - Find Transpose of array.
17. int LeftDiagonalTotal() - Calculates total/sum of the values in the left
Diagonal of array.
18. int RightDiagonalTotal() - Calculates total/sum of the values in the right
Diagonal of array.
19. Matrix Add(Matrix m) – adds the calling object matrix with the one
passed as an argument and returns a resultant matrix

20. Matrix Subtract(Matrix m) – subtracts the calling object matrix with the one
passedas an argument and returns a resultant matrix
21. Matrix Multiply(Matrix m) – multiplies the calling object matrix with the one
passedas an argument and returns a resultant matrix
22. int FindkSmallest(int k) – a function that finds the k

th smallest element in the
matrix.If k is 1, return the smallest element. If k is 2 return the second smallest
element andso on.
23. int FindkLargest(int k) – a function that finds the k
th
largest element in the
matrix. Ifk is 1, return the largest element. If k is 2 return the second largest
element and so on.
24. Matrix merge(Matrix m) - a function to merge two matrices.

## Question 5

You are developing a social media platform where users can create and manage their profiles.
Write a class named Profile that has private instance variables for user ID, username, number of
posts, email address, followers, likes, comments, password, and profile picture. The class should
have getter and setter methods for each instance variable, a constructor that takes user ID,
username, email address, and password as parameters, and initializes the profile picture to the
default image. The class should also have a destructor that prints a message when the object is
destroyed. The Profile class should have the following methods:

1. A const member function named validateEmail that checks if the email address entered
by the user is valid or not. You can validate by checking if the email address has the
correct format, including an "@" symbol and a valid domain name.
2. A const member function named getPasswordStrength that returns the strength of the
password entered by the user. You can define password strength based on various criteria,
such as length, complexity, and character types used. For example, a character that has 12
characters, special characters, lower- and upper-case characters, numbers, etc.
Medium-strength passwords would be weaker, while weak being the weakest.
3. A const member function named getProfileCompletionPercentage that calculates the
percentage of completed fields in the profile. You can define the completion criteria
based on the required and optional fields in the profile. Having a strong password, a
profile picture, and 100+ followers, are a few fields that can be used to determine the
Completion Percentage.
4. A const member function named getUserActivity that returns the user's activity statistics,
such as the number of posts, likes, comments, and followers.
5. A const member function that validates if the private variable “Profile Picture” is an
existing file path.
6. A function that returns the number of totals like a user has done.
7. A function that returns the total number of posts of a user.
8. A member function that allows users to update profile information. They can choose what
they want to update through this function.

## Question 6

You are developing a car rental platform where users can create and manage their rental
reservations. Write a class named RentalReservation that has private instance variables for
reservation ID, customer name, car make and model, pickup date, return date, rental duration,
rental rate, and rental total. The class should have getter and setter methods for each instance
variable, a constructor that takes reservation ID, customer name, car make and model, pickup
date, and return date as parameters, and calculates rental duration, rental rate, and rental total
based on the pickup and return dates and the car's rental rate. The class should also have a
destructor that prints a message when the object is destroyed. The RentalReservation class
should have the following methods:
1. A const member function named validateReservationID that checks if the reservation ID
entered by the user is valid or not. You can validate by checking if the reservation ID has
the correct format by verifying if the ID has 8 characters, followed by 2 special
characters, and finally ending with 4 numbers. The sum of the four numbers must be less
than 18.

2. A const member function that validates if the private variable “Car Make and Model” is
an existing option.
3. A const member function named calculateRentalRate that calculates and returns the
rental rate for a specific car based on its make and model.
4. A const member function named calculateRentalTotal that calculates and returns the total
cost .
5. A const member function named getReservationDetails that returns the reservation
details, such as the reservation ID, customer name, car make and model, pickup date,
return date, rental duration, rental rate, and rental total.of the rental based on the rental
duration and rental rate.
6. Generate a member function that allows users to update their rental reservation
information. They can choose what they want to update through this function, such as the
pickup or return date, the car makes and model, or the rental rate. The function should
also recalculate the rental duration, rental rate, and rental total based on the updated
information. Additionally, the function should validate the input data and make sure it is
within acceptable ranges.
The car options are as follows: Suzuki Mehran, Suzuki Alto, Honda City, Toyota Corolla, Toyota
Land Cruiser, and Audi A6. These cars can have different models, and rates would reflect that.
You are allowed to set the rates on your own.