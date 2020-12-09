#pragma once
#include "Core.h"
#include "GameObject.h"
#include "InputEvent.h"

namespace India
{
	class India_EXPORT GuiObject : public Object {
	public:
		GuiObject() noexcept;
		GuiObject(int x, int y, int width, int height, const Color& color = { 0,0,0 }) noexcept;
		GuiObject(int x, int y, int width, int height, const std::string& image_path) noexcept;

		/**
		 Adds an event handler to the GUI Object. The callback will be called when the specified event occurs.
		 Available events: click, mouse_enter, mouse_leave
		*/
		void AddEventHandler(const std::string& event, const std::function<void(InputEvent&)>& callback) noexcept;

		/**
		 Notifies the event handlers which are listening to the event that is passed.
		*/
		void Notify(const std::string& event, InputEvent& evt) noexcept;

		virtual void DrawComponent(const Graphics2D& g) const noexcept override;
		virtual void Draw(const Graphics2D& g) const override;

		virtual ~GuiObject() = 0;
	private:
		std::unordered_map<std::string, std::vector<std::function<void(InputEvent&)>>> _event_handlers;
	};

}
