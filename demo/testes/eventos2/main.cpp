#include "timerexample.h"
#include <gtkmm/main.h>

int main (int argc, char *argv[])
{
  Gtk::Main app(argc, argv);

  TimerExample example;
  Gtk::Main::run(example);

  return 0;
}
