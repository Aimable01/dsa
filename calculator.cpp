#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>

class Calculator : public QWidget {
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void onNumberPressed();
    void onOperatorPressed();
    void onEqualPressed();
    void onClearPressed();

private:
    QLineEdit *display;
    double firstOperand;
    QString pendingOperator;
    bool waitingForSecondOperand;
};

Calculator::Calculator(QWidget *parent)
    : QWidget(parent), firstOperand(0), waitingForSecondOperand(false) {
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);

    QGridLayout *mainLayout = new QGridLayout;

    // Number buttons
    for (int i = 0; i < 10; ++i) {
        QPushButton *button = new QPushButton(QString::number(i));
        connect(button, &QPushButton::clicked, this, &Calculator::onNumberPressed);
        mainLayout->addWidget(button, i / 3 + 2, i % 3);
    }

    // Operator buttons
    QString operators[4] = {"+", "-", "*", "/"};
    for (int i = 0; i < 4; ++i) {
        QPushButton *button = new QPushButton(operators[i]);
        connect(button, &QPushButton::clicked, this, &Calculator::onOperatorPressed);
        mainLayout->addWidget(button, i + 2, 3);
    }

    // Clear and Equal buttons
    QPushButton *clearButton = new QPushButton("C");
    connect(clearButton, &QPushButton::clicked, this, &Calculator::onClearPressed);
    mainLayout->addWidget(clearButton, 1, 0);

    QPushButton *equalButton = new QPushButton("=");
    connect(equalButton, &QPushButton::clicked, this, &Calculator::onEqualPressed);
    mainLayout->addWidget(equalButton, 1, 3);

    mainLayout->addWidget(display, 0, 0, 1, 4);

    setLayout(mainLayout);
}

void Calculator::onNumberPressed() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    if (display->text() == "0" || waitingForSecondOperand) {
        display->clear();
        waitingForSecondOperand = false;
    }
    display->setText(display->text() + button->text());
}

void Calculator::onOperatorPressed() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString operatorSymbol = button->text();
    double displayValue = display->text().toDouble();

    if (!pendingOperator.isEmpty() && !waitingForSecondOperand) {
        onEqualPressed();
    }

    firstOperand = displayValue;
    pendingOperator = operatorSymbol;
    waitingForSecondOperand = true;
}

void Calculator::onEqualPressed() {
    double secondOperand = display->text().toDouble();
    double result = 0;

    if (pendingOperator == "+") {
        result = firstOperand + secondOperand;
    } else if (pendingOperator == "-") {
        result = firstOperand - secondOperand;
    } else if (pendingOperator == "*") {
        result = firstOperand * secondOperand;
    } else if (pendingOperator == "/" && secondOperand != 0) {
        result = firstOperand / secondOperand;
    } else {
        display->setText("Error");
        return;
    }

    display->setText(QString::number(result));
    pendingOperator.clear();
    waitingForSecondOperand = true;
}

void Calculator::onClearPressed() {
    display->setText("0");
    firstOperand = 0;
    pendingOperator.clear();
    waitingForSecondOperand = false;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Calculator calculator;
    calculator.setWindowTitle("Calculator");
    calculator.resize(250, 200);
    calculator.show();
    return app.exec();
}

#include "main.moc"
