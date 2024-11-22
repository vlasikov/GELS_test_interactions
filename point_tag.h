#ifndef POINT_TAG_H
#define POINT_TAG_H

#include <QObject>
#include "qcustomplot.h"

class point_tag : public QObject
{
    Q_OBJECT
  public:
    explicit point_tag(QCPAbstractPlottable *plottable, double key, double value);
    virtual ~point_tag();

    // setters:
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setText(const QString &text);

    // getters:
    QPen pen() const { return mLabel->pen(); }
    QBrush brush() const { return mLabel->brush(); }
    QString text() const { return mLabel->text(); }

    // other methods:
    bool isChild(QObject *item);

  protected:
    QCPAbstractPlottable *mGraph;
    QPointer<QCPItemLine> mArrow;
    QPointer<QCPItemText> mLabel;
};

#endif // POINT_TAG_H
