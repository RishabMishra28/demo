#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int tries=3;
string message= "you have three chances";//displayed over the jallad

void hang_man(char);
int checkguess(char,string,string&);//returns the number of times the character guessed by the user is present in the answer. &used with third string argument  because we need to udate it again and again

int main(){
    char letter;//to store the letters guessed by the user
    string month;//to store the correct answer month to be guessed by the user
    string months[]={
         "january",
         "february",
         "march",
         "april",
         "may",
         "june",
         "july",
         "august",
         "september",
         "october",
         "november",
         "december"
    };

srand(time(NULL));//to generate a newe random number each time
int month_number=rand()%12;//generates random number between 0 and 11 which denotes the index of the month present in the array
month =months[month_number];

string hide_month(month.length(),'X');//'X' PLACED IN THE length of the month string which is the answer and needs to be hidden
        
system("cls");//to clear the screen

while (tries!=0)
{
    hang_man('n');
    cout<<"\t\t\t\tLife: "<< tries <<endl;
    cout<<"\t\t\t\t"<<hide_month <<endl;
    cout<<"\t\t\t\tGuess a letter: ";
    cin>> letter;

    system("cls");//because everytime we have to draw new screen

    if (checkguess(letter,month,hide_month) ==0)//in this case if condition will hold true if the char guessed by the user is not present in the answer
    {
        message="incorrect letter!";//mesage displayed over the jallad
        tries--;
    }
    
    else//if checkguess returns something
    {
        message="Nice! Correct Guess ";
    }

    if (hide_month==month)//if player correctly guesses the month
    {
        message="you're free ";
        hang_man('f');//to udate the state of the game from neutral('n) to free
        cout<<"\t\t\t\tLife: "<< tries <<endl;
        cout<<"\t\t\t\tThe month is: "<<month<<endl;
        break;//as player wins the game 
    }
    
    if (tries==0)
    {
        message="you're hanged";
        hang_man('h');//h for hanged failure state
        cout<<"\t\t\t\tLife: "<< tries <<endl;
        cout<<"\t\t\t\tThe month is: "<<month<<endl;
    }
    

    
}

    


return 0;
}

int checkguess(char guess,string real_month,string  &hidden_month){
    int matches=0;
    int len=real_month.length();
    for (int i = 0; i < len; i++)
    {
        if (guess == hidden_month[i])//if the user guesses a wrong guess of a letter already guessed before which was correct as it was present only once in the real month name
        {
            return 0;
        }
        if (guess == real_month[i])//if it is a correct guess
        {
            hidden_month[i]=guess;
            matches++;
        }   
    }
    return matches;
}
void hang_man(char state){

string head_string="|";
string stage = "=";


if (state =='f')
{
    head_string=" ";
}
else if(state =='h'){
    stage = " ";
}

cout << "\t\t\t\t________________________________" <<endl;
cout << "\t\t\t\t                " <<head_string<<"             |" <<endl;
cout << "\t\t\t\t                O              |" <<endl;  
cout << "\t\t\t\t               / \\            | " << "\t    "<< message <<endl;
cout << "\t\t\t\t                |              | " << "\t   /"<<endl; 
cout << "\t\t\t\t               / \\            |            O "<<endl;
cout << "\t\t\t\t           ==="<<stage<<stage<<stage<<stage<<stage<<"=====       |          / \\"<<endl; 
cout << "\t\t\t\t           |           |       |           |"<<endl;            
cout << "\t\t\t\t           |           |       |          / \\"<<endl; 
cout << "\t\t\t\t=========================================================="<<endl;
}





