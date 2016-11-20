#pragma once

#include <QDialog>
#include <QPushButton>
#include <QMainWindow>
#include <qlabel.h>
#include <qcombobox.h>

class SettingsWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit SettingsWindow(QMainWindow * parent = 0);
private:
  QPushButton * m_startButton = nullptr;
  QLabel * m_labelDifficulty = nullptr;
  QComboBox * m_comboBoxDifficulty = nullptr;
  QLabel * m_labelSpeed = nullptr;
  QComboBox * m_comboBoxSpeed = nullptr;
private slots:
  void StartButtonClicked();
};
