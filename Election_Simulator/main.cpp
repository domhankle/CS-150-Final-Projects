///Domenic Hankle
///CS 150
///UIN: 01202552
///April 7, 2022
/*This program calculates the winner of an election based on user input.*/

#include <iostream>
#include <string>
#include <iomanip>
//Include the header files <string> and <iomanip>

using namespace std;

///Function Prototypes
float CalculatePercentage(int, int);
int CalculateWinner(int[], int);

int main()
{
    ///Declare variables
    int numCandidates = 0;//Number of candidates.
    int totalVotes = 0;//Total votes.

    ///Declare pointer variables
    string* candidateNames = NULL;
    int* candidateVotes = NULL;

    ///Prompt the user to enter the number of candidates.
    cout << "Please enter the number of candidates: ";
    cin >> numCandidates;//Store the value in numCandidates.


    ///Initialize pointer variables.
    candidateNames = new string[numCandidates]; //Dynamic array for candidate names.
    candidateVotes = new int[numCandidates]; //Dynamic array for votes per candidate.

    ///Initialize each candidate name and votes in the arrays.
    for(int i = 0; i < numCandidates; i++)
    {
        cout << "Enter the candidates name and number of votes: ";
        cin >> candidateNames[i] >> candidateVotes[i]; //Prompt the user to enter votes and candidate names. Store them in respective variables.
        totalVotes += candidateVotes[i];// Add to totalVotes every iteration.
    }

    ///Congfigure output and set up header.
    cout << left << endl
         << setw(15) << "Candidate"
         << setw(20) << "Votes Received"
         << setw(20) << "% of Total Votes" << endl;

    cout << fixed << showpoint << setprecision(2);//Configuring decimal place formatting

    ///Output Information for each candidate.
    for(int i = 0; i < numCandidates; i++)
    {
        cout << left
             << setw(15) << candidateNames[i]
             << setw(20) << candidateVotes[i]
             << setw(20) << CalculatePercentage(candidateVotes[i], totalVotes) << endl; //Calculates the percentage of vote each candidate earned.
    }
    cout << "Total Votes: " << totalVotes << endl; //Output total votes of the election.

    ///Output the winner of the election
    cout << "The winner of the election is " << candidateNames[CalculateWinner(candidateVotes, numCandidates)] << endl;


    ///Clean up

    //Deallocate memory for both of the dynamic arrays.
    delete [] candidateNames;
    delete [] candidateVotes;


    return 0;
}

int CalculateWinner(int candidateVotes[], int numCandidates)
{
    int winnerInd = 0;//Declare a local variable

    ///Loop through the array and determine the element in the array with the highest vote count.
    for(int i = 1; i < numCandidates; i++)
    {
        if(candidateVotes[i] > candidateVotes[winnerInd])//If current element is higher than current winningIndex element.
        {
            winnerInd = i; //Initialize winnerInd to i.
        }
    }

    ///Return the winning index value.
    return winnerInd;
}

float CalculatePercentage(int voteCount, int totalVotes)
{
    ///Calculate the vote percentage of a specific candidate.
    return static_cast<float>(voteCount) / totalVotes * 100;
}
