#include "..\API_Headers\Button.hpp"
#include "../API_Headers/BehaviourScript.hpp"

SPIC_API spic::Button::Button(const std::string& asset, const int& x, const int& y, const int& h, const int& w, const std::string& behaviourscript) {
	buttonFacade = std::make_unique<spic::ButtonFacade>(x, y, w, h, asset);
	_behaviourscript = behaviourscript;
}

void spic::Button::Render() {
	if (!rendered) {
		rendered = true;
		buttonFacade->CreateTexture();
	}
	buttonFacade->Render();
	if (buttonFacade->clicked) {
		buttonFacade->clicked = false;

		std::shared_ptr<spic::Component> script = GetComponentByName(_behaviourscript);
		if (script != nullptr) {
			script->OnClick();
		}
	}
}