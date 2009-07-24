#ifndef TERMINALPANE_H
#define TERMINALPANE_H

#include <QtGui/QWidget>
#include <QKeyEvent>

namespace Ui {
    class TerminalPane;
}

class TerminalPane : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(TerminalPane)
public:
    explicit TerminalPane(QWidget *parent = 0);
    virtual ~TerminalPane();

    void appendOutput(QString str);
    // Post: str is appended to the text edit

    void waitingForInput();
    // Post: Sets the writability of the text edit to true, and prevents previously entered text from being modified

    void clearTerminal();
    // Post: Clears the terminal

    void highlightOnFocus();
    // Post: Highlights the label based on the label window color saved in the UI file

    bool hasFocus();
    // Post: returns if the pane has focus

    void copy();
    // Post: selected text in the text edit is copied to the clipboard

    void setFont();
    // Post: the font used by the text edit is set to a font chosen in a font dialog

private:
    Ui::TerminalPane *m_ui;

    bool waiting;

    QString strokeString;
    QString retString;

    void displayTerminal();

private slots:
    void keyPressEvent(QKeyEvent *e);

signals:
    void undoAvailable(bool);
    void redoAvailable(bool);
    void inputReceived();

};

#endif // TERMINALPANE_H
