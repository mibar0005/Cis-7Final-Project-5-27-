/*Encryption Program Final Project
Software Developers: Lissette Serrato, Issac Martinez, 
Jared Napalan and Miguel Ibarra.
06/09/2020
*/

#include <iostream>
#include <string>
using namespace std;

//Function Prototypes
int showMenu();
string encrypt (string, int);
string decrypt(string, int);
void vigenereTable();

//Start of the program 
int main() {

  int CHOICE;               //Stores the users Menu choice 
  string message;           //Message to be enccypted 
  int shift;                //Number of unit to be shifted 
  string encryptMessage;    //Message to be decrypted 
  char again;               //Stores the input if user wants 
                            //to run the program again.

  //calls lthe function showMenu, this function
  //displays a menu that gives the user choices 
  //to encrypt a message, decrypt a message, 
  //display a Vigenere Table or Quit the program.
  //The function the returns the user's choice.
  //The program then branche to the appropiate 
  //user selection.
  LOOP: do {
  CHOICE  = showMenu();     

  //First choice is to Encrypt a message
  //This choice asks the user to enter a string
  //with no spaces, no special characters, and
  //no numbers. This string is then passed into 
  //a function where it is encrypted and returned
  //The encrypted message is the displayed to the user.
  if (CHOICE == 1)
  {
    //Display a welcome message.
    cout << "\n1. Encrypt Message. \n\n" <<
    "Welcome to Encrypto!\nPlease enter the message you wish to encrypt. \n" << 
    "The message must be entered as a single string with no spaces," << 
    "special chatacters, or numbers.\n\n";
    //Promt the user for a message.
    cout << "Please enter your message: "; 
    cin >> message;
    //This will shift each character in the string
    //by the number entered by the user. 
    cout << "\nEnter the shift number for your message: ";
    cin >> shift; 
    //Call the function encrypt message
    //pass the message and the shift as parameters
    //This function return a string that has been 
    //shifted by the variable shift. 
    cout << "\nYour encrypted Message is: " << encrypt(message, shift);
    
  }

  //CHOICE 2 is used to decrypt a message
  //The user should know the message that they want to 
  //decrypt, followed by the shift number.
  else if (CHOICE == 2)
  {
    //Display a welcome message.
    cout << "\n2. Decrypt a Message.\n";
    cout << "\nWelcome to Decrypto!\nPlease enter the message"
    << " you wish to Decrypt, followed by the\nshift number. ";
    cout << "The message should be a single string with\nno spaces, no special characters, or numbers.\n\n";
    //prompt the user to enter an encrypted message.
    cout << "Enter the Encrypted message: ";
    cin >> encryptMessage;
    //ask the user the shift number 
    //remember that decryption shifts character 
    //place to the right. 
    cout << "\nPlease the shift number: ";
    cin >> shift; 
    //call the function decrypt and pass the parameters 
    //encryptMessage, and shift.
    cout << "\nDecrypted Message: " << decrypt(encryptMessage, shift) << endl << endl;

  }

  else if (CHOICE == 3)
  {
    //call the function to display a Vigenere Table 
    vigenereTable();
  }

  //If the user's choice is 4
  //We display a good-bye message 
  //and we exit the program. Notice that for this 
  //we used the exit function. 
  else if (CHOICE == 4)
  {
    cout << "\n4. Quit Program. \n";
    cout << "Good-Bye";
    exit(0);
  } 
  //This trailing else serves to catch Invalid entries.
  else
  {
    cout << "Invalid Entry! \n";
    cout << "Please enter a valid Menu Entry";
    cout << endl << endl;
  }
  } while (CHOICE <= 0 || CHOICE >=5);

cout << "\n\nRun the Program again? \n";
cout << "If yes, press 'y' or 'Y, if not, press 'N' or 'n': ";
cin >> again;
cout << endl << endl;
if (again == 'Y' || again =='y')
{
  //We use this label goto in order to restart the program
  //in case the user wants to run the program again.
  goto LOOP;
}
if (again == 'N' || again == 'n')
{
  cout << "\nQuitting the program!\n";
  cout << "Good-Bye!";
}

return 0;
}


//This function displays a menu table
//The user enters a menu option and this 
//is returned to the main function, where
//it is evaluated with each if/else if statement.
int showMenu()
{
  int choice;
  cout << "***************************************\n" << 
  "Welcome to MyEncyption!             ***\n" <<
  "                                    ***\n" <<
  "Menu Options:                       ***\n" << 
  "1. Encrypt a Message.               ***\n" <<
  "2. Decrypt a Message.               ***\n" <<
  "3. Display Vigenere Table.          ***\n" <<
  "4. Quit Program.                    ***\n"; 
  cout << "***************************************\n\n";

  cout << "Please enter your choice: ";
  cin >> choice; 

  return choice;
 
}


//This function encrypts a message entered by the user
//This function shifts the number of letters the 
//right by the variable shift (number of units entered 
//by the user). This function the returns the string
//with the correct amount of units shifted to the right.
string encrypt(string message, int shift)
{
  string encryption = "";

  for (int i = 0; i < message.length(); i++)
  {
    //encrypt capital letters
    if (isupper(message[i]))
      encryption += char(int(message[i] + shift - 65)%26 + 65);

      //encrypt to lowercase 
    else 
        encryption += char(int(message[i] + shift - 97)% 26 + 97);
  }

    return encryption; 
}

//This function decrypts a message. This function 
//takes a message and shifts it to the left by 
//the value of the variable shift (entered by the user).
//The function then returns the string with a 
//decrypted message.
string decrypt(string encryptMessage, int shift)
{

  string decryption = "";
  for (int i = 0; i < encryptMessage.length(); i++)
  {
    //encrypt capital letters
    if (isupper(encryptMessage[i]))
      decryption += char(int(encryptMessage[i] - shift - 65)%26 + 65);

      //encrypt to lowercase 
    else 
        decryption += char(int(encryptMessage[i] - shift - 97)% 26 + 97);
  }
  return decryption; 
}

//This function displays a Vigenere Table to the user
//This table can be used if the user would like to
//encrypt or decrypt a message by hand using a table.
void vigenereTable ()
{
  cout << "\n3. Display the Vigenere Table. \n\n";
  cout << "Below is the Vigenere Table: \n\n";
 int alpha[26][26];
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<26; j++)
        {
            alpha[i][j]=(i+j)+65;
            if(alpha[i][j]>=91)
            {
                alpha[i][j]-=26;
            }
            cout<<(char) alpha[i][j];
        }
        cout<<endl;
    }
}
     