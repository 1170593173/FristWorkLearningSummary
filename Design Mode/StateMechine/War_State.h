#pragma once
class War;
class State
{
public:
	virtual void CurrentState(War *war) {}
	//virtual void Prophase() {}
	//virtual void Metaphase() {}
	//virtual void Anaphase() {}
	//virtual void End() {}
};
//战争
class War
{
private:
	State *m_state;  //目前状态
	int m_days;      //战争持续时间
public:
	War(State *state) : m_state(state), m_days(0) {}

	~War() { 
		delete m_state; 
	}
	int GetDays() { 
		return m_days; 
	}
	void SetDays(int days) { 
		m_days = days;
	}
	void SetState(State *state) { 
		delete m_state; 
		m_state = state; 
	}
	void GetState() { 
		m_state->CurrentState(this); 
	}
};