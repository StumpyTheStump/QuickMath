#include "StateMachine.h"



StateMachine::StateMachine()
{
	currentState = nullptr;
	prevState = nullptr;
}

void StateMachine::update(Agent * agent, float deltaTime)
{
	if (currentState != nullptr)
		currentState->update(agent, this, deltaTime);
}

void StateMachine::ChangeState(Agent * agent, State * newState)
{
	// If the current is not a null pointer
	// Destroy the objects in the current state by calling the exit function
	if (currentState != nullptr)
		currentState->exit(agent);

	// Initialise the game objects of the new state by calling hte Inititalise fucntion
	if (newState != nullptr)
		newState->initialise(agent);

	// Store currentState into the prevState
	prevState = currentState;
	currentState = newState;
}

State * StateMachine::GetCurrentState()
{
	return currentState;
}

State * StateMachine::GetPrevState()
{
	return prevState;
}


StateMachine::~StateMachine()
{
	delete currentState;
	delete prevState;
}
