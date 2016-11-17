#pragma once

#include <QDialog>
#include <QPushButton>
#include <QMainWindow>

class SettingsWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit SettingsWindow(QMainWindow * parent = 0);
private:
  QPushButton * m_settingsButton = nullptr;
};
