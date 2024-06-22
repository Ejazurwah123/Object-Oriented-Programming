
#include <iostream>
//#include "C.png"
using namespace std;

class Profile
{
private:
    
    string user_ID;
    string username;
    int number_of_posts;
    string email_address;
    double followers;
    double likes;
    double comments;
    string password;
    string Profile_picture;
    static int number_of_likes;
    static int total_posts;
    
public:
    
    
   //  default constructor
    Profile() {
            user_ID= "";
            username="";
            number_of_posts=0;
            email_address="";
            followers=0;
            likes=0;
            comments=0;
            password="";
        
    }
    
    //Parametrised constructor
    Profile( string userID, string usrname, int posts_count, string email, double foLLowers, double like, double coments, string passcode)
   
    {
        
        user_ID = userID;
        username = usrname;
        number_of_posts = posts_count;
        email_address = email;
        followers = foLLowers;
        likes = like;
        comments = coments;
        password = passcode;
        Profile_picture = "default.png ";
        
    }
    
    
    void set_UserId( string Id) {
        user_ID = Id;
    }
    
    string get_UserId() {
        return user_ID;
    }
    
    void set_username(string usr) {
        username = usr;
    }
    
    string get_Username() {
        return username;
    }
    
    void set_num_of_posts( int num ) {
        number_of_posts = num;
    }
    
    int get_num_of_posts() {
        return number_of_posts;
    }
    
    void set_email_address(string em) {
        email_address = em;
    }
    
    string get_email_address() {
        return email_address;
    }
    
    void set_followers(int fol) {
        followers = fol;
    }
    
    int get_followers() {
        return followers;
    }
    
    void set_likes ( int lik) {
        likes = lik;
    }
    
    int get_likes () {
        return likes ;
    }
    
    void set_comments( int com_count ) {
        comments = com_count;
    }
    
    int get_comment() {
        return  comments;
    }
    
    void set_password( string pass ) {
        password = pass;
    }
    
    string get_password() {
        return  password ;
    }
    
    string getProfilePicture(){
        return Profile_picture;
    }
    
    void setProfilePicture(string pic) {
        Profile_picture = pic ;
    }
    
    
    //destrutor
    ~Profile () {
        cout<<"Your object is finally destroyed"<<endl;
    }
    
    

    /* --------------------Part 1 email checking-------------- */
    bool validateEmail(string str) {
    
        int At;  // to find the index number on which at the rate comes
        int dot; // to find the index number on which the dot comes
        bool check_has_at_the_rate = false;
        bool check_has_dot = false;
        
      
        
        int start=0;
        while (start< str.length()){
            
            if (str[start] == '@') {
                
                At=start;
                check_has_at_the_rate = true;
            }
            
            else if (str[start] == '.') {
                
                dot = start;
                check_has_dot = true;
                
          
            }
            
            start++;
            
        }
        // if we have both false values of at the rate check and dot check then our function will not commence instead it will return false right here
        if (!check_has_at_the_rate || !check_has_dot) {
            return false;
        }
        
        // checking that the domain which comes between at the rate and dot is valid domain
        string Domain_Extract = "";
        bool Domain_Check = false;
        
        int y = At;
        
        while ( y<dot) {
            if (Domain_Check ) {
                                  //getting the domain so that we could check it further with the specified domain
                                Domain_Extract += str[y];
                            }
              else if (str[y] == '@') {    //bool check to see if we are having at the rate at y index
                                          Domain_Check = true;
                                       }
           
            y++ ;
        }
        
      // all valid domains
        string domain1 = "gmail";
        string domain2 = "yahoo";
        string domain3 = "icloud";
        string domain4 = "hotmail";
        
        
        bool Email_Validated = false;
        
        // if any of the domain matches the domain we extracted it means the email is validated
       
                            if ((Domain_Extract == domain1) || (Domain_Extract == domain2)  || (Domain_Extract == domain3)  || (Domain_Extract == domain4))
                            {
                                Email_Validated  = true;
                            }
        
        
        bool Final_check = false;
        
        // now if all conditions are met we have at the rate before dot and the domain is valid domain then the function will return true
        if ( Email_Validated && check_has_at_the_rate && check_has_dot ) {
            Final_check = true;
        }
       
        return Final_check;
    }
    
    
    /*--------------------------- Part 2 Password Checking--------------- */
    
     string getPasswordStrength(string pass) {
        
         string ans;
        int Alphabet_count=0;
        int special_character_count=0;
        int digit_count=0;
        
       // if ( pass.length() >= 12) {
            // first conditions that the length must be greater than 12 for a strong pass
        
        //string* str = arr;
        
        char str[200];
        int t=0;
        while ( t< pass.length() ){
            
         str[t] = pass[t];
            t++;
        }
        //cout<<t<<endl;
        
            for ( int i=0; i< pass.length(); i++ ) {
                
                if ( ( str[i] >='a' && str[i] >='z' ) || ( str[i]>='A' && str[i]>='Z' )) {
                            Alphabet_count++ ;
                   
                    //counting the number of Alphabets
                
                 }
                    
                    else if ( (str[i]>='!' && str[i]<='/') ||   (str[i]>=':' && str[i]<='@') )
                    {
                    special_character_count++ ;
                        
                    //count special characters
                    
                     }
                    
                    else if (str[i]>='0' && str[i]<='9') {
                    digit_count++ ;
                        
                    }
                
            
       }
        
       // cout<<Alphabet_count<<endl;
       // cout<<special_character_count<<endl;
       // cout<<digit_count<<endl;
                    
                    // criteria for strong password
        if ( (Alphabet_count>=7 && Alphabet_count<=10) || ( pass.length()>12  && pass.length()<30) || (special_character_count>=5 && special_character_count<=7 ) || (digit_count>=5 && digit_count<=7) )
                    {
                                           // cout<<"This is a strong password \n";
                       ans = "strong";
                          }
        
                    //crtieria for weak-middle password
                    
                   else if ( (Alphabet_count<6 && Alphabet_count>3 ) || ( pass.length()>7 && pass.length()<12) || (special_character_count>3 &&  special_character_count<5) ||
                            (digit_count>3 &&  digit_count<5)  )
            
                    {
                                           // cout<<"This is an average password \n";
                        ans= "Average";

                          }
                    
                    //crtieria for weak password
        
                   else if ( (Alphabet_count>1 && Alphabet_count<3 ) || ( pass.length()>2 && pass.length()<6) || (special_character_count<3 &&  special_character_count>0) ||
                            (digit_count>1 &&  digit_count<3) )
                    {
                                          //  cout<<"This is an weak password \n";
                        ans = "Weak";
                          }
         return ans;
        
    }

  /* -------------- Part 3 ------------- */
    
    float getProfileCompletionPercentage() {
        
        
        if ( (getPasswordStrength(get_password()) == "strong" ||  getPasswordStrength(get_password()) == "Average") &&  ( followers>=100 ) && (validateEmail(get_email_address()))   ) {
            
            return 100.0;  //if staisfies all these fields then it means profile is completed 100%
        }
        
        else if ( (getPasswordStrength(get_password()) == "Weak") && followers>=50 )
        {
            return 50.0;       // half field satisying hence 50 percent is completed
        }
        
        
        
    }
    
    /* ------------- Part 4 -------------*/
        
    void getUserActivity() {
        
        cout<<"Below is the data of the user \n";
        cout<<"Number of posts are: "<<get_num_of_posts()<<endl;
        cout<<"Number of likes: "<<get_likes()<<endl;            
        cout<<"Number of comments: "<<get_comment()<<endl;
        cout<<"Number of followers: "<<get_followers()<<endl;
         
     }

  /* -------------Part 5----------- */



  /* -------------Part 6----------- */



  static int get_Number_of_likes() {

    return number_of_likes;  // total number of likes a user has done

  }

 /* -------------Part 7----------- */
  static int get_total_number_of_posts() {
    return total_posts ;  //  total number of posts a user has done
  }

   /* -------------Part 8----------- */



   void Update_Profile() {
    
        int Press;
        cout<<"Read the following instructions to update your profile accordingly \n";
        cout<<"Press 1 to update Username \n";
        cout<<"Press 2 to update your email address \n";
        cout<<"Press 3 to update your Password \n";
       cout<<"Press 4 to update your profile picture \n";
        cin>> Press;

        //switch (Press)
       // {
                
                
        //case (1):
       if ( Press == 1 ) {
           
    // updation case 1 : if user wants to edit username then he will be asked to enter and we will set that username using setter
            cout<<"Enter the new Username \n";
                cin>>username;
                set_username(username);
                cout<<"Your username has been updated: \n";
                cout<<get_Username()<<endl;
                
           // break;
      }
       
       // case (2):
        
       else if( Press == 2) {
      
                // updation case 2 : if user wants to edit email then he will be asked to enter, program will validate email and  we will set that email using setter
            cout<<"Enter your new email \n";
            cin>>email_address;
                if(validateEmail(email_address)){
                    
                set_email_address(email_address);
                cout<<"Your email has been updated: \n";
                cout<<get_email_address()<<endl;
                }
                
                else {
                    cout<<"You have entered invalid email address. Retry \n";
                    cin>>email_address;
                    
                    if(validateEmail(email_address)){
                        
                    set_email_address(email_address);
                    cout<<"Your email has been updated: \n";
                    cout<<get_email_address()<<endl;
                    }
                }
         ///  break;
       }
         
         //   case (3):
       
       else if (Press==3) {
                // updation case 3 : if user wants to edit password then he will be asked to enter, program will validate password and  we will set that password using setter
            string passcode;
            cout<<"Enter your new password: \n";
                cin>>passcode;
                getPasswordStrength(passcode);
                
                if ( getPasswordStrength(passcode)== "strong" || getPasswordStrength(passcode)== "strong" ) {
                    set_password(passcode);
                    cout<<"Your password has been update \n";
                    cout<<get_password()<<endl;
             
                    }
                    else {
                        cout<< "You've entered a weak password. Retry with some other passcord \n";
                    
                            cin>>passcode;
                            getPasswordStrength(passcode);
                            
                            if ( getPasswordStrength(passcode)== "strong" || getPasswordStrength(passcode)== "strong" ) {
                                set_password(passcode);
                                cout<<"Your password has been update \n";
                                cout<<get_password()<<endl;
                         
                           }
                    
                                }
       }
                
                
              
                
   // case (4) :
       
       else if (Press==4) {
                
                cout<<"What is your new profile picture \n";
                cin>>Profile_picture;
                
                setProfilePicture(Profile_picture);
                cout<<"Updated profile pictue is "<<getProfilePicture()<<endl;
        
               // break;
                
                
                
        }



   }



 
        };

 


 int Profile::number_of_likes = 0;
 int Profile::total_posts = 0;

   




int main() {
    Profile P1;
    if ( P1.validateEmail("urwahejaz@gmail.com")  )
     {
        cout<<"you have entered a valid email \n";
    }
    
    else {
        cout<<"You have entered a invalid email \n";
    }
    P1.getPasswordStrength("Urwah@*&^^^^433352");
    P1.Update_Profile();
    
}
