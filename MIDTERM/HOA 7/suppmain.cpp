#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "suppselectionalgo.h"

const int maxSize = 100;
void displayArr(int arr[]);

int main()
{
    std::srand(std::time(0));
    int unsortedArr[maxSize];

    // random votes
    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = (std::rand() % 5) + 1;
    }
    std::string candidates[5] = {
        "Bo Dalton Capistrano", "Cornelius Raymon Agustin", "Deja Jayla Banaga",
        "Lalla Brielle Yabut", "Franklin Relano Castro"
    };

    std::cout << "Unsorted Array:\n";
    displayArr(unsortedArr);

    // sorting votes using header file
    selectionSort(unsortedArr, maxSize);

    std::cout << "\nSorted Array:\n";
    displayArr(unsortedArr);

    // manual count
    int manualCount[6] = {0};
    for (int i = 0; i < maxSize; i++)
    {
        manualCount[unsortedArr[i]]++;
    }

    // algorithm count
    int voteCount[6] = {0};
    for (int i = 0; i < maxSize; i++)
    {
        int vote = unsortedArr[i];
        if (vote >= 1 && vote <= 5)
        {
            voteCount[vote]++;
        }
    }

    // finding result/winnder
    int winner = 1;
    for (int i = 2; i <= 5; i++) {
        if (voteCount[i] > voteCount[winner]) {
            winner = i;
        }
    }

    // display results
    std::cout << "\nVote Count Results:";

    for (int i = 1; i <= 5; i++) {
        std::cout << "\nCandidate " << i << ": ";
        std::cout << candidates[i - 1] << "\n";

        std::cout << "Manual Count: ";
        std::cout << manualCount[i] << "\n";

        std::cout << "Algorithm Count: ";
        std::cout << voteCount[i] << "\n";
    }

    std::cout << "\nWinning Candidate: Candidate " << winner << "\n";
    std::cout << "Name: " << candidates[winner - 1] << "\n";
    std::cout << "Votes: " << voteCount[winner] << "\n";

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}