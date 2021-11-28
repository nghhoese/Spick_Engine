#include "..\Facade_Headers\ButtonFacade.hpp"
#include "../API_Headers/Point.hpp"
#pragma warning(disable : 4996)

std::unique_ptr<MouseFacade> mousefacade_ptr2 = std::make_unique<MouseFacade>();;

spic::ButtonFacade::ButtonFacade(int x, int y, int w, int h, std::string asset) {
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;
    _asset = "assets/" + asset + ".jpg";
    bool mouse = mousefacade_ptr2->PollContinousEvent();
}

void spic::ButtonFacade::CreateTexture(SDL_Renderer* renderer) {
    std::string _path = _asset;
    char* a = new char[_path.size() + 1];
    strcpy(a, _path.c_str());
    SDL_Surface* tmpSurface = IMG_Load(a);
    _texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    delete[] a;
}

void spic::ButtonFacade::Render(SDL_Renderer* renderer) {


    SDL_RenderCopy(renderer, _texture, NULL, &box);
    spic::ButtonFacade::handle_events();
    SDL_DestroyTexture(_texture);
}

void spic::ButtonFacade::handle_events() {
    if (mousefacade_ptr2->GetMouseButtonDown(1)) {
    Point point;

        std::tuple<int, int> coords = mousefacade_ptr2->PollMousePosition();
        point.x = std::get<0>(coords);
        point.y = std::get<1>(coords);

        if ((point.x > box.x) && (point.x < box.x + box.w) && (point.y > box.y) && (point.y < box.y + box.h))
        {
            clicked = true;
        }
    }

    

}