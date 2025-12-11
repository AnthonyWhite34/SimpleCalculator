#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <limits>   // std::numeric_limits

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Single display
    if (ui->lineEdit_Output) {
        ui->lineEdit_Output->setReadOnly(true);
        ui->lineEdit_Output->setAlignment(Qt::AlignRight);
    }

    // Operations map (symbols must match setOp calls)
    ops_ = {
        { "+", [](double a, double b){ return a + b; } },
        { "-", [](double a, double b){ return a - b; } },
        { "*", [](double a, double b){ return a * b; } },
        { "÷", [](double a, double b){
            return (b == 0.0) ? std::numeric_limits<double>::quiet_NaN() : a / b;
        } }
    };

    // Initial state
    total = 0.0;
    pendingOp_.clear();
    expr_.clear();
    entry_ = "0";
    clearOnNextDigit_ = false;
    refreshDisplay();
}

MainWindow::~MainWindow() { delete ui; }

// ------------ Display helpers ------------
void MainWindow::refreshDisplay() {
    const QString shown = (expr_ + entry_).isEmpty() ? QStringLiteral("0")
                                                     : (expr_ + entry_);
    ui->lineEdit_Output->setText(shown);
}

void MainWindow::setDisplay(const QString& s) {
    QString t = s;
    normalizeNumber(t);
    ui->lineEdit_Output->setText(t);
}

void MainWindow::setDisplay(double v) {
    setDisplay(QString::number(v, 'g', 15));
}

void MainWindow::normalizeNumber(QString& s) const {
    // Trim trailing zeros after decimal: "12.3400" -> "12.34", "5." -> "5"
    if (!s.contains('.')) return;
    while (s.endsWith('0')) s.chop(1);
    if (s.endsWith('.')) s.chop(1);
    if (s.isEmpty()) s = "0";
}

// ------------ Actions ------------
void MainWindow::insertDigit(int d) {
    if (clearOnNextDigit_) { entry_ = "0"; clearOnNextDigit_ = false; }
    if (entry_ == "0") entry_.clear();
    entry_ += QString::number(d);
    refreshDisplay();
}

void MainWindow::insertDot() {
    if (clearOnNextDigit_) { entry_ = "0"; clearOnNextDigit_ = false; }
    if (!entry_.contains('.')) entry_ += '.';
    refreshDisplay();
}

void MainWindow::clearAll() {
    total = 0.0;
    pendingOp_.clear();
    expr_.clear();
    entry_ = "0";
    clearOnNextDigit_ = false;
    refreshDisplay();
}

void MainWindow::backspace() {
    if (clearOnNextDigit_) { clearOnNextDigit_ = false; entry_ = "0"; refreshDisplay(); return; }
    if (entry_.size() <= 1) entry_ = "0";
    else entry_.chop(1);
    refreshDisplay();
}

void MainWindow::toggleSign() {
    bool ok=false;
    double v = entry_.toDouble(&ok);
    if (!ok) return;
    entry_ = QString::number(-v, 'g', 15);
    refreshDisplay();
}

void MainWindow::setOp(const QString& op) {
    // If user taps an operator twice, replace the operator visually
    if (!pendingOp_.isEmpty() && entry_.isEmpty()) {
        if (!expr_.isEmpty() && expr_.endsWith(' ')) {
            // expr_ == "<lhs> <oldop> "
            expr_.chop(2);             // remove " " + old op
            expr_ += op + " ";
            pendingOp_ = op;
            refreshDisplay();
            return;
        }
    }

    // Start a new expression if no pending op
    if (pendingOp_.isEmpty()) {
        bool ok=false; double rhs = entry_.toDouble(&ok);
        if (!ok) rhs = 0.0;
        total = rhs;

        QString pretty = entry_;
        normalizeNumber(pretty);
        expr_ = pretty + " " + op + " ";
        entry_.clear();
        pendingOp_ = op;
        clearOnNextDigit_ = false;
        refreshDisplay();
        return;
    }

    // We have a pending op and a new RHS -> compute and continue
    if (!entry_.isEmpty()) {
        const double rhs = entry_.toDouble();
        applyPending(rhs);

        QString pretty = QString::number(total, 'g', 15);
        normalizeNumber(pretty);
        expr_ = pretty + " " + op + " ";
        entry_.clear();
        pendingOp_ = op;
        clearOnNextDigit_ = false;
        refreshDisplay();
    } else {
        // pressed op again without RHS; keep replacing operator
        pendingOp_ = op;
        if (!expr_.isEmpty()) {
            if (expr_.endsWith(' ')) { expr_.chop(2); expr_ += op + " "; }
        } else {
            expr_ = "0 " + op + " ";
        }
        refreshDisplay();
    }
}

void MainWindow::equals() {
    if (pendingOp_.isEmpty()) { refreshDisplay(); return; }

    const double rhs = entry_.isEmpty() ? total : entry_.toDouble();
    applyPending(rhs);

    QString right = entry_.isEmpty()
        ? QString::number(rhs, 'g', 15)
        : entry_;
    normalizeNumber(right);

    QString result = QString::number(total, 'g', 15);
    normalizeNumber(result);

    // Show full expression: "8 * 4 = 32"
    ui->lineEdit_Output->setText(expr_ + right + " = " + result);

    // Prepare for next entry; keep result as current entry
    expr_.clear();
    entry_ = result;
    pendingOp_.clear();
    clearOnNextDigit_ = true; // next digit starts a fresh number
}

void MainWindow::applyPending(double rhs) {
    if (pendingOp_.isEmpty()) { total = rhs; return; }
    auto it = ops_.find(pendingOp_);
    if (it != ops_.end()) total = it->second(total, rhs);
}

// ------------ Slots: digits ------------
void MainWindow::on_button_0_clicked(){ insertDigit(0); }
void MainWindow::on_button_1_clicked(){ insertDigit(1); }
void MainWindow::on_button_2_clicked(){ insertDigit(2); }
void MainWindow::on_button_3_clicked(){ insertDigit(3); }
void MainWindow::on_button_4_clicked(){ insertDigit(4); }
void MainWindow::on_button_5_clicked(){ insertDigit(5); }
void MainWindow::on_button_6_clicked(){ insertDigit(6); }
void MainWindow::on_button_7_clicked(){ insertDigit(7); }
void MainWindow::on_button_8_clicked(){ insertDigit(8); }
void MainWindow::on_button_9_clicked(){ insertDigit(9); }

// ------------ Slots: unary / misc ------------
void MainWindow::on_button_decimal_clicked(){ insertDot(); }
void MainWindow::on_button_C_clicked(){ clearAll(); }
void MainWindow::on_button_CE_clicked(){ clearAll(); }

// IMPORTANT: this slot name must match your UI object's objectName.
// If your button is named "button_Backspace" in Designer, rename this function to:
//   void MainWindow::on_button_Backspace_clicked(){ backspace(); }
void MainWindow::on_button_Delete_clicked(){ backspace(); }

void MainWindow::on_button_PosNeg_clicked(){ toggleSign(); }
void MainWindow::on_button_empty_clicked(){ /* no-op */ }

// ------------ Slots: ops & equals ------------
void MainWindow::on_button_Add_clicked(){ setOp("+"); }
void MainWindow::on_button_Minus_clicked(){ setOp("-"); }
void MainWindow::on_button_Multiply_clicked(){ setOp("*"); }
void MainWindow::on_button_Divide_clicked(){ setOp("÷"); }
void MainWindow::on_button_Equals_clicked(){ equals(); }
