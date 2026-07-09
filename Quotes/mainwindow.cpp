#include "mainwindow.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* window = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(window);

    this ->quoteLbl = new QLabel(window);
    this->quoteLbl->setAlignment(Qt::AlignCenter);
    this->btn =  new QPushButton("New quote",window);

    layout->addWidget(this->quoteLbl);
    layout->addWidget(this->btn);

    this->setCentralWidget(window);

    this->quotes = QStringList();
    this->lastQuoteIdx = -1;

    QFile file(":/quotes.txt");

    if (! file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this, "Error", "Couldn't open qoutes file!");

    }
    else{
        QTextStream in(&file);

        while(! in.atEnd()){
            QString line = in.readLine().trimmed();
            if (!line.isEmpty()) {
                this->quotes.append(line);
            }
        }
    }

    file.close();

    connect(this->btn, &QPushButton::clicked, [this](){
        int randomIdx = QRandomGenerator::global()->bounded(0, this->quotes.size());
        while(randomIdx == lastQuoteIdx){
            randomIdx = QRandomGenerator::global()->bounded(0, this->quotes.size());
        }

        lastQuoteIdx = randomIdx;
        this->quoteLbl->setText(this->quotes.at(randomIdx));

    });

    window->setObjectName("centralWidget");

    QFile stylesheet(":/style.qss");
    if (stylesheet.open(QIODevice::ReadOnly)){
        this->setStyleSheet(stylesheet.readAll());
    }
}


MainWindow::~MainWindow() = default;
