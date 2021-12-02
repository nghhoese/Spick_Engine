#include "..\Facade_Headers\ButtonFacade.hpp"
#include "../API_Headers/Point.hpp"
#include "..\Facade_Headers\ImageFacade.hpp"
#pragma warning(disable : 4996)

spic::ButtonFacade::ButtonFacade(int x, int y, int w, int h, std::string asset) {
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;
    _asset = "assets/" + asset + ".jpg";
    this->input = new spic::Importation();
}

void spic::ButtonFacade::CreateTexture() {
    std::string _path = _asset;
    char* a = new char[_path.size() + 1];
    strcpy(a, _path.c_str());
    SDL_Surface* tmpSurface = IMG_Load(a);
    _texture = SDL_CreateTextureFromSurface(spic::WindowFacade::GetInstance()->_renderer.get(), tmpSurface);
    SDL_FreeSurface(tmpSurface);
    delete[] a;
}

void spic::ButtonFacade::Render() {


    SDL_RenderCopy(spic::WindowFacade::GetInstance()->_renderer.get(), _texture, NULL, &box);
    spic::ButtonFacade::handle_events();
    //SDL_DestroyTexture(_texture);
}

void spic::ButtonFacade::handle_events() {
    if (input->GetMouseButton(LEFT)) {
    Point point = input->GetMousePosition();

        if ((point.x > box.x) && (point.x < box.x + box.w) && (point.y > box.y) && (point.y < box.y + box.h))
        {
            clicked = true;
        }
    }
}