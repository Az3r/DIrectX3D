#pragma once
#include <vector>
#include <queue>
#include <bitset>

// forward declaration
class Keyboard;
class KeyState;


class KeyEventArgs
{
	friend Keyboard;
private:
	KeyState mState;
	unsigned char mKeyCode;

public:
	KeyEventArgs(KeyState state, unsigned char key) noexcept : mState(state), mKeyCode(key) {}
	KeyEventArgs() noexcept : mState(), mKeyCode(0u) {}

	inline const KeyState& GetState() const noexcept { return mState; }
	inline unsigned char GetKeyCode() const noexcept { return mKeyCode; }
};

class KeyState
{
private:
	std::bitset<3> mStates;
public:
	KeyState(std::bitset<3> states) noexcept : mStates(states) {}
	KeyState() noexcept : mStates("000") {}

	inline bool IsDown() const noexcept { return mStates.test(0); }
	inline bool IsPressed() const noexcept { return mStates.test(1); }
	inline bool IsReleased() const noexcept { return mStates.test(2); }

	inline void SetDown() noexcept { mStates = std::bitset<3>("100"); }
	inline void SetPressed() noexcept { mStates = std::bitset<3>("010"); }
	inline void SetDownAndPressed()  noexcept { mStates = std::bitset<3>("110"); }
	inline void SetReleased() noexcept { mStates = std::bitset<3>("001"); }
};

class Keyboard
{
private:
	std::vector<KeyState> mKeys;
	std::queue<KeyEventArgs> mEventBuffer;

public:
	Keyboard() : mKeys(256) {}

	// clear preivous state and start reading events in the event buffer
	int ReadKeys() noexcept;

	// clear events in buffer
	void ClearBuffer() noexcept;

	// clear keyboard state
	void Reset() noexcept;

	// add new event into buffer
	void OnKeyEvent(KeyEventArgs args);
	
	const KeyState& GetState(unsigned char key) const;
	KeyState& GetState(unsigned char key);
	inline bool IsKeyDown(unsigned char key) const { return this->GetState(key).IsDown(); }
	inline bool IsKeyPressed(unsigned char key) const { return this->GetState(key).IsPressed(); }
	inline bool IsKeyReleased(unsigned char key) const { return this->GetState(key).IsReleased(); }
};

