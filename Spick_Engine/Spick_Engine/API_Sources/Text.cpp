#include "..\API_Headers\Text.hpp"

SPIC_API spic::Text::Text() {

}

void spic::Text::OnRender()
{
	TextFacade* textFacade = new TextFacade("hallo", "Fonts/Capsmall.ttf");
	textFacade->Createtexture(getScene()->GetSceneFacade()->_renderer.get());
	textFacade->Render(getScene()->GetSceneFacade()->_renderer.get());

}

void spic::Text::Render() {
	TextFacade* textFacade = new TextFacade("hallo", "Fonts\Capsmall.ttf");
	textFacade->Createtexture(getScene()->GetSceneFacade()->_renderer.get());
	textFacade->Render(getScene()->GetSceneFacade()->_renderer.get());
}