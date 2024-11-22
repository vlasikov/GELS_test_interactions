#include "point_tag.h"

point_tag::point_tag(QCPAbstractPlottable *plottable, double key, double value) :
  QObject(plottable),
  mGraph(plottable)
{

  // the arrow end (head) is set to move along with the dummy tracer by setting it as its parent
  // anchor. Its coordinate system (setCoords) is thus pixels, and this is how the needed horizontal
  // offset for the tag of the second y axis is achieved. This horizontal offset gets dynamically
  // updated in AxisTag::updatePosition. the arrow "start" is simply set to have the "end" as parent
  // anchor. It is given a horizontal offset to the right, which results in a 15 pixel long arrow.
  mArrow = new QCPItemLine(mGraph->parentPlot());
  mArrow->setLayer("axes");
  mArrow->setClipToAxisRect(true);
  QPen pen = QPen();
  pen.setColor(mGraph->pen().color());
  mArrow->setPen(pen);
  QCPLineEnding head = QCPLineEnding(QCPLineEnding::esDisc,6,6,false);
  mArrow->setHead(head);
  mArrow->end->setType(QCPItemPosition::ptPlotCoords);
  mArrow->end->setCoords(key, value);
  mArrow->start->setParentAnchor(mArrow->end);
  mArrow->start->setType(QCPItemPosition::ptAbsolute);
  mArrow->start->setCoords(20, -20);

  // The text label is anchored at the arrow start (tail) and has its "position" aligned at the
  // left, and vertically centered to the text label box.
  mLabel = new QCPItemText(mGraph->parentPlot());
  mLabel->setLayer("axes");
  mLabel->setClipToAxisRect(true);
  mLabel->setPadding(QMargins(3, 0, 3, 0));
  mLabel->setBrush(QBrush(Qt::white));
  mLabel->setPen(pen);
  mLabel->setPositionAlignment(Qt::AlignLeft|Qt::AlignVCenter);
  mLabel->position->setParentAnchor(mArrow->start);
  mLabel->setText(QString::number(value, 'f', 2));

}

point_tag::~point_tag()
{
  if (mArrow)
    mArrow->parentPlot()->removeItem(mArrow);
  if (mLabel)
    mLabel->parentPlot()->removeItem(mLabel);
}

void point_tag::setPen(const QPen &pen)
{
  mArrow->setPen(pen);
  mLabel->setPen(pen);
}

void point_tag::setBrush(const QBrush &brush)
{
  mLabel->setBrush(brush);
}

void point_tag::setText(const QString &text)
{
    mLabel->setText(text);
}

bool point_tag::isChild(QObject *item)
{
    if ( ((QCPItemLine *)item == mArrow) |
         ((QCPItemText *)item == mLabel) )
        return true;
    return false;
}
