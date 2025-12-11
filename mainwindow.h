#pragma once
#include <QMainWindow>
#include <functional>
#include <unordered_map>
#include <expected>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui = nullptr;

    using Op = std::function<double(double,double)>;
    std::unordered_map<QString, Op> ops_;

    // Calculator state
    double  total = 0.0;           // accumulator
    QString pendingOp_;            // "+", "-", "*", "÷"
    bool    clearOnNextDigit_ = false;

    // Expression-building state
    QString expr_;                 // e.g., "8 * "
    QString entry_;                // e.g., "4"

    // Display helpers
    void    refreshDisplay();                    // shows expr_ + entry_
    void    setDisplay(const QString& s);        // direct set (normalizes number)
    void    setDisplay(double v);
    void    normalizeNumber(QString& s) const;

    // Actions
    void insertDigit(int d);
    void insertDot();
    void clearAll();
    void backspace();
    void toggleSign();
    void setOp(const QString& op);
    void equals();
    void applyPending(double rhs);

private slots:
    // Digits
    void on_button_0_clicked();
    void on_button_1_clicked();
    void on_button_2_clicked();
    void on_button_3_clicked();
    void on_button_4_clicked();
    void on_button_5_clicked();
    void on_button_6_clicked();
    void on_button_7_clicked();
    void on_button_8_clicked();
    void on_button_9_clicked();

    // Unary / misc
    void on_button_decimal_clicked();
    void on_button_C_clicked();
    void on_button_CE_clicked();
    void on_button_Delete_clicked();     // backspace (objectName must match)
    // If your UI uses button_Backspace instead, rename slot accordingly.

    void on_button_PosNeg_clicked();
    void on_button_empty_clicked();

    // Binary ops
    void on_button_Add_clicked();
    void on_button_Minus_clicked();
    void on_button_Multiply_clicked();
    void on_button_Divide_clicked();

    // Equals
    void on_button_Equals_clicked();
};
