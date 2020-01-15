#pragma once
#include <vector>
#include <queue>

enum class KeyEventTypes { Pressed, Down, Released, None };

class KeyEventArgs
{
private:
	KeyEventTypes mType;
	unsigned char mKeyCode;

public:
	KeyEventArgs(KeyEventTypes type, unsigned char key) noexcept : mType(type), mKeyCode(key) {}
	KeyEventArgs() noexcept : mType(KeyEventTypes::None), mKeyCode(0u) {}
	~KeyEventArgs() noexcept {}

	inline KeyEventTypes GetType() const noexcept { return mType; }
	inline unsigned char GetKeyCode() const noexcept { return mKeyCode; }
	inline bool IsDown() const noexcept { return mType == KeyEventTypes::Down; }
	inline bool IsPressed() const noexcept { return mType == KeyEventTypes::Pressed; }
	inline bool IsReleased() const noexcept { return mType == KeyEventTypes::Released; }
};



class Keyboard
{
private:
	std::vector<KeyEventTypes> mKeys;
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
	
	const KeyEventTypes& GetKeyState(unsigned char key) const;
	inline bool IsKeyDown(unsigned char key) const { return this->GetKeyState(key) == KeyEventTypes::Down; }
	inline bool IsKeyPressed(unsigned char key) const { return this->GetKeyState(key) == KeyEventTypes::Pressed; }
	inline bool IsKeyReleased(unsigned char key) const { return this->GetKeyState(key) == KeyEventTypes::Released; }
};

