#pragma once

#include "ObjectManager.h"
#include "System.h"
#include "GuiObject.h"
#include "Graphics2D.h"
#include "InputFacade.h"
#include "DrawingFacade.h"

namespace India {
	class SceneSystem : public System {
	public:
		SceneSystem(DrawingFacade& drawing_facade, const InputFacade& input_facade) noexcept;
		~SceneSystem();
		/**
		Updates drawable objects on the window.
		*/
		void Update(UpdateParameters& params) noexcept override;
	private:
		InputEvent _last_input_event;
		DrawingFacade& _drawing_facade;
		const InputFacade& _input_facade;
		std::vector<std::reference_wrapper<GuiObject>> _hovered_objects;

		/**
		 Handles the window events. Currently supports, mouse motion and mouse button presses.
		*/
		void HandleEvents(std::vector<std::reference_wrapper<GuiObject>> gui_objects) noexcept;
	};
}