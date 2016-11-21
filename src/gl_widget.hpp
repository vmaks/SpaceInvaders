#pragma once

#include <QGLWidget>
#include <QOpenGLFunctions>
#include <QTime>
#include "textured_rect.hpp"

#include <array>

class MainWindow;

double constexpr PI = 3.14159265;

QT_FORWARD_DECLARE_CLASS(QOpenGLTexture)
QT_FORWARD_DECLARE_CLASS(QOpenGLShader)
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLWidget : public QGLWidget, protected QOpenGLFunctions
{
  Q_OBJECT
public:
  GLWidget(MainWindow * mw, QColor const & background);
  ~GLWidget();

protected:
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void initializeGL() override;

  void Update(float elapsedSeconds);
  void Render();
  void RenderStar(float blend);
  void mousePressEvent(QMouseEvent * e) override;
  void mouseDoubleClickEvent(QMouseEvent * e) override;
  void mouseMoveEvent(QMouseEvent * e) override;
  void mouseReleaseEvent(QMouseEvent * e) override;
  void wheelEvent(QWheelEvent * e) override;
  void keyPressEvent(QKeyEvent * e) override;
  void keyReleaseEvent(QKeyEvent * e) override;

private:
  int L2D(int px) const { return px * devicePixelRatio(); }

  MainWindow * m_mainWindow;

  unsigned int m_frames = 0;
  QTime m_time;
  QColor m_background;
  QSize m_screenSize;


  /// m_period is a value between 0.0 and 1.0 .
  /// It as a period.
  float m_period = 0.0f;
  std::vector<float> m_random = {0.2f, 0.5f, 0.7f};

  QOpenGLTexture * m_texture = nullptr;
  TexturedRect * m_texturedRect = nullptr;
//  QOpenGLTexture * m_textureStar = nullptr;
  QVector2D m_position = QVector2D(200, 200);
  std::array<bool, 4> m_directions = {{ false, false, false, false }};
};
