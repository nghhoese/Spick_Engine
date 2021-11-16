#include "../Facade_Headers/KeyFacade.hpp"

KeyFacade::KeyFacade() {

}

KeyCode KeyFacade::PollEvent() {
	if (SDL_PollEvent(&sdlEvent) != 0)
	{
		switch (sdlEvent.type) {
		    case SDL_KEYDOWN:
			    return TranslateToEnum(sdlEvent);
            case SDL_KEYUP:
                return TranslateToEnum(sdlEvent);
		    default:
			    return KeyCode::ERROR_UNDEFINED;
		}
	}
}

bool KeyFacade::PollContinousEvent(const KeyCode& key)
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

KeyCode KeyFacade::TranslateToEnum(const SDL_Event& sdlEvent) const {
    switch (sdlEvent.key.keysym.sym)
    {
        case SDLK_0:
            return KeyCode::NUMBER_0_AND_CLOSING_PARENTHESIS;
        case SDLK_1:
            return KeyCode::NUMBER_1_AND_EXCLAMATION;
        case SDLK_2:
            return KeyCode::NUMBER_2_AND_AT;
        case SDLK_3:
            return KeyCode::NUMBER_3_AND_HASHMARK;
        case SDLK_4:
            return KeyCode::NUMBER_4_AND_DOLLAR;
        case SDLK_5:
            return KeyCode::NUMBER_5_AND_PERCENTAGE;
        case SDLK_6:
            return KeyCode::NUMBER_6_AND_CARET;
        case SDLK_7:
            return KeyCode::NUMBER_7_AND_AMPERSAND;
        case SDLK_8:
            return KeyCode::NUMBER_8_AND_ASTERISK;
        case SDLK_9:
            return KeyCode::NUMBER_9_AND_OPENING_PARENTHESIS;
        case SDLK_LEFT:
            return KeyCode::LEFT_ARROW;
        case SDLK_RIGHT:
            return KeyCode::RIGHT_ARROW;
        case SDLK_UP:
            return KeyCode::UP_ARROW;
        case SDLK_DOWN:
            return KeyCode::DOWN_ARROW;
        case SDLK_a:
            return KeyCode::A;
        case SDLK_b:
            return KeyCode::B;
        case SDLK_c:
            return KeyCode::C;
        case SDLK_d:
            return KeyCode::D;
        case SDLK_e:
            return KeyCode::E;
        case SDLK_f:
            return KeyCode::F;
        case SDLK_g:
            return KeyCode::G;
        case SDLK_h:
            return KeyCode::H;
        case SDLK_i:
            return KeyCode::I;
        case SDLK_j:
            return KeyCode::J;
        case SDLK_k:
            return KeyCode::K;
        case SDLK_l:
            return KeyCode::L;
        case SDLK_m:
            return KeyCode::M;
        case SDLK_n:
            return KeyCode::N;
        case SDLK_o:
            return KeyCode::O;
        case SDLK_p:
            return KeyCode::P;
        case SDLK_q:
            return KeyCode::Q;
        case SDLK_r:
            return KeyCode::R;
        case SDLK_s:
            return KeyCode::S;
        case SDLK_t:
            return KeyCode::T;
        case SDLK_u:
            return KeyCode::U;
        case SDLK_v:
            return KeyCode::V;
        case SDLK_w:
            return KeyCode::W;
        case SDLK_x:
            return KeyCode::X;
        case SDLK_y:
            return KeyCode::Y;
        case SDLK_z:
            return KeyCode::Z;
        case SDLK_BACKSPACE:
            return KeyCode::BACKSPACE;
        case SDLK_SPACE:
            return KeyCode::SPACE;
        case SDLK_ESCAPE:
            return KeyCode::ESCAPE;
        case SDLK_PAGEUP:
            return KeyCode::PAGE_UP;
        case SDLK_PAGEDOWN:
            return KeyCode::PAGE_DOWN;
        case SDLK_HOME:
            return KeyCode::HOME;
        case SDLK_EQUALS:
            return KeyCode::KEYPAD_EQUAL_SIGN;
        default:
            return KeyCode::ERROR_UNDEFINED;
    }
}
