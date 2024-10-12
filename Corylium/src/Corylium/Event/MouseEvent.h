#pragma once

#include "Corylium/Core.h"
#include "Event.h"

namespace Corylium {

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float MouseX, float MouseY)
			: _mouseX { MouseX }, _mouseY { MouseY }
		{}

		[[nodiscard]] virtual EventType GetEventType() const override { return EventType::MouseMoved; }
		[[nodiscard]] virtual std::string_view GetName() const override { return "MouseMovedEvent"; }
		[[nodiscard]] virtual int GetCategoryFlags() const override { return EventCategory::EventCategoryInput | EventCategory::EventCategoryMouse; }
		
		[[nodiscard]] virtual int GetX() const { return _mouseX; }
		[[nodiscard]] virtual int GetY() const { return _mouseY; }
	private:
		float _mouseX, _mouseY;
	};

	class MouseButtonEvent : public Event
	{
		[[nodiscard]] virtual EventType GetEventType() const override = 0;
		[[nodiscard]] virtual std::string_view GetName() const override = 0;
		[[nodiscard]] virtual int GetCategoryFlags() const override { return EventCategory::EventCategoryInput | EventCategory::EventCategoryMouse | EventCategory::EventCategoryMouseButton; }
	
		[[nodiscard]] int GetButton() const { return _button; }
	protected:
		MouseButtonEvent(int Button)
			: _button {Button}
		{}
	private:
		int _button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
		[[nodiscard]] virtual EventType GetEventType() const override { return EventType::MouseButtonPressed; }
		[[nodiscard]] virtual std::string_view GetName() const override { return "MouseButtonPressedEvent"; }
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
		[[nodiscard]] virtual EventType GetEventType() const override { return EventType::MouseButtonReleased; }
		[[nodiscard]] virtual std::string_view GetName() const override { return "MouseButtonReleasedEvent"; }
	};

	class MouseScrolledEvent : public Event
	{
		MouseScrolledEvent(float VerticalOffset, float HorizontalOffset)
			: _verticalOffset { VerticalOffset }, _horizontalOffset{ HorizontalOffset }
		{}

		[[nodiscard]] virtual EventType GetEventType() const override { return EventType::MouseScrolled; }
		[[nodiscard]] virtual std::string_view GetName() const override { return "MouseScrolledEvent"; }
		[[nodiscard]] virtual int GetCategoryFlags() const override { return EventCategory::EventCategoryInput | EventCategory::EventCategoryMouse; }

		[[nodiscard]] float GetVerticalOffset() const { return _verticalOffset; }
		[[nodiscard]] float GetHorizontalOffset() const { return _horizontalOffset; }

	private:
		float _verticalOffset;
		float _horizontalOffset;
	};
}
