#include "dragTextEdit.h"



DragTextEdit::DragTextEdit(QWidget *parent) : QTextEdit(parent)
{

    setAcceptDrops(true);

}



void DragTextEdit::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasText()) {
        QTextStream out(stdout);
        QFile file(mimeData->urls().at(0).path());
        file.open(QFile::ReadOnly | QFile::Text);
        QString contents = file.readAll();
        setText(contents);
        event->acceptProposedAction();
    }
    else{
        event->ignore();
    }


}

void DragTextEdit::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}


void DragTextEdit::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void DragTextEdit::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}