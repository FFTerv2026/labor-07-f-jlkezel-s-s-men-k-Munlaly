#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QMenu>
#include <QFileDialog>
#include <QMenuBar>
#include <QAction>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>
#include <QHeaderView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    QMenuBar * menu;
    QMenu *fileMenu;
    QAction *openAction;
    QTableWidget *table;

    void loadCsv(const QString &fileName);

private slots:
    void openFile();

};
#endif // MAINWINDOW_H
