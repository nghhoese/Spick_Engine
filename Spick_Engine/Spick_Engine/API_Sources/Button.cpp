#include "..\API_Headers\Button.hpp"

SPIC_API spic::Button::Button(const std::string& asset, const int& x, const int& y, const int& h, const int& w) {
	buttonFacade = std::make_unique<spic::ButtonFacade>(x, y, w, h, asset);
}

void spic::Button::Render() {
	buttonFacade->CreateTexture(getScene()->GetSceneFacade()->_renderer.get());
	buttonFacade->Render(getScene()->GetSceneFacade()->_renderer.get());
}