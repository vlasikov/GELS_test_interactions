#include <QApplication>
#include "mainwindow.h"

#include "client.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  Client myClient;
  myClient.show();

  MainWindow w;
  w.show();
  
  return a.exec();
}


//<header>../../qcustomplot.h</header> file mainwindow.ui -- error
