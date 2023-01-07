#pragma once
#include <iostream>
#include <vector>

int playerChoice(std::vector<std::string>& choiceList){
    int chosen;
    int listSize = choiceList.size();

    for(int num = 0; num < listSize; num++){
        std::cout << num + 1 << ") " << choiceList[num] << std::endl;
    }

    std::cin >> chosen;

    if(chosen > 0 && chosen <= listSize){
        return chosen;
    }

    std::cout << chosen << " is not a valid choice";
    playerChoice(choiceList);
}