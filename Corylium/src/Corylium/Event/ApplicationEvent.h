#pragma once
#include "Corylium/Core.h"
#include "Event.h"

namespace Corylium {

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int Width, unsigned int Height)
			: _width(Width), _height(Height)
		{}

		[[nodiscard]] virtual EventType GetEventType() const override { return EventType::WindowResize; }
		[[nodiscard]] virtual std::string_view GetName() const override { return "WindowResizeEvent"; }
		[[nodiscard]] virtual int GetCategoryFlags() const override { return EventCategory::EventCategoryApplication; }

		unsigned int GetWidth() const { return _width; }
		unsigned int GetHeight() const { return _height; }
	
	private:
		unsigned int _width;
		unsigned int _height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent()
		{}

		[[nodiscard]] virtual EventType GetEventType() const override { return EventType::WindowClose; }
		[[nodiscard]] virtual std::string_view GetName() const override { return "WindowCloseEvent"; }
		[[nodiscard]] virtual int GetCategoryFlags() const override { return EventCategory::EventCategoryApplication; }
	
	};
}
