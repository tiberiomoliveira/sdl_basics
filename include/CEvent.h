#ifndef _CEVENT_H_
#define _CEVENT_H_

#include <SDL/SDL.h>

class CEvent {
  public:
    CEvent();
    virtual ~CEvent();

    virtual void on_event(SDL_Event* event);
    virtual void on_input_focus();
    virtual void on_input_blur();
    virtual void on_mouse_focus();
    virtual void on_mouse_blur();
    virtual void on_minimize();
    virtual void on_restore();
    virtual void on_key_down(SDLKey sym, SDLMod mod, Uint16 unicode);
    virtual void on_key_up(SDLKey sym, SDLMod mod, Uint16 unicode);
    virtual void on_mouse_move(int  m_x,  int  m_y,
                               int  xrel, int  yrel,
                               bool left, bool right, bool middle);
    virtual void on_mouse_wheel(bool up, bool down);
    virtual void on_lbutton_down(int m_x, int m_y);
    virtual void on_lbutton_up(int m_x, int m_y);
    virtual void on_rbutton_down(int m_x, int m_y);
    virtual void on_rbutton_up(int m_x, int m_y);
    virtual void on_mbutton_down(int m_x, int m_y);
    virtual void on_mbutton_up(int m_x, int m_y);
    virtual void on_joy_axis(Uint8 which, Uint8 axis, Sint16 value);
    virtual void on_joy_button_down(Uint8 which, Uint8 button);
    virtual void on_joy_button_up(Uint8 which, Uint8 button);
    virtual void on_joy_hat(Uint8 which, Uint8 hat, Uint8 value);
    virtual void on_joy_ball(Uint8  which, Uint8  ball,
                             Sint16 xrel,  Sint16 yrel);
    virtual void on_resize(int w, int h);
    virtual void on_expose();
    virtual void on_exit();
    virtual void on_user(Uint8 type, int code, void* data1, void* data2);
};

#endif
