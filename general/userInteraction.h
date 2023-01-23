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

int entityChoiceList(battle& battleInstance, int start, int end, int displayMode){
    int chosen = 0;
    int num = 0;
    std::vector<int> entityPositions = {};

    for(int x = start; x < end; x++){
        std::string currentName = battleInstance.entityNames[x];
        if (currentName != ""){
            switch (displayMode){
                case 0:
                    if (battleInstance.combatants[x]->getHealth() <= 0) continue;
                    break;
                case 1:
                    if (battleInstance.combatants[x]->getHealth() > 0) continue;
                    break;
                case 2:
                    break;
                default:
                    throw std::invalid_argument("displayMode of " + std::to_string(displayMode) + " is not possible");
            }
            std::cout << num + 1 << ") " << currentName << std::endl;
            entityPositions.push_back(x);
            num++;
        }
    }

    std::cin >> chosen;
    chosen -= 1;

    if(chosen < 0 || chosen >= num){
        std::cout << chosen << " is not a valid choice";
        chosen = entityChoiceList(battleInstance, end, start, displayMode);
    }

    return entityPositions[chosen];
}