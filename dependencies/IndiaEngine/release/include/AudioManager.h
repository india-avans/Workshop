#pragma once
#include "Core.h"
#include "Manager.h"
#include <memory>
#include <string>

namespace India {

	struct India_EXPORT Audio {
	public:
		Audio(std::string vtype, std::string vname, int vvolume)
		{
			type = vtype;
			name = vname;
			volume = vvolume;
		};

		std::string type;
		std::string name;
		int volume;
	};

	//https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer.html
	/**
		Only supported file type at the moment is .WAV other files will result in no music playing
	*/
	class India_EXPORT AudioManager : public Manager
	{
	public:
		AudioManager(const std::string& base_directory = "/resources") noexcept;
		~AudioManager() override;

		/**
			Play a sound or if loop is set to true play the music
		*/
		bool PlaySound(const std::string& id, bool loop = false) noexcept;

		/**
			Load a sound with an Audio object, again the key in the mSound map will be the audio name
		*/
		bool LoadSound(const Audio& audio) noexcept;

		/**
			Load Music with an Audio object, the key in the mMusic map will be the audio name
		*/
		bool LoadMusic(const Audio& audio) noexcept;

		/**
			Adjust the volume of the music played.
			The volume can only be from 0 up to including 128
		*/
		bool AdjustMusicVolume(int volume) noexcept;

		/**
			Adjust the volume of certain sounds with the sound's id
			The volume can only be from 0 up to including 128
		*/
		bool AdjustSoundVolume(int volume, const std::string& id) noexcept;

		/**
			Pause or resume the music based on the state the music is currently in
		*/
		void AdjustMusicState() noexcept;

		/**
			Returns the current volume for the object linked to given id
			if the id is empty volume of music is given
		*/
		int GetCurrentVolume(const std::string & = "") const noexcept;
	private:
		struct impl;
		std::unique_ptr<impl> pimpl;
	};

}
