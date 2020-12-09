#pragma once
#include "Core.h"
#include "Component.h"
#include "Sprite.h"

#include <map>
#include <vector>
#include <string>

namespace India {

	class India_EXPORT SpriteComponent : public Component {
	public:
		SpriteComponent(const SpriteComponent& other);
		SpriteComponent() noexcept;
		SpriteComponent(std::map<std::string, std::vector<Sprite>> sprites, std::string active_sprite_key, int delay = 100) noexcept;
		/**
		Set sprite
		*/
		void SetSprites(std::map<std::string, std::vector<Sprite>> sprites, std::string active_sprite_key, int delay);
		~SpriteComponent() override;
		/**
		Set sprite_key accordingly to parameter value.
		*/
		void SetActiveSpriteKey(const std::string& sprite_key, bool loop = true);
		/**
		Return active sprite.
		*/
		Sprite GetActiveSprite() const noexcept;
		/**
		Return key of active sprite.
		*/
		std::string GetActiveSpriteKey() const noexcept;
		/**
		Set active sprite index accordingly to parameter value.
		*/
		void SetActiveSpriteIndex(int sprite_index);
		/**
		Return index of active sprite.
		*/
		int GetActiveSpriteIndex() const noexcept;
		/**
		Returns the amount of sprites for the specified sprite key.
		*/
		int GetSpriteCount(const std::string& sprite_key) const noexcept;
		/**
		Returns sprite that was previously active.
		*/
		Sprite GetPreviousActiveSprite() const noexcept;
		/**
		Returns key of the sprite that was previously active.
		*/
		std::string GetPreviousActiveSpriteKey() const noexcept;
		/**
		Returns index of the sprite that was previously active.
		*/
		int GetPreviousActiveSpriteIndex() const noexcept;

		/**
		Set animation delay in milliseconds for every key (every x frames a new sprite will be shown)
		*/
		void SetAnimationDelay(int delay) noexcept;

		/**
		Set animation delay in milliseconds for a specific key (every x frames a new sprite will be shown)
		*/
		void SetAnimationDelay(int delay, std::string key) noexcept;

		/**
		Returns the animation delay in milliseconds for a specific key.
		*/
		int GetAnimationDelay(std::string key) const noexcept;

		/**
		Returns the current active key animation delay in milliseconds.
		*/
		int GetCurrentAnimationDelay() const noexcept;
		
		/**
		Updates the component frame counter.
		*/
		void SetAnimationTime(float time);

		/**
		Returns the component frame counter.
		*/
		float GetAnimationTime();
		/**
		Returns true if the animation should loop and false if not.
		*/
		bool ShouldLoop();

		std::map<std::string, std::vector<Sprite>> GetSprites();

	private:
		Sprite _active_sprite;
		Sprite _previous_active_sprite;

		std::string _active_sprite_key;
		std::string _previous_active_sprite_key;

		int _active_sprite_index;
		int _previous_active_sprite_index;

		bool _loop = true;

		std::map<std::string, int> _animation_delays;
		float _animation_time = 0;

		std::map<std::string, std::vector<Sprite>> _sprites;
	};

}