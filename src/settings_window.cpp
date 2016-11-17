#include "settings_window.hpp"

SettingsWindow::SettingsWindow(QMainWindow * parent) : QMainWindow(parent)
{
  QWidget * centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);
  m_settingsButton = new QPushButton("Settings",this);
  m_settingsButton->move(15,50);
  setFocusPolicy(Qt::StrongFocus);
}
