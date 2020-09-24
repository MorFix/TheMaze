#include "UserPlayer.h"
#include "NoStepMove.h"

Move* UserPlayer::askForMove() {
	return new NoStepMove;
}
