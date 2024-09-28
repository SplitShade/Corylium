#pragma once
#include "Corylium/Core.h"
#include "Event.h"

namespace Corylium {

	class CORYLIUM_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: _width(width), _height(height)
		{}

		unsigned int GetWidth() const { return _width; }
		unsigned int GetHeight() const { return _height; }

		[[nodiscard]] virtual EventType GetEventType() const override { return EventType::WindowResize; }
		[[nodiscard]] virtual std::string_view GetName() const override { return "WindowResizeEvent"; }
		[[nodiscard]] virtual int GetCategoryFlags() const override { return EventCategory::EventCategoryApplication; }
	private:
		unsigned int _width;
		unsigned int _height;
	};
}
