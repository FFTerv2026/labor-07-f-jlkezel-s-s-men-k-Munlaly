#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QStringList>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
private:
    QPushButton *btn;
    QLabel *quoteLbl;
    QStringList quotes;
    int lastQuoteIdx;
};
#endif // MAINWINDOW_H
