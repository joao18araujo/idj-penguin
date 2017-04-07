#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include<map>

using std::unordered_map;

class InputManager{
private:
  bool mouse_state[6];
  int mouse_update[6];

  unordered_map<int, bool> key_state;
  unordered_map<int, int> key_update;

  bool m_quit_requested;
  int update_counter;

  int mouse_x;
  int mouse_y;

public:
  InputManager();
  ~InputManager();

  void update();

  bool key_press(int key);
  bool key_release(int key);
  bool is_key_down(int key);

  bool mouse_press(int button);
  bool mouse_release(int button);
  bool is_mouse_down(int button);

  int get_mouse_x();
  int get_mouse_y();

  bool quit_requested();

  static InputManager & get_instance();
};

#endif
