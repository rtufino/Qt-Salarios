#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->cmdCalcular, SIGNAL(released()),
            this, SLOT(calcular()));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::calcular()
{
    // obtener datos
    QString nombre = ui->inNombre->text();
    int horas = ui->inHoras->value();

    float const HORA_EXTRA = 20.10;

    // Calcular horas extra
    int extra = 0;
    if (horas > 40){
        extra = horas - 40;
        horas = 40;
    }

    // Calcular el salario
    float salario = 0;
    if (ui->inMatutina->isChecked()){
        salario = horas * 5.15 + extra * HORA_EXTRA;
    }else if (ui->inVespertina->isChecked()){
        salario = horas * 8.50 + extra * HORA_EXTRA;
    }else{
        salario = horas * 12.65 + extra * HORA_EXTRA;
    }

    // Calcular el descuento
    float descuento = salario * 9.5 / 100;
    float salario_neto = salario - descuento;

    // Imprimir resultados
    QString resultado = "\nObrero: " + nombre + "\n";
    resultado += "Salario: $" + QString::number(salario) + "\n";
    resultado += "Descuento (9.5%): $" + QString::number(descuento) + "\n";
    resultado += "Salario neto: $" + QString::number(salario_neto) + "\n";
    resultado += "--\n";

    ui->outResultado->appendPlainText(resultado);
}

