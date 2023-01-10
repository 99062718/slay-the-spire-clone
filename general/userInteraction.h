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
    chosen -= 1;

    if(chosen < 0 || chosen >= listSize){
        std::cout << chosen << " is not a valid choice";
        chosen = playerChoiceVector(choiceList);
    }

    return chosen;
}

int playerChoiceArray(std::string choiceList[], int listSize, int startPoint){
    int chosen;
    int num = 0;

    for(int x = startPoint; x < listSize; x++){
        if (choiceList[x] != ""){
            std::cout << num + 1 << ") " << choiceList[x] << std::endl;
            num++;
        }
    }

    std::cin >> chosen;
    chosen -= 1;

    if(chosen < 0 || chosen >= listSize){
        std::cout << chosen << " is not a valid choice";
        chosen = playerChoiceArray(choiceList, listSize, startPoint);
    }

    return chosen;
}