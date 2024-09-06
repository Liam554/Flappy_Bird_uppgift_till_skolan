#include "StateMachine.hpp"

namespace Liam
{
	// Adds a new state to the state machine.
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;

		this->_newState = std::move(newState);
	}
	// Marks the current state for removal.
	void StateMachine::RemoveState()
	{
		this->_isRemoving = true;
	}

	// Processes changes to the state stack (adding/removing states).
	void StateMachine::ProcessStateChanges()
	{
		if (this->_isRemoving && !this->_states.empty())
		{
			this->_states.pop();

			if (!this->_states.empty())
			{
				this->_states.top()->Resume();
			}

			this->_isRemoving = false;
		}
	        // Check if a new state needs to be added.
		if (this->_isAdding)
		{
			if (!this->_states.empty())
			{
				if (this->_isReplacing)
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->Pause();
				}
				
			}

			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			this->_isAdding = false;

		}
	}
	// Returns a reference to the currently active state.
	StateRef& StateMachine::GetActiveState()
	{
		return this->_states.top();
	}
}

