#pragma once
#include "cards.h"
#include "../general/battle.h"
#include <array>

std::array<int, 2> getAOIsize(int AOIeffect, int id, std::array<int, 2> teamSize);

std::array<int, 2> getTargetTeam(int id, bool target);

void activateCard(int userId, const card *currentCard, cardEffect& currentEffect, int teamId, std::array<int, 2> loopSize, battle& currentBattle);