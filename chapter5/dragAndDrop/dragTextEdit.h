#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QMoveEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QDateTime>
#include <QTextEdit>
#include <QMimeData>
#include <QMimeDatabase>
#include <QMimeType>

class DragTextEdit: public QTextEdit
{
    Q_OBJECT

    public:
        explicit DragTextEdit(QWidget *parent = nullptr);

    protected:
        void dragEnterEvent(QDragEnterEvent *event) override;
        void dragMoveEvent(QDragMoveEvent *event) override;
        void dragLeaveEvent(QDragLeaveEvent *event) override;
        void dropEvent(QDropEvent *event) override;

};
#endif