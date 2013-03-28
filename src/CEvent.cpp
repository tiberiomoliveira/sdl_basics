#include "CEvent.h"

CEvent::CEvent() {}

CEvent::~CEvent() {}

void
CEvent::on_event(SDL_Event* event) {
  switch (event->type) {
    case SDL_ACTIVEEVENT:
      switch (event->active.state) {
        case SDL_APPINPUTFOCUS:
          if (event->active.gain)
            on_input_focus();
          else
            on_input_blur();
          break;
        case SDL_APPMOUSEFOCUS:
          if (event->active.gain)
            on_mouse_focus();
          else
            on_mouse_blur();
          break;
        case SDL_APPACTIVE:
          if (event->active.gain)
            on_minimize();
          else
            on_restore();
          break;
      }
      break;
    case SDL_KEYDOWN:
      on_key_down(event->key.keysym.sym,
                  event->key.keysym.mod,
                  event->key.keysym.unicode);
      break;
    case SDL_KEYUP:
      on_key_up(event->key.keysym.sym,
                event->key.keysym.mod,
                event->key.keysym.unicode);
      break;
    case SDL_MOUSEMOTION:
      on_mouse_move(event->motion.x, event->motion.y,
                    event->motion.xrel, event->motion.yrel,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
      break;
    case SDL_MOUSEBUTTONDOWN:
      switch (event->button.button) {
        case SDL_BUTTON_LEFT:
          on_lbutton_down(event->button.x, event->button.y);
          break;
        case SDL_BUTTON_RIGHT:
          on_rbutton_down(event->button.x, event->button.y);
          break;
        case SDL_BUTTON_MIDDLE:
          on_mbutton_down(event->button.x, event->button.y);
          break;
      }
      break;
    case SDL_MOUSEBUTTONUP:
      switch (event->button.button) {
        case SDL_BUTTON_LEFT:
          on_lbutton_up(event->button.x, event->button.y);
          break;
        case SDL_BUTTON_RIGHT:
          on_rbutton_up(event->button.x, event->button.y);
          break;
        case SDL_BUTTON_MIDDLE:
          on_mbutton_up(event->button.x, event->button.y);
          break;
      }
      break;
    case SDL_JOYAXISMOTION:
      on_joy_axis(event->jaxis.which, event->jaxis.axis, event->jaxis.value);
      break;
    case SDL_JOYBUTTONDOWN:
      on_joy_button_down(event->jbutton.which, event->jbutton.button);
      break;
    case SDL_JOYBUTTONUP:
      on_joy_button_up(event->jbutton.which, event->jbutton.button);
      break;
    case SDL_JOYHATMOTION:
      on_joy_hat(event->jhat.which, event->jhat.hat, event->jhat.value);
      break;
    case SDL_JOYBALLMOTION:
      on_joy_ball(event->jball.which, event->jball.ball,
                  event->jball.xrel,  event->jball.yrel);
      break;
    case SDL_SYSWMEVENT:
      //ignore
      break;
    case SDL_VIDEORESIZE:
      on_resize(event->resize.w, event->resize.h);
      break;
    case SDL_VIDEOEXPOSE:
      on_expose();
      break;
    case SDL_QUIT:
      on_exit();
      break;
    default:
      on_user(event->user.type,  event->user.code,
              event->user.data1, event->user.data2);
      break;
  }
}

// Pure virtual, do nothing
void
CEvent::on_input_focus() {}

// Pure virtual, do nothing
void
CEvent::on_input_blur() {}

// Pure virtual, do nothing
void
CEvent::on_mouse_focus() {}

// Pure virtual, do nothing
void
CEvent::on_mouse_blur() {}

// Pure virtual, do nothing
void
CEvent::on_minimize() {}

// Pure virtual, do nothing
void
CEvent::on_restore() {}

// Pure virtual, do nothing
void
CEvent::on_key_down(SDLKey sym, SDLMod mod, Uint16 unicode) {}

// Pure virtual, do nothing
void
CEvent::on_key_up(SDLKey sym, SDLMod mod, Uint16 unicode) {}

// Pure virtual, do nothing
void
CEvent::on_mouse_move(int  m_x,  int  m_y,
                      int  xrel, int  yrel,
                      bool left, bool right, bool middle) {}

// Pure virtual, do nothing
void
CEvent::on_mouse_wheel(bool up, bool down) {}

// Pure virtual, do nothing
void
CEvent::on_lbutton_down(int m_x, int m_y) {}

// Pure virtual, do nothing
void
CEvent::on_lbutton_up(int m_x, int m_y) {}

// Pure virtual, do nothing
void
CEvent::on_rbutton_down(int m_x, int m_y) {}

// Pure virtual, do nothing
void
CEvent::on_rbutton_up(int m_x, int m_y) {}

// Pure virtual, do nothing
void
CEvent::on_mbutton_down(int m_x, int m_y) {}

// Pure virtual, do nothing
void
CEvent::on_mbutton_up(int m_x, int m_y) {}

// Pure virtual, do nothing
void
CEvent::on_joy_axis(Uint8 which, Uint8 axis, Sint16 value) {}

// Pure virtual, do nothing
void
CEvent::on_joy_button_down(Uint8 which, Uint8 button) {}

// Pure virtual, do nothing
void
CEvent::on_joy_button_up(Uint8 which, Uint8 button) {}

// Pure virtual, do nothing
void
CEvent::on_joy_hat(Uint8 which, Uint8 hat, Uint8 value) {}

// Pure virtual, do nothing
void
CEvent::on_joy_ball(Uint8  which, Uint8  ball,
                    Sint16 xrel,  Sint16 yrel) {}

// Pure virtual, do nothing
void
CEvent::on_resize(int w, int h) {}

// Pure virtual, do nothing
void
CEvent::on_expose() {}

// Pure virtual, do nothing
void
CEvent::on_exit() {}

// Pure virtual, do nothing
void
CEvent::on_user(Uint8 type, int code, void* data1, void* data2) {}
