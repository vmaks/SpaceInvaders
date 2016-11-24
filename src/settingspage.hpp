#pragma once

#include <QWidget>

namespace Ui {
class SettingsPage;
}

class SettingsPage : public QWidget
{
  Q_OBJECT

public:
  explicit SettingsPage(QWidget *parent = 0);
  ~SettingsPage();

private slots:
  void on_menuButton_clicked();

  void on_saveButton_clicked();

signals:
  void moveToMenuPage();

private:
  Ui::SettingsPage *ui;
};
