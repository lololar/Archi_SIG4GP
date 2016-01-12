#include "PlayerState.h"

StatePlayer PlayerState::GetState() {
    return _state;
}

PlayerState::PlayerState()
{
	_state = Normal;
}

PlayerState::~PlayerState()
{
}

void PlayerState::SetState(StatePlayer playerState) {

	_state = playerState;

}