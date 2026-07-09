#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    table = new QTableWidget(this);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    menu = menuBar();

    fileMenu = menu->addMenu(tr("&File"));
    openAction = new QAction(tr("&Open File..."), this);
    fileMenu->addAction(openAction);

    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    setCentralWidget(table);
}

MainWindow::~MainWindow() = default;

void MainWindow::loadCsv(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Hiba"), tr("Couldn't open file") + file.errorString());
        return;
    }

    QTextStream in(&file);

    table->clear();
    table->setRowCount(0);
    table->setColumnCount(0);

    if (!in.atEnd()) {
        QString headerLine = in.readLine();

        QStringList headers = headerLine.split(",");

        table->setColumnCount(headers.size());
        table->setHorizontalHeaderLabels(headers);
    }

    while (!in.atEnd()) {
        QString line = in.readLine();

        if(line.trimmed().isEmpty()) continue;

        QStringList rowData = line.split(",");

        int currentRow = table->rowCount();
        table->insertRow(currentRow);

        for (int col = 0; col < rowData.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(rowData[col]);
            table->setItem(currentRow, col, item);
        }
    }

    file.close();

    table->resizeColumnsToContents();
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open CSV File"),
        QDir::homePath(),
        tr("CSV Files (*.csv);;All Files (*)")
        );

    if (!fileName.isEmpty()){
        loadCsv(fileName);
    }

}



