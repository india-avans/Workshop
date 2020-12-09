#pragma once
#include "DrawingFacade.h"
#include "Sprite.h"

namespace India {

	class India_EXPORT Graphics2D {
	public:
		Graphics2D(DrawingFacade& drawing_facade) noexcept;

		/**
		 Draws a rectangle on the window.
		*/
		void DrawRect(const Rectangle& rect, const Color& color = { 0,0,0 }, bool should_fill = false) const noexcept;

		/**
		 Draws and fills a rectangle on the window.
		*/
		void FillRect(const Rectangle& rect, const Color& color = { 0,0,0 }) const noexcept;

		/**
		 Draws and caches blended text. This is useful for text that does not change often.
		*/
		void DrawText(const Text& text, const Rectangle& rect, const Color& color = { 0,0,0 }) const noexcept;

		/**
		 Draws text quickly. This is useful for text that changes often. Using this function will result in some quality loss, unless use smooth text is true.
		*/
		void DrawDynamicText(const Text& text, const Rectangle& rect, const Color& color = { 0,0,0 }, bool use_smooth_text = false) const noexcept;

		/**
		 Draws a sprite on the window.
		*/
		void DrawSprite(const Sprite& sprite, const Rectangle& rect, const Rectangle& src = { -1,-1,-1,-1 }) const noexcept;

		/**
		 Returns the window size
		*/
		Size& GetWindowSize() const noexcept;

		/**
		 Returns the optimal rendering size of the text.
		*/
		Size GetTextSize(const Text& text) const noexcept;

		/**
		 Returns the current scale.
		*/
		Scale GetScale() const noexcept;

		/**
		 Returns the optimal font size based on GUI resolution.
		*/
		int GetOptimalFontSize(int base_size) const noexcept;

		/**
		 Returns the current GUI resolution.
		*/
		Size& GetGuiResolution() const noexcept;

	private:
		DrawingFacade& _drawing_facade;
	};

}