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

		[[nodiscard]] virtual EventType GetEventType() const override = 0;
		[[nodiscard]] virtual std::string_view GetName() const override = 0;
		[[nodiscard]] int GetCategoryFlags() const final { return EventCategory::EventCategoryKeyboard | EventCategory::EventCategoryInput; }
		
		[[nodiscard]] int GetKeyCode() const { return _keyCode; }

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
		[[nodiscard]] virtual std::string_view GetName() const override { return "KeyPressedEvent"; };

		[[nodiscard]] int GetRepeatCount() const { return _repeatCount; }
	private:
		int _repeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int KeyCode)
			: KeyEvent{ KeyCode }
		{}

		[[nodiscard]] virtual EventType GetEventType() const override { return EventType::KeyReleased; }
		[[nodiscard]] virtual std::string_view GetName() const override { return "KeyReleasedEvent"; };

	};
}
