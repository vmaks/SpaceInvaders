#include "settingspage.hpp"
#include "ui_settingspage.h"

SettingsPage::SettingsPage(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SettingsPage)
{
  ui->setupUi(this);

  ui->comboBoxDifficulty->addItem("Easy", 1);
  ui->comboBoxDifficulty->addItem("Normal", 2);
  ui->comboBoxDifficulty->addItem("Hard", 3);

  ui->comboBoxSpeed->addItem("Speed 1", 1);
  ui->comboBoxSpeed->addItem("Speed 2", 2);
  ui->comboBoxSpeed->addItem("Speed 3", 3);

  connect(this, SIGNAL(moveToMenuPage()),
          parent, SLOT(moveToMenuPage()));
}

SettingsPage::~SettingsPage()
{
  delete ui;
}

void SettingsPage::on_menuButton_clicked()
{
  emit moveToMenuPage();
}
