#include "settings_window.hpp"

#include <qdebug.h>

#include "main_window.hpp"

SettingsWindow::SettingsWindow(QMainWindow * parent) : QMainWindow(parent)
{
  QWidget * centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QVBoxLayout * newLayout = new QVBoxLayout(centralWidget);

  m_startButton = new QPushButton("Start",this);
  m_startButton->move(15,50);

  m_labelDifficulty = new QLabel("Difficulty", this);

  m_comboBoxDifficulty = new QComboBox(this);
  m_comboBoxDifficulty->addItem("Difficulty 1", 1);
  m_comboBoxDifficulty->addItem("Difficulty 2", 2);
  m_comboBoxDifficulty->addItem("Difficulty 3", 3);

  m_labelSpeed = new QLabel("Speed", this);

  m_comboBoxSpeed = new QComboBox(this);
  m_comboBoxSpeed->addItem("Speed 1", 1);
  m_comboBoxSpeed->addItem("Speed 2", 2);
  m_comboBoxSpeed->addItem("Speed 3", 3);

  connect(m_startButton, SIGNAL(clicked()), this, SLOT(startButton_clicked()));

  newLayout->addWidget(m_startButton);
  newLayout->addWidget(m_labelDifficulty);
  newLayout->addWidget(m_comboBoxDifficulty);
  newLayout->addWidget(m_labelSpeed);
  newLayout->addWidget(m_comboBoxSpeed);

  setFocusPolicy(Qt::StrongFocus);
}

void SettingsWindow::startButton_clicked()
{
  qDebug("startButton_clicked");

  MainWindow * mainWindow = new MainWindow();

  mainWindow->show();

  this->hide();
}
