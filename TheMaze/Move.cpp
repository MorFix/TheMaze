#include "Move.h"
#include "Player.h"

void Move::increasePlayerMoves(Player* player)
{
	player->setNumberOfMoves(player->getNumberOfMoves() + 1);
}
