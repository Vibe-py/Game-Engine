#pragma once

#include "Event.h"

#include <sstream>

namespace Pretzel
{
	class PRETZEL_API KeyEvent : public Event
	{
	public:
		inline int getKeyCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keyCode)
			:keyCode(keyCode) {}

		int keyCode;
	};

	class PRETZEL_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			:KeyEvent(keyCode), repeatCount(repeatCount) {}
		
		inline int getRepeatCount() const { return repeatCount; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "Key Pressed Event : " << keyCode << ',' << repeatCount << "\n";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);
	private:
		int repeatCount;
	};

	class PRETZEL_API KeyReleasedEvent : public Event
	{
		KeyReleasedEvent(int keyCode)
			:KeyEvent(keyCode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "Key Released Event : " << keyCode << "\n";
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}