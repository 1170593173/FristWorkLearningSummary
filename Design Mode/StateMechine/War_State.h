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
//ս��
class War
{
private:
	State *m_state;  //Ŀǰ״̬
	int m_days;      //ս������ʱ��
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