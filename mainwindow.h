#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "qcustomplot.h"
#include "point_tag.h"
#include <QList>
#include <QVector>
#include <QDateTime>

#include "client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
public slots:
  void addPoints(QVector<double> *VectTime, QVector<double> *vect, QVector<double> *vectX);

private slots:
  void titleDoubleClick(QMouseEvent *event);
  void axisLabelDoubleClick(QCPAxis* axis, QCPAxis::SelectablePart part);
  void legendDoubleClick(QCPLegend* legend, QCPAbstractLegendItem* item);
  void selectionChanged();
  void mousePress();
  void mouseWheel();
  void addRandomGraph();
  void addMainGraph();
  void removeSelectedGraph();
  void removeAllGraphs();
  void contextMenuRequest(QPoint pos);
  void moveLegend();
  void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);
  void legendSelectChanged(QCPLegend::SelectableParts parts);
  void itemClicked(QCPAbstractItem *item, QMouseEvent *event);

private:
  Ui::MainWindow *ui;
  QPointer<point_tag> pt[10];
  int pt_ptr = 0;
  Client *myTcpClient;
};

#endif // MAINWINDOW_H
