#include <iostream>
using namespace std;

class RentalReservation
{
  
    string reservation_id;
    string customer_name;
    string car_make;
    string car_model;
    string pickup_date;
    string return_date;
    int rental_duration;
    double rental_rate;
    double rental_total;
    
public:
    
    
    
    
    
    // parametrised constructor
    RentalReservation(string reser_ID, string name, string carmake, string carmodel, string pickdate, string returndate)
    {
        reservation_id = reser_ID;
        customer_name = name;
        car_make = carmake;
        car_model = carmodel;
        pickup_date = pickdate;
        return_date = returndate;
        //rental_duration = calc_rentalduration();                            //( (rental_rate) / (return_date - pickup_date) )  ;
        //rental_rate = calc_rentalrate();
        //rental_total = calc_rentaltotal();
        
        
    }
    
    // destructor
    ~RentalReservation () {
        cout<<"The object is destroyed finally :) \n";
    }
    
    // setter and getter functions
    
    string getReservationID()   {
           return reservation_id;
       }
       
    void setReservationID( string id)   {
           reservation_id = id;
       }
    
    string getCustomerName()    {
            return customer_name;
        }
        
    void setCustomerName( string name)   {
            customer_name = name;
        }
    
    string getCarMake ()   {
        return car_make;
    }
    
    void setCarMake ( string p)   {
        
        car_make = p;
    }
    
    string getCarModel ()   {
        return car_model;
    }
    
    void setCarModel ( string w)   {
        car_model = w;
    }
    
    
    string getPickuDate()    {
            return pickup_date;
        }
        
    void setPickDate(  string pd)    {
            pickup_date = pd;
        }
    
    string getReturn_Date()  {
            return return_date;
        }
    
    
    
        
    double getRentalTotal()   {
        return rental_total;
    }

    void setReturn_Date( string r)   {
            return_date = r;
        }
    
    int getRentalDuration()   {
            return rental_duration;
        }
    
    double getRentalRate()   {
            return rental_rate;
        }
    
//    int total=0;
//    //counting the length of the reservation ID
//    void lengthcheck_of_ID( char str[] ) {
//
//        // char str[20] = q;
//        int i = 0;
//        while (*(str+i) != '\0'   ) {
//            i++;
//        }
//
//        total = i;
//
//    }
        
        
    // part 1
    bool is_valid_password(char* password)  {
        
        const char special_characters[] = "!@#$%^&*()_?/.,|{}][+=:;'";
        int special_character_count = 0;  // to count that string has 2 special characters
        int last_digit_count = 0;   // to count that string has 4 digits
        int sum_of_digits = 0;  //sum of last 4 digits that needs to be less than 18
        
        //first of all we will count the length of string
        int u=0;
        while( *(password+u) != '\0' ) {
            u++;
        }
        int string_length = u;
        
        // length must be 8 if no that return false
        if (u != 8) {
            return false;
        }
     
        //this loop is checking that there are 4 digits in the ID
        for (int i = 0; i < 8; i++) {

            char c = *(password+i);

            if (c >= '0' && c <= '9') {
               // count++;
                last_digit_count++ ;
                sum_of_digits += c - '0';
                
                   }
        
            else {
            
            for (int j = 0; j < 8 ; j++) {
          
                   // char p = password[j];
                    if (c == special_characters[j]) {
                        special_character_count++;
                    
                                                    }
                                                }
                
                }
        }
        
        if ( last_digit_count != 4) {
            return false;
        }
        

        if (special_character_count != 2) {
            return false;
        }

        if (sum_of_digits >= 18) {
            return false;
        }

        return true;
    }
    
    
    /* part 2 */
    
    bool validate_make_and_model ()   {

        if( (car_make =="Toyota" || car_make =="Suzuki" || car_make =="Honda" || car_make =="Audi" ) && (car_model=="A6" ||car_model=="City" || car_model=="Corolla" || car_model=="Land Cruiser" || car_model=="Mehran" || car_model=="Alto") ) {
            return true;
        }
        
        else
            return false;
    }

    
    /* part 3 */
    
    int calculateRentalRate()    {
        // this function will return the rental rate for a specific car based on its make and model
        if (car_make == "Toyota" && car_model == "Corolla") {
            rental_rate = rental_rate + 50000;
        }
        
        else if (car_make == "Toyota" && car_model == "Land Cruiser") {
            rental_rate = rental_rate + 90000;
        }
        
        else if (car_make == "Honda" && car_model == "City") {
            rental_rate = rental_rate + 35000;
        }
        else if (car_make == "Suzuki" && car_model == "Mehran") {
            rental_rate = rental_rate + 15000;
        }
        else if (car_make == "Suzuki" && car_model == "Alto") {
            rental_rate = rental_rate + 17000;
        }
        
        else if (car_make == "Audi" && car_model == "A6") {
            rental_rate = rental_rate + 48000;
        }
        
        return rental_rate;
        
    }
    
    /* part 4 */
    
    int Helper(string& str,  int total,  int i)   {
        int length = str.length();
        //this function is calculating the length of string
        
        if ( i < length ) {
            // we will start counter so that each letter is considered

            if ( str[i] -'0'>=0 && str[i]-'0'<=9) {
                
                // anything subratacted from '0' gives us the same number in integer form but but we need to make sure that it must only lay between 0-9
                total = (total*10) + str[i] -'0';
              
                //for each that digit which agter getting subtracted given one integer
               return  Helper(str,total,i+1);
                //recursive call for the function with i incremented with one to check the next digit
            }

            else if ( str[i]>='!' && str[i]<='/') {
                return 0 + Helper(str,total,i+1);
                // if the current letter is any character of the given range then it will just increment with i+1 to move to next letter
            }


                return total;
    }
        return total;
    }
    
    int calculateRentalTotal()   {
        // this function will return total rent which will be calculate by multiplying number of days with rental rate calculated above
        
        int entry_Date = Helper(pickup_date,0,0);  //// recusrive function to convert string dates in to integer
        int exit_Date = Helper(return_date,0,0);
        entry_Date = entry_Date / 100; // dividing by hundred so that month part of date gets eliminated
        exit_Date = exit_Date / 100;
        int Days;
        
        if ( exit_Date > entry_Date ) {
             Days = exit_Date - entry_Date;
        }
        
        // this if condition will cater the case for the situation where month is changing
        if ( entry_Date >= exit_Date) {
            entry_Date = 1 ;
            Days = exit_Date + entry_Date;
            
            
        }
       //multiplying it the number of days with rate to find out rent for that specific number of days
        double TotalRENT = Days * rental_rate;
        return TotalRENT;
        
    }
    
    
    /* part 5 */
    void getReservationDetails()  {
        
        
        cout<<"Name: "<<customer_name<<endl;
        cout<<"Your Reservation ID: "<<reservation_id<<endl;
        cout<<"Your Car Make: "<<car_make<<endl;
        cout<<"Your Car Model: "<<car_model<<endl;
        cout<<"Pick up Date of the Car: "<<pickup_date<<endl;
        cout<<"Return Date of the Car: "<<return_date<<endl;
        cout<<"Rental Rate for your rented Car is: "<<rental_rate<<endl;
       
        cout<<"Total Rental Rate based on rental duration is: "<<calculateRentalTotal()<<endl;
    
    }

    
    
    
    
    /* part 6 */
    
    void Update_Rental_Info()   {
        
        int Press_key;
        
        cout<<" Welcome! Please Let us know what do you want to update? \n";
        cout<<" Press 1 to update Car make and model\n";
        cout<<" Press 2 to update Pickup Date \n";
        cout<<" Press 3 to update Return Date \n";
        cout<<" Press 4 to update Rental Rate \n";
        cin>>Press_key;
        
        if ( Press_key < 1 || Press_key > 4) {
            cout<<" You have entered invalid Press \n";
            cin>>Press_key;
        }
        
       
        else  {


        if ( Press_key == 1) {
            //changes in car make
            string m;
            string l;
            cout<<"Enter the name of car make: \n";
            cin>>m;
            setCarMake(m);
            
            cout<<"Enter the name of car model : \n";
            cin>>l;
            setCarModel(l);
            calculateRentalRate();  // updating the rent as per the updated model and car
            calculateRentalTotal(); // updating total as the rate is updates



        }


        else if ( Press_key == 2) {
            //changes in pickup date
            string pkd;
            cout<<"Enter the new Pick up date: \n";
            cin>>pkd;
            setPickDate(pkd);
            calculateRentalRate();
            //seting the total again with respect to new pickup date
            calculateRentalTotal();

        }

        else if ( Press_key == 3) {
            //changes in return date
            string rtd;
            cout<<"Enter the new Return date: \n";
            cin>>rtd;
            setReturn_Date(rtd);
            calculateRentalRate();
            // seting the total again with respect to new return date
            calculateRentalTotal();



        }
        
        
        else if ( Press_key == 4) {
            //changes in rental rate;
            string cme; // car make
            string cml; // car model
            cout<<"Enter the changes you want to make in Rental rate therefore enter car make : \n";
            cin>>cme;
            setCarMake(cme);
              cout<<"Enter the changes you want to make in Rental rate therefore enter car model : \n";
            cin>>cml;
           setCarModel(cml);
            calculateRentalRate();
            calculateRentalTotal();

        }

        cout<<"Your information is updated succesfully \n";
        //now displaying the update version
        getReservationDetails();

        }
    }
    
    
};
    
    int main() {
        
        RentalReservation R1("ur!#1234", "urwah", "Suzuki","Mehran", "16-03", "18-03");
       char test[] = "ur!#1234" ;
         char* str1 = test;
        if ( R1.is_valid_password(str1) == 1) {
            cout<<"The ID follows the condtions: "<<" "<<R1.getReservationID()<<endl;         // This is working right
            cout<<"pickup date: "<< R1.getPickuDate()<<endl;                                  // This is working right
            cout<<"return date: "<< R1.getReturn_Date()<<endl;                                // This is working right
            cout<<"Your rental rate is: "<<R1.calculateRentalRate()<<endl;                    // This is working right
            cout<<"Total rent is: "<< R1.calculateRentalTotal()<<endl;                        // This is working right
            cout<<endl<<endl;
           R1.getReservationDetails();// This is working right
            cout<<endl<<endl;

           R1.Update_Rental_Info();                                                           // This is working right
            cout<<R1.validate_make_and_model ()<<endl;                                        // This is working right
            
        }
        
        else {
            cout<<"You entered a wrong ID \n";
        }
        
        
    }
