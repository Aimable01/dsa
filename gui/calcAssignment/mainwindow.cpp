#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QStack>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect digit buttons to the onDigitPressed slot
    connect(ui->btn0, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->btn1, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->btn2, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->btn3, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->btn4, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->btn5, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->btn6, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->btn7, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->btn8, SIGNAL(clicked()), this, SLOT(onDigitPressed()));
    connect(ui->btn9, SIGNAL(clicked()), this, SLOT(onDigitPressed()));

    // Connect operator buttons
    connect(ui->addBtn, SIGNAL(clicked()), this, SLOT(onOperatorPressed()));
    connect(ui->subBtn, SIGNAL(clicked()), this, SLOT(onOperatorPressed()));
    connect(ui->multBtn, SIGNAL(clicked()), this, SLOT(onOperatorPressed()));
    connect(ui->divBtn, SIGNAL(clicked()), this, SLOT(onOperatorPressed()));

    // Connect equals and clear buttons
    connect(ui->eqBtn, SIGNAL(clicked()), this, SLOT(onEqualPressed()));
    connect(ui->clearBtn, SIGNAL(clicked()), this, SLOT(onClearPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot to handle digit button clicks
void MainWindow::onDigitPressed()
{
    QPushButton *button = (QPushButton*)sender();
    QString digitValue = button->text();
    currentExpression += digitValue;
    ui->txtResult->setText(currentExpression);
}

// Slot to handle operator button clicks
void MainWindow::onOperatorPressed()
{
    QPushButton *button = (QPushButton*)sender();
    QString operatorValue = button->text();
    currentExpression += " " + operatorValue + " ";
    ui->txtResult->setText(currentExpression);
}

// Slot to handle the equals button click
void MainWindow::onEqualPressed()
{
    // Simple expression evaluation logic
    QStack<QString> operands;
    QStack<QString> operators;
    QStringList tokens = currentExpression.split(" ");

    // Parse the expression
    for (const QString &token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            operators.push(token);
        } else {
            operands.push(token);
        }
    }

    // Perform calculations (left-to-right for simplicity)
    while (!operators.isEmpty()) {
        QString op = operators.pop();
        double operand2 = operands.pop().toDouble();
        double operand1 = operands.pop().toDouble();
        double result = 0;

        if (op == "+") result = operand1 + operand2;
        else if (op == "-") result = operand1 - operand2;
        else if (op == "*") result = operand1 * operand2;
        else if (op == "/") result = operand1 / operand2;

        operands.push(QString::number(result));
    }

    // Display the result
    ui->txtResult->setText(operands.pop());
    currentExpression.clear();
}

// Slot to handle clear button click
void MainWindow::onClearPressed()
{
    currentExpression.clear();
    ui->txtResult->clear();
}
