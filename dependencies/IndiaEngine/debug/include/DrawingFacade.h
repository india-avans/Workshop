#pragma once
#include "Color.h"
#include "Shapes.h"
#include "Utilities.h"
#include "Text.h"
#include "Sprite.h"
#include <string>
#include <map>
#include <memory>

namespace India {

	struct Scale {
		float x, y;
	};

	class DrawingFacade {
	private:
		struct impl;
		std::unique_ptr<impl> pimpl;
	public:
		DrawingFacade(const std::string& title, int window_width, int window_height, bool is_fullscreen = false) noexcept;
		~DrawingFacade();

		/**
		 Converts a rectangle to the right scale.
		*/
		Rectangle GetScaledRectangle(const Rectangle& original, RenderType render_type) noexcept;

		/**
		 Fills a rectangle on the window.
		*/
		void DrawRect(const Rectangle& rect, bool should_fill, const Color& color = { 0,0,0 }) noexcept;

		/**
		 Draws and caches blended text. This is useful for text that does not change often.
		*/
		void DrawText(const Text& text, const Rectangle& rect, const Color& color = { 0,0,0 }) noexcept;

		/**
		 Draws text quickly. This is useful for text that changes often. Using this function will result in some quality loss, unless use smooth text is true.
		*/
		void DrawDynamicText(const Text& text, const Rectangle& rect, const Color& color = { 0,0,0 }, bool use_smooth_text = false) noexcept;

		/**
		 Draws a sprite on the window.
		*/
		void DrawSprite(const Sprite& sprite, const Rectangle& rect, const Rectangle& sprite_part = { -1,-1,-1,-1 }) noexcept;

		/**
		 Returns the optimal rendering size of the text.
		*/
		Size GetTextSize(const Text& text) const noexcept;

		/**
		 Initializes the SDL window, renderer and image library.
		*/
		bool InitWindow() noexcept;

		/**
		 Checks if the window is active or not.
		*/
		bool IsWindowActive() const noexcept;

		/**
		 Checks if the window is focused or not.
		*/
		bool IsWindowFocused() const noexcept;

		/**
		Sets if the window is focused or not.
		*/
		void WindowFocus(bool focused);

		/**
		 Closes the window and clears memory.
		*/
		void CloseWindow() noexcept;
		/**
		 Renders the current drawn objects since last clear.
		*/
		void Render() noexcept;

		/**
		 Clears the screen to a white background.
		*/
		void Clear() noexcept;
		/**
		 Sets the window title.
		*/
		void SetWindowTitle(const std::string& title) noexcept;

		/**
		 Sets the camera position.
		*/
		void SetCameraPosition(const Rectangle& rect) noexcept;

		/**
		 Disables the camera.
		*/
		void DisableCamera() noexcept;

		/**
		 Returns the current window title.
		*/
		std::string GetWindowTitle() const noexcept;

		/**
		 Returns the current window size.
		*/
		Size& GetWindowSize() const noexcept;

		/**
		 Set the window size.
		*/
		void SetWindowSize(Size size) const noexcept;

		/**
		 Set the scene size.
		*/
		void SetSceneSize(Size size) const noexcept;

		/**
		 Sets the game scale.
		*/
		void SetScale(Scale scale) noexcept;

		/**
		 Returns the current game scale.
		*/
		Scale& GetScale() const noexcept;

		/**
		 Sets the game scale.
		*/
		void SetGuiResolution(Size resolution) noexcept;

		/**
		 Returns the current game scale.
		*/
		Size& GetGuiResolution() const noexcept;
	};
}