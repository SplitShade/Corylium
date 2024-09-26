#pragma once

#include "Corylium/Core.h"
#include "Event.h"

namespace Corylium {

	class KeyEvent : public Event
	{
	public:
		KeyEvent(int KeyCode)
			: _keyCode{ KeyCode }
		{}

		[[nodiscard]] int GetCategoryFlags() const final { return EventCategory::EventCategoryKeyboard | EventCategory::EventCategoryInput; }
		[[nodiscard]] int GetKeyCode() const { return _keyCode; }
		[[nodiscard]] virtual EventType GetEventType() const override = 0;

	private:
		int _keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int KeyCode, int RepeatCount)
			: KeyEvent{ KeyCode }, _repeatCount{ RepeatCount }
		{}

		[[nodiscard]] virtual EventType GetEventType() const override { return EventType::KeyPressed; }
		[[nodiscard]] int GetRepeatCount() const { return _repeatCount; }

	private:
		int _repeatCount;
	};
}