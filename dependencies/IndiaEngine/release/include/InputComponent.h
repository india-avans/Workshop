#pragma once
#include "Component.h"
#include "InputStruct.h"
namespace India {
	
	class India_EXPORT InputComponent : public Component {
	public:
		InputComponent(InputComponent&& other) noexcept = default;
		InputComponent& operator=(InputComponent&& other) noexcept = default;
		InputComponent() noexcept;
		/**
		KEYBOARD AS INPUT: Returns vector consisting of inputstruct with key scencodex.
		*/
		std::vector<std::reference_wrapper<InputStruct>> GetKeybindKeyHold() const noexcept;
		std::vector<std::reference_wrapper<InputStruct>> GetKeybindKeyUp() const noexcept;
		std::vector<std::reference_wrapper<InputStruct>> GetKeybindKeyDown() const noexcept;
		/**
		CONTROLLER AS INPUT: Returns vector consisting of inputstruct with key scencodex.
		*/
		std::vector<std::reference_wrapper<InputStruct>> GetKeybindController() const noexcept;
		/**
		KEYBOARD AS INPUT: Adds keybind to existing vecotr of scancodes
		*/
		void AddBindKeyHold(std::string scancode_key_hold, const func_ptr_t callback) noexcept;
		void AddBindKeyUp(std::string scancode_key, const func_ptr_t callback) noexcept;
		void AddBindKeyDown(std::string scancode_key, const func_ptr_t func_ptr_t) noexcept;
		/**
		Controller AS INPUT: Adds keybind to existing vecotr of scancodes
		*/
		void AddBindController(std::string scancode_controller, const func_ptr_t func_ptr_t) noexcept;
		InputComponent(std::vector<std::tuple<std::string, func_ptr_t>> keycombination_hold) noexcept;
		InputComponent(std::vector<std::tuple<std::string, func_ptr_t>> keycombination_hold, std::vector<std::tuple<std::string, func_ptr_t>> keycombination_up) noexcept;
		InputComponent(std::vector<std::tuple<std::string, func_ptr_t>> keycombination_hold, std::vector<std::tuple<std::string, func_ptr_t>> keycombination_up, std::vector<std::tuple<std::string, func_ptr_t>> keycombination_down) noexcept;

	private:
		std::vector<std::unique_ptr<InputStruct>> _scancode_key_hold;
		std::vector<std::unique_ptr<InputStruct>> _scancode_key_up;
		std::vector<std::unique_ptr<InputStruct>> _scancode_key_down;
		std::vector<std::unique_ptr<InputStruct>> _scancode_controller;
	};

}