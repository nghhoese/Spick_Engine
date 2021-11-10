#include "../Facade_Headers/KeyFacade.hpp"

KeyFacade::KeyFacade() {

}

Input::KeyCode KeyFacade::PollEvent() {
	if (SDL_PollEvent(&sdlEvent) != 0)
	{
		switch (sdlEvent.type) {
		    case SDL_KEYDOWN:
			    return TranslateToEnum(sdlEvent);
            case SDL_KEYUP:
                return TranslateToEnum(sdlEvent);
		    default:
			    return Input::KeyCode::ERROR_UNDEFINED;
		}
	}
}

bool KeyFacade::PollContinousEvent(const Input::KeyCode& key)
{
    int keyValue = (int)key;
    if (SDL_GetKeyboardState(&keyValue))
    {
        if (keyValue == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool KeyFacade::PollContinousEvent()
{
    if (SDL_GetKeyboardState(NULL))
    {
        return true;
    }
   
    return false;

}





Input::KeyCode KeyFacade::TranslateToEnum(const SDL_Event& sdlEvent) const {
    switch (sdlEvent.key.keysym.sym)
    {
        case SDLK_0:
            return Input::KeyCode::NUMBER_0_AND_CLOSING_PARENTHESIS;
        case SDLK_1:
            return Input::KeyCode::NUMBER_1_AND_EXCLAMATION;
        case SDLK_2:
            return Input::KeyCode::NUMBER_2_AND_AT;
        case SDLK_3:
            return Input::KeyCode::NUMBER_3_AND_HASHMARK;
        case SDLK_4:
            return Input::KeyCode::NUMBER_4_AND_DOLLAR;
        case SDLK_5:
            return Input::KeyCode::NUMBER_5_AND_PERCENTAGE;
        case SDLK_6:
            return Input::KeyCode::NUMBER_6_AND_CARET;
        case SDLK_7:
            return Input::KeyCode::NUMBER_7_AND_AMPERSAND;
        case SDLK_8:
            return Input::KeyCode::NUMBER_8_AND_ASTERISK;
        case SDLK_9:
            return Input::KeyCode::NUMBER_9_AND_OPENING_PARENTHESIS;
        case SDLK_LEFT:
            return Input::KeyCode::LEFT_ARROW;
        case SDLK_RIGHT:
            return Input::KeyCode::RIGHT_ARROW;
        case SDLK_UP:
            return Input::KeyCode::UP_ARROW;
        case SDLK_DOWN:
            return Input::KeyCode::DOWN_ARROW;
        case SDLK_a:
            return Input::KeyCode::A;
        case SDLK_b:
            return Input::KeyCode::B;
        case SDLK_c:
            return Input::KeyCode::C;
        case SDLK_d:
            return Input::KeyCode::D;
        case SDLK_e:
            return Input::KeyCode::E;
        case SDLK_f:
            return Input::KeyCode::F;
        case SDLK_g:
            return Input::KeyCode::G;
        case SDLK_h:
            return Input::KeyCode::H;
        case SDLK_i:
            return Input::KeyCode::I;
        case SDLK_j:
            return Input::KeyCode::J;
        case SDLK_k:
            return Input::KeyCode::K;
        case SDLK_l:
            return Input::KeyCode::L;
        case SDLK_m:
            return Input::KeyCode::M;
        case SDLK_n:
            return Input::KeyCode::N;
        case SDLK_o:
            return Input::KeyCode::O;
        case SDLK_p:
            return Input::KeyCode::P;
        case SDLK_q:
            return Input::KeyCode::Q;
        case SDLK_r:
            return Input::KeyCode::R;
        case SDLK_s:
            return Input::KeyCode::S;
        case SDLK_t:
            return Input::KeyCode::T;
        case SDLK_u:
            return Input::KeyCode::U;
        case SDLK_v:
            return Input::KeyCode::V;
        case SDLK_w:
            return Input::KeyCode::W;
        case SDLK_x:
            return Input::KeyCode::X;
        case SDLK_y:
            return Input::KeyCode::Y;
        case SDLK_z:
            return Input::KeyCode::Z;
        case SDLK_BACKSPACE:
            return Input::KeyCode::BACKSPACE;
        case SDLK_SPACE:
            return Input::KeyCode::SPACE;
        case SDLK_ESCAPE:
            return Input::KeyCode::ESCAPE;
        case SDLK_PAGEUP:
            return Input::KeyCode::PAGE_UP;
        case SDLK_PAGEDOWN:
            return Input::KeyCode::PAGE_DOWN;
        case SDLK_HOME:
            return Input::KeyCode::HOME;
        case SDLK_EQUALS:
            return Input::KeyCode::KEYPAD_EQUAL_SIGN;
        default:
            return Input::KeyCode::ERROR_UNDEFINED;
    }
}
