#pragma once

#include "Corylium/Core.h"

namespace Corylium {

	//Events are currently blocking, TODO buffered events

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = Bit(0),
		EventCategoryInput		 = Bit(1),
		EventCategoryKeyboard	 = Bit(2),
		EventCategoryMouse		 = Bit(3),
		EventCategoryMouseButton = Bit(4)
	};

	class Event
	{

	public:
		[[nodiscard]] virtual EventType GetEventType() const = 0;
		[[nodiscard]] virtual std::string_view GetName() const = 0;
		[[nodiscard]] virtual int GetCategoryFlags() const = 0;

		/// @brief Checks if an Event is in the specified category
		/// @param category 
		/// @return true or false
		bool IsInCategory(EventCategory category) const { return GetCategoryFlags() & category; }
		bool IsHandled() const { return _isHandled; }

	private:
		bool _isHandled = false;

	};

	class EventDispatcher
	{
	public:

	};
}
