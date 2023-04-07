///Domenic Hankle
///CS 150
///April 7, 2022
/*This program calculates student's scores based on an input file.*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

///Function Prototypes
char ExamGrade(int score);
void ReadData(char[], ifstream&, int);

int main()
{
    ///Declare variables.
    int i; //Loop control variable
    int score; //Student exam score.
    int len; //The length of the student's answer.
    char ch; //Store white space.
    int noOfQuestions = 20; //Number of questions.
    char ID[9]; //Array to hold the student ID.

    ///Declare pointer variables.
    char* keyString; //Char pointer for the answer key.
    char* answerString; //Char pointer to the student's answers.

    ///Declare an input variable.
    ifstream inFile;
    inFile.open("input.txt");//Open the input file.

    //Check to see if the file is open.
    if(!inFile)
    {
        cout << "Cannot open input file. Pogram terminated." << endl;
        return 1;
    }

    ///Declare two dynamic arrays.
    keyString = new char[noOfQuestions + 1]; //Dynamic array for the answer key.
    answerString = new char[noOfQuestions + 1]; //Dynamic array for student's answers.


    ///Read the answer key
    cout << "Processing Data..." << endl;
    inFile.get(keyString, noOfQuestions + 1);

    ///Output the answer key
    cout << "Key: " << keyString << endl;

    ///Prepare our output
    cout << left << setw(15) << "Student ID"
         << setw(25) << "Student Answers"
         << setw(10) << "Score"
         << setw(10) << "Grade" << endl;

    ///Read the data for the first student.
    inFile >> ID; //Read the student's ID.
    inFile.get(ch); //Reads white space character.

    ///Read the student's answers.
    inFile.get(answerString, noOfQuestions + 1);

    ///Loop through the rest of the file
    while(inFile)
    {
        ///Read the length of the student's answers.
        len = strlen(answerString);

        ///Clear out any trailing unanswered questions.
        for(i = len; i < noOfQuestions; i++)
        {
            answerString[i] = ' ';
        }
        answerString[noOfQuestions] = '\0'; //Set the last element of the string to null

        ///Calculate the score.

        score = 0; //Set score to 0.

        ///For each character in the student's answers...
        for(i = 0; i < noOfQuestions; i++)
        {
            if(answerString[i] != ' ') //Check if the answer exists.
            {
                if(answerString[i] == keyString[i]) //Check if the answer is equal to the answer key.
                {
                    score += 2; //Add 2 to the score.
                }
                else
                {
                    score--; //Subtract one from the score.
                }
            }
        }

        ///Output the student's answers, score, and grade.
        cout << left << setw(15) << ID
             << setw(25) << answerString
             << setw(10) << score
             << setw(10) << ExamGrade(score) << endl;

        ///Read the data for the next student.
        inFile >> ID;
        inFile.get(ch);
        inFile.get(answerString, noOfQuestions + 1);
    }


    ///Clean up.

    inFile.close(); //Close the input file.
    delete [] keyString; //Deallocate the dynamic array for answer key.
    delete [] answerString; //Deallocate the dynamic array for student's answers
    return 0;
}

///Calculate the letter grade.
char ExamGrade(int score)
{
    switch(static_cast<int>(score / 40.0 * 10))
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return 'F';
        case 6:
            return 'D';
        case 7:
            return 'C';
        case 8:
            return 'B';
        case 9:
        case 10:
            return 'A';
        default:
            return 'F';
    }
}


