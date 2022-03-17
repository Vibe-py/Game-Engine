#pragma once

#include "Event.h"

#include <sstream>

namespace Pretzel
{
	
	class PRETZEL_API MouseEventMoved : public Event
	{
	public:
		MouseEventMoved(float x, float y)
			:x(x), y(y) {}

		inline float getX() const { return x; }
		inline float getY() const { return y; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "Mouse Event Moved " << "(X: " << getX() << "Y: " << getY() << ")\n";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float x, y;
	};

	class PRETZEL_API MouseEventScrolled : public Event
	{
	public:
		MouseEventScrolled(float xOffset, float yOffset)
			:xOffset(xOffset), yOffset(yOffset) {}

		inline float getXOffset() const { return xOffset; }
		inline float getYOffset() const { return yOffset; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "Mouse Event Scrolled " << '(' << getXOffset() << ',' << getYOffset() << ")\n";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float xOffset, yOffset;
	};

	class PRETZEL_API MouseButtonEvent : public Event
	{
	public:
		inline int getMouseButton() const { return button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		MouseButtonEvent(int button)
			:button(button) {}

		int button;
	};

	class PRETZEL_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Pressed : " << button << "\n";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MousePressed)
	};

	class PRETZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Released : " << button << "\n";
			return ss.str();
		}

		EVEMT_CLASS_TYPE(MouseReleased)
	};
}