#include "..\API_Headers\Text.hpp"

SPIC_API spic::Text::Text(const std::string& text, const std::string& font, const int& size, const Color& color, int x, int y) {
	_text = text;
	_font = font;
	_size = size;
	_color = color;
	_x = x;
	_y = y;
	textFacade = std::make_unique<spic::TextFacade>(_text, _font, _size, _color, _x, _y);
}

void spic::Text::Render() {
	textFacade->setValues(_text, _font, _size, _color, _x, _y);
	textFacade->Createtexture(getScene()->GetSceneFacade()->_renderer.get());
	textFacade->Render(getScene()->GetSceneFacade()->_renderer.get());
}