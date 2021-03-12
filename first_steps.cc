//Michael Erwin

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>

void fizzbuzz();                            //declaration
void palindrome(std::string palCheck);      //declaration
void egg();                                 //declaration

int main(int argc, const char* argv[])
{
    fizzbuzz();                             //method call
    std::string input = "";                 //blank string to be used for user input
    std::cout << "Enter string for palindrome check: ";
                                            //user prompt
    std::getline(std::cin, input);          //get user input and put into input string; use getline so that it doesn't
                                            //stop at whitespace.

    palindrome(input);                      //method call passing input string

    egg();                                  //method call

    std::cout << std::endl;                 //newline
    return 0;
}

void fizzbuzz()
{
    std::string fizz     = "Fizz";
    std::string buzz     = "Buzz";
    std::string fizzbuzz = "FizzBuzz";


    for(int i = 1; i <= 100; i++)
    {
        if(i%5 == 0 && i%3 == 0 && i != 100)        //if remainder when divided by 5 and 3 is 0 and i isn't 100 print
                                                    //fizzbuzz
        {
            std::cout << fizzbuzz << ", ";
        }
        else if(i%3 == 0 && i != 100)               //else if remainder when divided by 3 is 0 and i isn't 100 print
                                                    //fizz
        {
            std::cout << fizz << ", ";
        }
        else if(i%5 == 0 && i != 100)               //else if remainder when divided by 5 is 0 and i isn't 100 print
                                                    //buzz
        {
            std::cout << buzz << ", ";
        }
        else if(i==100)                             //else if i is 100 print buzz (without ", ") and add some newlines
        {
            std::cout << buzz << std::endl << std::endl << std::endl;
        }
        else                                        //else print the number
        {
            std::cout << i << ", ";
        }
    }
}


void palindrome(std::string palCheck)
{
    int length = strlen(palCheck.c_str());              //use c_str() to get a null-terminated char array from
                                                        //the string and use strlen() to get the length

    const char* beg = &(palCheck.c_str())[0];           //character pointer to first char in string
    const char* end = &(palCheck.c_str())[length - 1];  //character pointer to last char in string


    int i = 0;                                          //i will be used to count left index of the string
    int j = length-1;                                   //j will be used to count the right index of the string

    while(i <= j)                                       //while left index is <= to right index
    {
        while(!isalpha(beg[i]))                         //while left index isn't alphabetical
        {
            i++;                                        //increase index
        }
        while(!isalpha(end[0]))                         //while right index (first value of end pointer)
                                                        //isn't alphabetical
        {
            end = end - 1;                              //move the end pointer position one to the left
            j--;                                        //reduce right index
        }

        if(toupper(beg[i]) != toupper(end[0]))          //convert to upper to ignore case and see if they aren't equal
        {
            std::cout << std::endl << "Not a palindrome :(" << std::endl << std::endl;
                                                        //if not equal it's not a palindrome
            return;                                     //return to main method
        }
        i++;                                            //increment left index
        j--;                                            //decrement right index
        end = end - 1;                                  //decrement end pointer by one char
    }

    std::cout << std::endl << "Palindrome! :)" << std::endl << std::endl;
                                                        //if it makes it this far, it's a palindrome!
    return;                                             //return to main method 
}

void egg()
{
    srand(time(NULL));                                  //from: https://www.cplusplus.com/reference/cstdlib/rand/

    int ran = rand() % 100 + 1;                         //create random number between 1-100

    //I used this website as a guide:
    //https://www.datagenetics.com/blog/july22012/index.html
    //Specifically, the "Two egg solution" section

    int counter = 0;                                    //counter counts how many attempts to find the critical
                                                        //floor have been made

    int check = 14;                                     //The first floor checked is 14, will explain further down

    int check2 = 0;                                     //This is used for the linear search after the interval
                                                        //containing the critical floor is found

    bool broken = false;                                //when the egg breaks this will be set to true

    int i = 0;                                          //this is used to determine the change in which floor to
                                                        //check. The first floor checked is 14, then 27 (+13), then 39,
                                                        //(+12) and so on. Each time one less than the previous amount
                                                        //of floors is added to check. This is called
                                                        //"Minimization of Maximum Regret"

    while(!broken)                                      //loops until egg breaks
    {
        counter++;                                      //increase drop counter
        if(check >= ran)                                //if floor being checked is >= critical floor
        {
            broken = true;                              //then egg breaks
        }
        else
        {
            check = check + (13 - i);                   //otherwise adjust check value
            i++;                                        //increase i value for determining check
        }
    }

    if(check - 1 < ran)                                 //To see if one floor below would not break the egg
    {
        std::cout << "Random floor chosen: "<< ran << std::endl;
        std::cout << "Critical floor determined from algorithm: "<< check << std::endl;
        std::cout << "Times dropped: "<< counter << std::endl;
        return;
    }

    i--;                                                //Otherwise, the interval has been found. decrease i by one to
                                                        //determine proper check2 amount.

    check2 = check - (13 - i);                          //check2 is used for the linear search. after finding the
                                                        //proper interval, return to the previous interval floor + 1
                                                        //example 50 -> 39 + 1 = 40. Then go up linearly until
                                                        //critical floor is found

    for(check2; check2 <= 100; check2++)                //use check2 as our counter and go until possibly 100
    {
        counter++;                                      //increase drop attempt counter
        if(check2 == ran)                               //if found match
        {
            std::cout << "Random floor chosen: "<< ran << std::endl;
            std::cout << "Critical floor determined from algorithm: "<< check2 << std::endl;
            std::cout << "Times dropped: "<< counter << std::endl;
            break;                                      //break out of loop
        }
    }
    return;
}




