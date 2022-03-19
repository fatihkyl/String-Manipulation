//**********************************************************************************************
// C++ String Manipulation Challenge
//Author: Fatih Kayali
//This program including all the code is my own work and has been tested fully 
// *********************************************************************************************

#include <iostream> //defines the standard devices cin, cout, clog, cerr.
#include <string> //defines string types and conventions including begin & end iterator.
#include <algorithm> //defines a collection of ranged functions.
#include <random> //defines random number generation facilities.

using namespace std; //tell the compiler that by default to use the “std” – this means that we don’t need to keep saying “std::cout” we can just use: “cout”

string GetWord(void) 
{ //this function should allow the user to enter a new word that can then be later manipulated
  string localString = ""; //declare and initialise a local string, used to store the new string
  cout << "\nPleae enter a new word or phrase: "; //by not including an end of line the input will be on the same line as the output message
  cin.ignore() ; //this is fors for avoiding over looping and for entering more than one word in to the input 
	getline(cin,localString); //get the input value from the user and store it in the local variable 'localstring'
  
  return localString; //pass the value stored in 'localstring' back to the calling instruction
}

void QuitNow(void) 
{ // this function allows user to quit the program when they    wanted to 
	cout << endl << endl << "Thank you for using StringWorld - please come back soon" << endl; //display a bye message in the end
	exit(EXIT_SUCCESS); //execute the c++ exit function and pass it c++ contant value called EXIT_SUCCESS; EXIT_SUCCESS is actually 0 -
}

string ReverseWord(string originalString) 
{ //this function is designed to expect one aurgument (called originalString) and returns a string. This function allows user to reverse the entered word or words
	string localString; //declare and initialise a local string, used to store the new string
	int len; //declare a local variable called len of type integer (whole numbers)

	len = originalString.length(); //execute a special function (part of the 'string' datatype) that returns the number of character contined in the variable
	
    for (int i = len-1; i >= 0; i--) 
    {
		//this executes a loop that uses and decreases a local and temporary variable (i) staring with the value contained in 'len' while 'i' is great than or equal to 0
		localString = localString + originalString[i]; //essentially this instruction adds the specific letter at position 'i' in the string variable 'originalString' to the 'localstring' variable
	  }
	//at this point the 'localString' variable should now contain the same information as originalString

  return localString; //return the value contained in the localstring local variable
}

string ToUpper(string originalString) 
{ //this function is designed to expect one aurgument (called originalString) and returns a string. This function allows user to convert all of the letters to upper case
 
  string localString = originalString; // declare a local variable called localstring and equalize to originalString
  for(int i=0;i<originalString.length();i++) //should be as same length as the originalString's 
  {
    if(localString[i]>=int('a') && localString[i] <=int('z')) //if the letter is between lowercase "a" and lowercase "z"
    {
      localString[i]=originalString[i]-32; //subtract 32 ASCII value to that letter's ASCII value, it will convert that letter into uppercase
    }
  }

return localString; //return the value contained in the localstring local variable
}  
 
string ToLower(string originalString) 
{ //this function is designed to expect one aurgument (called originalString) and returns a string. This function allows user to convert all of the letters to lowercase
  string localString = originalString; // declare a local variable called localstring and equalize to originalString
  for(int i=0;i<originalString.length();i++) //should be as same length as the originalString's 
  {
    if(localString[i]>=int('A') && localString[i] <=int('Z')) //if the letter is between capital "A" and capital "Z"
    {
      localString[i]=originalString[i]+32; //add 32 ASCII value to that letter's ASCII value, it will convert that letter into lowercase
    }
  }
 return localString; //return the value contained in the localstring local variable
}

string RandomiseWord(string originalString) 
{ //this function is designed to expect one aurgument (called originalString) and returns a string. This function allows user to randomise the entered word
  string localString; //declare and initialise a local string, used to store the new string
  random_shuffle(originalString.begin(),originalString.end()); //code for the randomise, already in the C++
  localString = originalString;  // declare a local variable called localstring and equalize to originalString
  
  return localString; //return the value contained in the localstring local variable
}

string OrderWord(string originalString) 
{ //this function is designed to expect one aurgument (called originalString) and returns a string. This function allows user to order letters in ascending order
  string localString = originalString; // declare a local variable called localstring and equalize to originalString
  ToLower(localString); // it is for sorting the letters in lowercase letters, without it OrderWord orders the uppercase letter first, than orders lowercase letters
  int len=originalString.length(); //add an integer for declaring the original string length. execute a special function (part of the 'string' datatype) that returns the number of character contined in the variable
  for (int i=0 ; i<len ; i++) 
  {
    for (int j=0 ; j<len;j++)
    {
      if(localString[i]<localString[j]) // compare the values of i to j, declare which comes first
      {
        char tmp = localString[i];
        localString[i]=localString[j];
        localString[j]=tmp;
        
      }
    }
  }
  return localString; //return the value contained in the localstring local variable
}

void Menu() 
{ //this function displays the menu to the user
  string currentString="18009814"; //declare and initialise the variable to hold the current word ready to be manipulated
  string modifiedString="nothing"; //declare and initialise the variable to hold the last modified wordno
  char menuOption; //declare a variable to hold the user's menu choice
  
  do 
  { //start an endless loop - this is so the associated code block repeats forever
    cout << "\n\nC++ String Manipulation Challenge " << endl << endl; //display a title for the menu
    cout << "\t1. Enter a word or phrase (current word/phrase is: " << currentString << ")." << endl; //display the current string 
		cout << "\t2. Reverse the current word." << endl;
    cout << "\t3. Convert the current word to uppercase." << endl;
    cout << "\t4. Convert the current word to lowercase." << endl;
    cout << "\t5. Randomise the letters in the current word." << endl;
    cout << "\t6. Sort the letters in the current word in ascending alphabetic order." << endl;
		cout << "\t0. Quit StringWorld" << endl;
    cout << "\n\n\tThe last word/phrase returned was: " << modifiedString << endl;
    cout << "\nPlease enter a valid option (1 - 6 or 0 to quit): ";
    cin >> menuOption; //store the choice made by the user in the variable menuOption

    switch(menuOption) 
    { //a 'switch' statement is similar to multiple if's.

      case '1': //this basically "if the menuOption = 1", option 1 should call the function GetWord() 
        cout<<"\033c"; //Clear Linux console, it is a displaying option.I just wanted to show the user a clear page when the user wants to enter a word

        currentString = GetWord(); //call the function and store any returned value in the local variable currentString

        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed

      case '2': //this basically "if the menuOption = 2", option 2 should call the function ReverseWord 

        modifiedString = ReverseWord(currentString); //call the function and store any returned value in the local variable modifiedString
        
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed
      
      case '3': //this basically "if the menuOption = 3", option 3 should call the function ToUpper()

        modifiedString = ToUpper(currentString); //call the function and store any returned value in the local variable modifiedString
        
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed

      case '4': //this basically "if the menuOption = 4", option 4 should call the function ToLower()

       modifiedString = ToLower(currentString); //call the function and store any returned value in the local variable modifiedString
       
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed

      case '5': //this basically "if the menuOption = 5", option 5 should call the function RandomiseWord()

      modifiedString = RandomiseWord(currentString); //call the function and store any returned value in the local variable modifiedString
        
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed

      case '6': //this basically "if the menuOption = 6", option 6 should call the function OrderWord()
      //conver to lower case before sorting them

      modifiedString = ToLower(currentString); // it first converts entered word to lowercase then orders the word
      modifiedString = OrderWord(modifiedString); //call the function and store any returned value in the local variable modifiedString
      
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed
      
      case '0': //this basically "if the menuOption = 0", option 0 should call the function QuitNow

      {
      string decision; //to create a decision function
        
        cout<<"\n\tAre you sure (Y/N)?\n";
        cin>>decision;
          if (decision == "Y") { // if user enters "Y" compiler replies back with QuitNow(); function
            
            QuitNow(); // call and activate the function QuitNow
          }
          if (decision == "y") { // if user enters "y" compiler replies back with QuitNow(); function
            
            QuitNow(); // call and activate the function QuitNow
          }
          if (decision == "Yes") { // if user enters "Yes" compiler replies back with QuitNow(); function
            
            QuitNow(); // call and activate the function QuitNow
          }
          
          else
          { // if the user not enters "Y","y" or "Yes" compiler will start the program from Menu() functon
            Menu();
          }
          
          break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed
      }
      default:
      //if the user enters a non-valid option this default message will display
      cin.ignore() ; // if the user multipe values for entering an option case the compiler will just reads the first, ignores the others
        cout<<"\n\tUnfortunately ‘"<<menuOption<<"’ is not a valid option, please try again.";
    }
  } while(true); //this tells the computer the conditions to break the "do" loop - while true is always true and therefore will continue forever; in essence and endless loop
}

int main() 
{ //this is the required function that will automatically execute when the program is run
  Menu(); //start the program menu function
}

// TEST LOG
//GetWord function has added but not working properly. It just works when one word has entered, when two or more words entered compiler just reads the first one.
//Problem has solved by adding cin.ignore();
//
//ReverseWord function has errors
//It has solved by changing i++ to i--
//
//There is an issue with the ToUpper function, it doesn't convert everything in to upper case
//Problem has solved by changing double quote to single quote
//
//ToLower just works fine, exactly the same as ToUpper just values are different
//
//RandomiseWord works perfect thanks to random_shuffle order
//
//OrderWord is working properly, but when upper and lower case letters are mixed in a word compiler first orders the upper case characters than lower case characters. Because copmiler is ordering from ASCII values. I don't know if it is a problem or not.
//
//QuitNow function is working perfect thanks to exit(EXIT_SUCCESS) order
//
//default has added for showing non-valid options but there is an error
//The error is because of case 0
//The error has solved by adding curly bracket after case 0, now default function is working
//I realized that problem is not solved properly because if I enter a letter or symbol it is an endless loop. It just works with numbers
//I changed menu option's variable to char in order to solve the problem,now it works fine 
//
//All necessary comments has added
//
//Unnecessary functions, variables and comments has deleted.
