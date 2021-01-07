class Window_EasterEgg : public Gtk::Window
{
public:
  Window_EasterEgg();
  virtual ~Window_EasterEgg();

protected:
  virtual void recursive_attach_view(int depth, Gtk::TextView& view, Glib::RefPtr<Gtk::TextChildAnchor> refAnchor);

  //Member widgets:
  Gtk::TextView* m_pTextView;
  Gtk::ScrolledWindow m_ScrolledWindow;
};





class Example_TextView : public Gtk::Frame
{
public:
  Example_TextView();
  virtual ~Example_TextView();

protected:
  virtual void create_tags(Glib::RefPtr<Gtk::TextBuffer>& refBuffer);
  virtual void insert_text(Glib::RefPtr<Gtk::TextBuffer>& refBuffer);
  virtual void attach_widgets(Gtk::TextView& text_view);
  virtual bool find_anchor(Gtk::TextBuffer::iterator& iter);

  //Signal handlers:
  virtual void on_button_clicked();


  //Member widgets
  Gtk::VPaned m_VPaned;
  Gtk::TextView m_View1;
  Gtk::TextView* m_pView2;
  Gtk::ScrolledWindow m_ScrolledWindow1, m_ScrolledWindow2;

  Window_EasterEgg m_WindowEasterEgg;
};

