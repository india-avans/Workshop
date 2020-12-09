#include <India.h>
#include "ExampleScene.h"
#include "GuiScene.h"
#include <memory>

India::IndiaEngine& India::Create()
{
	std::vector<std::unique_ptr<India::Scene>> scenes;
	scenes.push_back(std::move(std::make_unique<GuiScene>(800, 600)));
	scenes.push_back(std::move(std::make_unique<ExampleScene>(10, true)));
	return IndiaEngine("IndiaEngine debug", scenes, 1);
}