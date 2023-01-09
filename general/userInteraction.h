#pragma once
#include <iostream>
#include <vector>

//this code can most likely be shortened. should look into that later

int playerChoiceVector(std::vector<std::string>& choiceList){
    int chosen;
    int listSize = choiceList.size();

    for(int num = 0; num < listSize; num++){
        std::cout << num + 1 << ") " << choiceList[num] << std::endl;
    }

    std::cin >> chosen;

    if(chosen < 0 || chosen >= listSize){
        std::cout << chosen << " is not a valid choice";
        chosen = playerChoiceVector(choiceList);
    }

    return chosen;
}

int playerChoiceArray(std::string (&choiceList)[]){
    int chosen;
    int listSize = choiceList->size();
    int num = 0;

    for(int x = 0; x < listSize; x++){
        if (choiceList[x] != ""){
            std::cout << num + 1 << ") " << choiceList[num] << std::endl;
            num++;
        }
    }

    std::cin >> chosen;

    if(chosen < 0 || chosen >= listSize){
        std::cout << chosen << " is not a valid choice";
        chosen = playerChoiceArray(choiceList);
    }

    return chosen;
}