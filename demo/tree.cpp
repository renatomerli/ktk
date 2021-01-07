#include <gtkmm.h>
#include "tree.h"

CellItem_Bug::CellItem_Bug()
{
  m_fixed = false;
  m_number = 0;
}

CellItem_Bug::CellItem_Bug(bool fixed, guint number, const Glib::ustring& severity, const Glib::ustring& description)
{
  m_fixed = fixed;
  m_number = number;
  m_severity = severity;
  m_description = description;
}

CellItem_Bug::CellItem_Bug(const CellItem_Bug& src)
{
  operator=(src);
}

CellItem_Bug::~CellItem_Bug()
{
}

CellItem_Bug& CellItem_Bug::operator=(const CellItem_Bug& src)
{
  m_fixed = src.m_fixed;
  m_number = src.m_number;
  m_severity = src.m_severity;
  m_description = src.m_description;

  return *this;
}





// construtor 
Tree::Tree()
{
    


  create_model();

  set_model(m_refListStore);
  set_rules_hint();
  set_search_column(m_columns.description.index());


  add_columns();
  show_all();

}

Tree::~Tree()
{
}

void Tree::add_items()
{
  m_vecItems.push_back( CellItem_Bug(false, 60482, "Normal",     "scrollable notebooks and hidden tabs") );
  m_vecItems.push_back( CellItem_Bug(false, 60620, "Critical",   "gdk_window_clear_area (gdkwindow-win32.c) is not thread-safe") );
  m_vecItems.push_back( CellItem_Bug(false, 50214, "Major",      "Xft support does not clean up correctly") );
  m_vecItems.push_back( CellItem_Bug(true,  52877, "Major",      "GtkFileSelection needs a refresh method. ") );
  m_vecItems.push_back( CellItem_Bug(false, 56070, "Normal",     "Can not click button after setting insensitive") );
  m_vecItems.push_back( CellItem_Bug(true,  56355, "Normal",     "GtkLabel - Not all changes propagate correctly") );
  m_vecItems.push_back( CellItem_Bug(false, 50055, "Normal",     "Rework width/height computations for TreeView") );
  m_vecItems.push_back( CellItem_Bug(false, 58278, "Normal",     "gtk_dialog_set_response_sensitive () does nott work") );
  m_vecItems.push_back( CellItem_Bug(false, 55767, "Normal",     "Getters for all setters") );
  m_vecItems.push_back( CellItem_Bug(false, 56925, "Normal",     "Gtkcalender size") );
  m_vecItems.push_back( CellItem_Bug(false, 56221, "Normal",     "Selectable label needs right-click copy menu") );
  m_vecItems.push_back( CellItem_Bug(true,  50939, "Normal",     "Add shift clicking to GtkTextView") );
  m_vecItems.push_back( CellItem_Bug(false, 6112,  "Enhancement","netscape-like collapsable toolbars") );
  m_vecItems.push_back( CellItem_Bug(false, 1,     "Normal",     "First bug :=)") );
}

void Tree::create_model()
{
  m_refListStore = Gtk::ListStore::create(m_columns);

  add_items();

  std::for_each(
      m_vecItems.begin(), m_vecItems.end(),
      sigc::mem_fun(*this, &Tree::liststore_add_item));
}

void Tree::liststore_add_item(const CellItem_Bug& foo)
{
  Gtk::TreeRow row = *(m_refListStore->append());

  row[m_columns.fixed]       = foo.m_fixed;
  row[m_columns.number]      = foo.m_number;
  row[m_columns.severity]    = foo.m_severity;
  row[m_columns.description] = foo.m_description;
}



void Tree::add_columns()
{
   /* column for fixed toggles */
  {
    int cols_count = append_column_editable("Fixed", m_columns.fixed);
    Gtk::TreeViewColumn* pColumn = get_column(cols_count-1);

    /* set this column to a fixed sizing (of 50 pixels) */
  pColumn->set_sizing(Gtk::TREE_VIEW_COLUMN_FIXED);
    pColumn->set_fixed_width(50);
    pColumn->set_clickable();
  }

  /* column for bug numbers */
  append_column("Bug number", m_columns.number);

  /* column for severities */
  append_column("Severity", m_columns.severity);

  /* column for descriptions */
  append_column("Description", m_columns.description);
}