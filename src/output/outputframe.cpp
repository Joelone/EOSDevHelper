#include "outputframe.h"
#include "ui_outputframe.h"

#include <QJsonDocument>

OutputFrame::OutputFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OutputFrame)
{
    ui->setupUi(this);
}

OutputFrame::~OutputFrame()
{
    delete ui;
}

void OutputFrame::setRequestOutput(int index, const QString &title, const QByteArray &data)
{
    if (index >= 4) {
        return;
    }

    QLabel *labeltitle = nullptr;
    QTextEdit *textEdit = nullptr;

    switch (index) {
    case 0:
        labeltitle = ui->labelTitle_1;
        textEdit = ui->textEditRequest_1;
        break;

    case 1:
        labeltitle = ui->labelTitle_2;
        textEdit = ui->textEditRequest_2;
        break;

    case 2:
        labeltitle = ui->labelTitle_3;
        textEdit = ui->textEditRequest_3;
        break;

    case 3:
        labeltitle = ui->labelTitle_4;
        textEdit = ui->textEditRequest_4;
        break;

    default:
        break;
    }

    if (labeltitle == nullptr || textEdit == nullptr) {
        return;
    }

    labeltitle->setText(title);

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QByteArray formatData = doc.toJson(QJsonDocument::Indented);
    textEdit->setText(QString::fromStdString(formatData.toStdString()));
}

void OutputFrame::setResponseOutput(int index, const QByteArray &data)
{
    if (index >= 4) {
        return;
    }

    QTextEdit *textEdit = nullptr;

    switch (index) {
    case 0:
        textEdit = ui->textEditResponse_1;
        break;

    case 1:
        textEdit = ui->textEditResponse_2;
        break;

    case 2:
        textEdit = ui->textEditResponse_3;
        break;

    case 3:
        textEdit = ui->textEditResponse_4;
        break;

    default:
        break;
    }

    if (textEdit == nullptr) {
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QByteArray formatData = doc.toJson(QJsonDocument::Indented);
    textEdit->setText(QString::fromStdString(formatData.toStdString()));
}
