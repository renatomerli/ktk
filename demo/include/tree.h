
#include <gtkmm.h>


class CellItem_Bug
{
public:
  CellItem_Bug();
  CellItem_Bug(bool fixed, guint number, const Glib::ustring& severity, const Glib::ustring& description);
  CellItem_Bug(const CellItem_Bug& src);
  ~CellItem_Bug();
  CellItem_Bug& operator=(const CellItem_Bug& src);

  bool m_fixed;
  guint m_number;
  Glib::ustring m_severity;
  Glib::ustring m_description;
};

class Tree : public Gtk::TreeView
{
public:
  Tree();
  virtual ~Tree();

protected:
  virtual void create_model();
  virtual void add_columns();
  virtual void add_items();
  virtual void liststore_add_item(const CellItem_Bug& foo);

  //Member widgets:
  Glib::RefPtr<Gtk::ListStore> m_refListStore;

  typedef std::vector<CellItem_Bug> type_vecItems;
  type_vecItems m_vecItems;

  struct ModelColumns : public Gtk::TreeModelColumnRecord
  {
    Gtk::TreeModelColumn<bool>          fixed;
    Gtk::TreeModelColumn<unsigned int>  number;
    Gtk::TreeModelColumn<Glib::ustring> severity;
    Gtk::TreeModelColumn<Glib::ustring> description;

    ModelColumns() { add(fixed); add(number); add(severity); add(description); }
  };

  const ModelColumns m_columns;

};


