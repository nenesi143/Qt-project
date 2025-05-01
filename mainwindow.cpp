#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDate>
#include <QStandardPaths>
#include <QInputDialog>
#include <QMap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"Студент", "Группа", "Курс", "Лабораторная", "Дата сдачи", "Оценка"});

    ui->tableWidget->setColumnWidth(0, 200);
    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget->setColumnWidth(2, 150);
    ui->tableWidget->setColumnWidth(3, 180);
    ui->tableWidget->setColumnWidth(4, 85);
    ui->tableWidget->setColumnWidth(5, 80);

    chartView = new QChartView(this);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setVisible(false);

        ui->verticalLayout_2->insertWidget(1, chartView);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addLabwork_clicked()
{
    if (recordcount >= MAXRECORDS){
        QMessageBox::warning(this, "Ошибка", "Достигнуто максимальное количество записей!");
        return;
    }

    QDialog dialog(this);
    QFormLayout form(&dialog);

    QLineEdit *studentEdit = new QLineEdit(&dialog);
    QLineEdit *groupnumEdit = new QLineEdit(&dialog);
    QLineEdit *namecourseEdit = new QLineEdit(&dialog);
    QLineEdit *namelabworkEdit = new QLineEdit(&dialog);

    QDateEdit *deadlineEdit = new QDateEdit(QDate::currentDate(), &dialog);
    deadlineEdit->setCalendarPopup(true);
    deadlineEdit->setDisplayFormat("dd.MM.yyyy");

    QDateEdit *issueDateEdit = new QDateEdit(QDate::currentDate(), &dialog);
    issueDateEdit->setCalendarPopup(true);
    issueDateEdit->setDisplayFormat("dd.MM.yyyy");

    QSpinBox *gradeEdit = new QSpinBox(&dialog);
    gradeEdit->setRange(2, 5);
    gradeEdit->setValue(3);

    form.addRow("Студент:", studentEdit);
    form.addRow("Номер группы:", groupnumEdit);
    form.addRow("Название курса:", namecourseEdit);
    form.addRow("Название лабораторной:", namelabworkEdit);
    form.addRow("Дата сдачи:", deadlineEdit);
    form.addRow("Дата выдачи:", issueDateEdit);
    form.addRow("Оценка:", gradeEdit);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);

    QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() != QDialog::Accepted)
        return;

    if (studentEdit->text().isEmpty() || groupnumEdit->text().isEmpty() ||
        namecourseEdit->text().isEmpty() || namelabworkEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните все обязательные поля!");
        return;
    }

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(studentEdit->text()));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(groupnumEdit->text()));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(namecourseEdit->text()));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(namelabworkEdit->text()));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(deadlineEdit->date().toString("dd.MM.yyyy")));
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(gradeEdit->value())));
    ui->tableWidget->setItem(row, 6, new QTableWidgetItem(issueDateEdit->date().toString("dd.MM.yyyy")));

    recordcount++;
}

void MainWindow::on_ImportButton_clicked(){

    QString FileName = QFileDialog::getOpenFileName(this, "Выберите файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");

        if (FileName.isEmpty()) {
            return;
        }

        QFile file(FileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл!");
            return;
        }

        QTextStream in(&file);
        in.setCodec("UTF-8");

        ui->tableWidget->setRowCount(0);

        QStringList record;

        while (!in.atEnd()){
            QString line = in.readLine().trimmed();
            if (!line.isEmpty()){
                record << line;
            }

            if (record.size() == 6){

                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);

                ui->tableWidget->setItem(row, 0, new QTableWidgetItem(record[0]));
                ui->tableWidget->setItem(row, 1, new QTableWidgetItem(record[1]));
                ui->tableWidget->setItem(row, 2, new QTableWidgetItem(record[2]));
                ui->tableWidget->setItem(row, 3, new QTableWidgetItem(record[3]));
                ui->tableWidget->setItem(row, 4, new QTableWidgetItem(record[4]));
                ui->tableWidget->setItem(row, 5, new QTableWidgetItem(record[5]));

                recordcount++;
                record.clear();
            }
        }

        file.close();

        if (!record.isEmpty()){
            QMessageBox::warning(this, "Ошибка", "Запись неполная");
            return;
        }
}

void MainWindow::on_DeleteRecord_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей для удаления!");
        return;
    }
    int index = QInputDialog::getInt(this, "Удаление записи", "Индекс");

    if (index < 1 or index > ui->tableWidget->rowCount()){
        QMessageBox::warning(this, "Ошибка", "Неверный индекс!");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(
            this,
            "Подтверждение действия",
            QString("Вы точно хотите удалить запись №%1?").arg(index),
            QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::No){
        return;
    }

    else{
        ui->tableWidget->removeRow(index - 1);
        recordcount--;
    }
}


void MainWindow::on_ExportButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Экспорт данных","Введите название файла с указанитем типа файла");

    if (filename.isEmpty()){
        return;
    }

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Ошибка", "Не удалось создать файл!");
        return;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");

    int column = ui->tableWidget->columnCount();

    for (int row = 0; row < ui->tableWidget->rowCount(); row++){
        for (int col = 0; col < column; col++){
            out << ui->tableWidget->item(row, col)->text() << endl;
        }
    }

    file.close();
    QMessageBox::information(this, "Успех", "Данные экспортированы в файл!");
}

void MainWindow::on_DeleteRecord_2_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей для удаления!");
        return;
    }

    QString FNS = QInputDialog::getText(this, "Добавление записи", "Студент:", QLineEdit::Normal, "").trimmed();

    if (FNS.isEmpty()){
        QMessageBox::warning(this, "Ошибка", "Введите ФИО для удаления");
        return;
    }

    QMessageBox::StandardButton reply1 = QMessageBox::question(this, "Подтверждение", QString("Удалить все записи для '%1'?").arg(FNS), QMessageBox::Yes | QMessageBox::No);

    if (reply1 != QMessageBox::Yes){
        return;
    }

    int deletedrecord = 0;

    for (int row = ui->tableWidget->rowCount() - 1; row >= 0; row--){
        QTableWidgetItem *nameItem = ui->tableWidget->item(row, 0);

        if (nameItem and nameItem->text() == FNS){
            ui->tableWidget->removeRow(row);
            deletedrecord++;
        }
    }

    recordcount -= deletedrecord;

    if (deletedrecord > 0){
        QMessageBox::information(this, "Успех", QString("Удалено %1 записей").arg(deletedrecord));
    }

    else{
        QMessageBox::warning(this, "Ошибка", QString("Нет записей с таким ФИО"));
    }
}

void MainWindow::on_EditRecord_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей для изменения оценки!");
        return;
    }

    int index = QInputDialog::getInt(this, "Изменение записи", QString("Введите индекс").arg(recordcount), 1, 1, recordcount, 1);
    int newGrade = QInputDialog::getInt(this, "Изменение оценки", "Оценка", 1, 2, 5, 1);

    int row = index - 1;
    if (row < 0 or row > ui->tableWidget->rowCount()){
        QMessageBox::warning(this, "Ошибка", "Неверный индекс!");
        return;
    }

    QTableWidgetItem *gradeItem = ui->tableWidget->item(row, 5);
    if (gradeItem){
        gradeItem->setText(QString::number(newGrade));
    }

    QMessageBox::information(this, "Успех", "Оценка успешно изменена!");
}


void MainWindow::on_newColumn_clicked()
{
    int newColumnIndex = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(newColumnIndex);
    ui->tableWidget->setHorizontalHeaderItem(newColumnIndex, new QTableWidgetItem("Дата выдачи"));
    ui->tableWidget->setColumnWidth(newColumnIndex, 85);

    for (int row = 0; row < ui->tableWidget->rowCount(); row++){
        QDialog dialog(this);
        QFormLayout form(&dialog);

        QDateEdit *dateEdit = new QDateEdit(QDate::currentDate(), &dialog);
        dateEdit->setCalendarPopup(true);
        dateEdit->setDisplayFormat("dd.MM.yyyy");

        form.addRow("Дата выдачи для студента " + ui->tableWidget->item(row, 0)->text() + ":", dateEdit);

        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                   Qt::Horizontal, &dialog);
        form.addRow(&buttonBox);

        QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
        QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

        if (dialog.exec() == QDialog::Accepted) {
            ui->tableWidget->setItem(row, newColumnIndex,
                                   new QTableWidgetItem(dateEdit->date().toString("dd.MM.yyyy")));
        }
    }
}

void MainWindow::on_Request1_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей осуществление запроса!");
        return;
    }

    int countRecords = 0;
    QString student = QInputDialog::getText(this, "Сколько студент сдал лабораторных работ", "Введите студента", QLineEdit::Normal);

    if (student.isEmpty()){
        QMessageBox::warning(this, "Ошибка", "Поле студента пустое");
        return;
    }

    for (int row = 0; row < ui->tableWidget->rowCount(); row++){
        QTableWidgetItem *labwork = ui->tableWidget->item(row, 0);
        if (labwork and labwork->text() == student){
            countRecords++;
        }
    }

    QMessageBox::information(this, "Сколько студент сдал лабораторных работ", QString("Студент %1 сдал %2 лабораторных работ").arg(student).arg(countRecords));
}

void MainWindow::on_Request2_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей осуществление запроса!");
        return;
    }

    int countRecords = 0;
    QString groupname = QInputDialog::getText(this, "Название группы", "Введите название группы", QLineEdit::Normal);

    if (groupname.isEmpty()){
        QMessageBox::warning(this, "Ошибка", "Поле группы пустое");
        return;
    }

    QDate currentdate = QDate::currentDate();
    QDate lastMonthDate = currentdate.addDays(-30);

    for (int row = 0; row < ui->tableWidget->rowCount(); row++){
        QTableWidgetItem *labwork = ui->tableWidget->item(row, 1);
        QTableWidgetItem *dateItem = ui->tableWidget->item(row, 4);

        if (dateItem && labwork && labwork->text() == groupname){
            QDate submissionDate = QDate::fromString(dateItem->text(), "dd.MM.yyyy");

            if (!submissionDate.isValid()) {
                QMessageBox::warning(this, "Ошибка",
                                   QString("Некорректная дата в строке %1").arg(row+1));
                continue;
            }

            if (submissionDate >= lastMonthDate && submissionDate <= currentdate){
                countRecords++;
            }
        }
    }

    QMessageBox::information(this, "Сколько лабораторных работ сдано группй", QString("Группой сдано %1 работ").arg(countRecords));
}


void MainWindow::on_Request3_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей осуществление запроса!");
        return;
    }

    struct student{
        QString studentName;
        QString nameCourse;
        QString nameLab;
        int grade;
    };

    QMap<QString, QList<student>> studentRecords;

    for (int row = 0; row < ui->tableWidget->rowCount(); row++){
        QTableWidgetItem* name = ui->tableWidget->item(row, 0);
        QTableWidgetItem* course = ui->tableWidget->item(row, 2);
        QTableWidgetItem* lab = ui->tableWidget->item(row, 3);
        QTableWidgetItem* grade = ui->tableWidget->item(row, 5);
        QTableWidgetItem* date = ui->tableWidget->item(row, 4);

        if (name and course and lab and grade and date){
            QString key = name->text() + "|" + date->text();
            student record{
                name->text(),
                course->text(),
                lab->text(),
                grade->text().toInt()
            };
            studentRecords[key].append(record);
        }
    }

    QStringList report;
    for (auto temp = studentRecords.begin(); temp != studentRecords.end(); temp++){
        if (temp.value().size() >= 2){
            QStringList parts = temp.key().split("|");
            QString student = parts[0];
            QString date = parts[1];

            report << QString("\n Студент: %1 | Дата: %2").arg(student).arg(date);

            for (auto record : temp.value()){
                report << QString("\n Курс: %1 | Название лабораторной работы: %2 | Оценка: %3").arg(record.nameCourse).arg(record.nameLab).arg(record.grade);
            }

            report << QString("Всего работ сдано %1").arg(temp.value().size());
        }
    }

    if (report.empty()){
        QMessageBox::information(this, "Результат", "Нет студентов, сдавших больше двух работ за день!");
    }
    else{
        QMessageBox::information(this, "Результат", "Студенты, сдавшие больше двух работ: " + report.join("\n"));
    }
}


void MainWindow::on_Request4_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей осуществление запроса!");
        return;
    }

    QString nameCourse = QInputDialog::getText(this, "Поиск студентов", "Введите название курса", QLineEdit::Normal);

    if (nameCourse.isEmpty()){
        QMessageBox::warning(this, "Ошибка", "Поле названия курса пустое!");
        return;
    }

    QStringList report;

    report << QString("Студенты, сдавшие курс %1 на оценку 4 или 5: ").arg(nameCourse);

    for (int row = 0; row < ui->tableWidget->rowCount(); row++){
        QTableWidgetItem* course = ui->tableWidget->item(row, 2);
        QTableWidgetItem* grades = ui->tableWidget->item(row, 5);

        if (course and grades){
            bool rep;
            int grade = grades->text().toInt(&rep);

            if (rep and (grade == 4 or grade == 5) and course->text() == nameCourse){
                QTableWidgetItem* name = ui->tableWidget->item(row, 0);
                QTableWidgetItem* group = ui->tableWidget->item(row, 1);
                QTableWidgetItem* lab = ui->tableWidget->item(row, 3);

                if (name and group and lab){
                    report << QString("%1 | Группа %2 | Название лабораторной работы %3 | Оценка %4").arg(name->text()).arg(group->text()).arg(lab->text()).arg(grade);
                }
            }
        }
    }

    if (report.size() == 1){
        QMessageBox::information(this, "Результат", "Нет студентов, сдавших курс на 4 и 5");
    }
    else{
        QMessageBox::information(this, "Результат", report.join("\n"));
    }
}

void MainWindow::on_Request5_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей осуществление запроса!");
        return;
    }

    QDate currentDate = QDate::currentDate();
    QDate twoMountAgo = currentDate.addMonths(-2);

    QStringList report;

    report << QString("Студенты, не сдавшие работы, выданные с %1 по %2: ").arg(twoMountAgo.toString("dd.MM.yyyy")).arg(currentDate.toString("dd.MM.yyyy"));

    for (int row = 0; row < ui->tableWidget->rowCount(); row++){
        QTableWidgetItem* issueDateItem = ui->tableWidget->item(row, 6);
        QTableWidgetItem* submissionDateItem = ui->tableWidget->item(row, 4);
        QTableWidgetItem* name = ui->tableWidget->item(row, 0);
        QTableWidgetItem* group = ui->tableWidget->item(row, 1);
        QTableWidgetItem* nameCourse = ui->tableWidget->item(row, 2);
        QTableWidgetItem* labWork = ui->tableWidget->item(row, 3);

        if (!issueDateItem){
            QMessageBox::information(this, "Внимание", "В таблице пропущен столбец даты выдачи");
            return;
        }

        if (!name or !group or !nameCourse or !labWork){
            QMessageBox::information(this, "Внимание", "Строка пропущена, в ней не хватает данных");
            continue;
        }

        QDate issueDate = QDate::fromString(issueDateItem->text(), "dd.MM.yyyy");

        if (!issueDate.isValid() or issueDate < twoMountAgo or issueDate > currentDate){
            continue;
        }

        QDate submissionDate = QDate::fromString(submissionDateItem->text(), "dd.MM.yyyy");
        if (!submissionDate.isValid()){
            report << QString("%1 группы %2 курса %3 не сдал лабораторную работу под названием %5 в срок с %6 по %7").arg(name->text()).arg(group->text()).arg(nameCourse->text()).arg(labWork->text()).arg(issueDateItem->text()).arg(submissionDateItem->text());
        }
    }

    if (report.size() == 1){
        QMessageBox::information(this, "Результат", "Все работы за указанный период сданы!");
    }
    else{
        QMessageBox::information(this, "Результат", report.join("\n"));
    }
}


void MainWindow::on_Request2_2_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей осуществление запроса!");
        return;
    }

    QString nameStudent;
    QString nameLabwork;
    int maxDays = 0;

    for (int row = 0; row < ui->tableWidget->rowCount(); row++){
        QTableWidgetItem* name = ui->tableWidget->item(row, 0);
        QTableWidgetItem* labwork = ui->tableWidget->item(row, 3);
        QTableWidgetItem* dates = ui->tableWidget->item(row, 4);
        QTableWidgetItem* issueDate = ui->tableWidget->item(row, 6);

        if (!name or !labwork or !dates or !issueDate){
            continue;
        }

        QDate date = QDate::fromString(dates->text(), "dd.MM.yyyy");
        QDate isDate = QDate::fromString(issueDate->text(), "dd.MM.yyyy");

        if (!date.isValid() or !isDate.isValid()){
            continue;
        }

        int differentDays = abs(isDate.daysTo(date));

        if (differentDays > maxDays){
            maxDays = differentDays;
            nameStudent = name->text();
            nameLabwork = labwork->text();
        }
    }

    if (maxDays != 0){
        QMessageBox::information(this, "Результат", (QString("Студент %1 сдавал лабораторную работу под названием %2 сдавал %3 дней").arg(nameStudent).arg(nameLabwork).arg(maxDays)));
    }
    else {
        QMessageBox::information(this, "Результат", "Нет данных для анализа");
    }
}


void MainWindow::on_Diagram1_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей построения диаграммы!");
        return;
    }

    if (chartView->isVisible()) {
            chartView->setVisible(false);
            ui->tableWidget->setVisible(true);
            return;
        }

    QString selectedCourse = QInputDialog::getText(this, "Выбор", "Введите имя курса", QLineEdit::Normal);

    if (selectedCourse.isEmpty()){
        QMessageBox::warning(this, "Ошибка", "Введите имя курса!");
        return;
    }

    int totalLabs = 0;
    int courseLabs = 0;

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        totalLabs++;
        if (ui->tableWidget->item(row, 2)->text() == selectedCourse) {
            courseLabs++;
        }
    }

    QPieSeries *series = new QPieSeries();

    QPieSlice *courseSlice = series->append(selectedCourse, courseLabs);
    courseSlice->setExploded(true);
    courseSlice->setLabelVisible(true);

    if (totalLabs > courseLabs) {
        QPieSlice *otherSlice = series->append("Остальные работы", totalLabs - courseLabs);
        otherSlice->setLabelVisible(true);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(QString("Доля работ по курсу %1\n%2 из %3 (%4%)")
                   .arg(selectedCourse)
                   .arg(courseLabs)
                   .arg(totalLabs)
                   .arg(100.0 * courseLabs / totalLabs, 0, 'f', 1));

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    chartView->setChart(chart);
    chartView->setVisible(true);
    ui->tableWidget->setVisible(false);
}

void MainWindow::on_Diagram2_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей построения диаграммы!");
        return;
    }

    if (chartView->isVisible()) {
        chartView->setVisible(false);
        ui->tableWidget->setVisible(true);
        return;
    }

    QMap<QString, int> groupCounts;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *groupItem = ui->tableWidget->item(row, 1);
        if (groupItem && !groupItem->text().isEmpty()) {
            groupCounts[groupItem->text()]++;
        }
    }

    if (groupCounts.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Нет данных о группах!");
        return;
    }

    QPieSeries *series = new QPieSeries();

    for (auto it = groupCounts.begin(); it != groupCounts.end(); ++it) {
        QPieSlice *slice = series->append(it.key(), it.value());
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1 (%2 работ)").arg(it.key()).arg(it.value()));
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Распределение работ по группам");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    chartView->setChart(chart);
    chartView->setVisible(true);
    ui->tableWidget->setVisible(false);
}

void MainWindow::on_graphic_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей построения диаграммы!");
        return;
    }
    if (chartView->isVisible()) {
        chartView->setVisible(false);
        ui->tableWidget->setVisible(true);
        return;
    }

    QMap<QString, int> groupDebtCounts;
    QDate currentDate = QDate::currentDate();
    QDate monthAgo = currentDate.addMonths(-1);

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem* groupItem = ui->tableWidget->item(row, 1);
        QTableWidgetItem* dateItem = ui->tableWidget->item(row, 4);

        if (groupItem && dateItem && !groupItem->text().isEmpty()) {
            QDate submissionDate = QDate::fromString(dateItem->text(), "dd.MM.yyyy");
            if (!submissionDate.isValid() || submissionDate < monthAgo) {
                groupDebtCounts[groupItem->text()]++;
            }
        }
    }

    if (groupDebtCounts.isEmpty()) {
        QMessageBox::information(this, "Информация", "Нет студентов с задолженностью более месяца!");
        return;
    }

    QBarSeries *series = new QBarSeries();
    QBarSet *barSet = new QBarSet("Задолженности");
    series->append(barSet);

    QStringList groups = groupDebtCounts.keys();
    groups.sort();

    foreach (const QString &group, groups) {
        *barSet << groupDebtCounts[group];
    }

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(groups);
    axisX->setTitleText("Группы");

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Количество студентов");
    axisY->setMin(0);
    axisY->setMax(10);

    int maxDebt = 0;
    foreach (int count, groupDebtCounts.values()) {
        if (count > maxDebt) maxDebt = count;
    }
    axisY->setMax(maxDebt + 1);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    chart->setTitle("Задолженности по группам (более 1 месяца)");
    chart->legend()->setVisible(true);

    if (!chartView) {
        chartView = new QChartView(this);
        ui->verticalLayout_2->addWidget(chartView);
    }
    chartView->setChart(chart);
    chartView->setVisible(true);
    ui->tableWidget->setVisible(false);
}



void MainWindow::on_Diagram3_clicked()
{
    if (recordcount == 0){
        QMessageBox::warning(this, "Ошибка", "Нет записей построения диаграммы!");
        return;
    }

    if (chartView->isVisible()) {
        chartView->setVisible(false);
        ui->tableWidget->setVisible(true);
        return;
    }

    int selectedGrade = QInputDialog::getInt(this, "Выбор", "Введите оценку", 3, 2, 5, 1);

    if (!selectedGrade){
        QMessageBox::warning(this, "Ошибка", "Не введена оценка");
        return;
    }

    QMap<QString, int> groupGradeCounts;

        for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
            QTableWidgetItem* groupItem = ui->tableWidget->item(row, 1);
            QTableWidgetItem* gradeItem = ui->tableWidget->item(row, 5);

            if (groupItem && gradeItem) {
                bool converted;
                int grade = gradeItem->text().toInt(&converted);
                if (converted && grade == selectedGrade) {
                    groupGradeCounts[groupItem->text()]++;
                }
            }
        }

        if (groupGradeCounts.isEmpty()) {
            QMessageBox::information(this, "Информация",
                                   QString("Нет студентов с оценкой %1").arg(selectedGrade));
            return;
        }

        QBarSeries *series = new QBarSeries();
        QBarSet *barSet = new QBarSet(QString("Оценка %1").arg(selectedGrade));

        QStringList groups = groupGradeCounts.keys();
        groups.sort();

        foreach (const QString &group, groups) {
            *barSet << groupGradeCounts[group];
        }

        series->append(barSet);

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(groups);
        axisX->setTitleText("Группы");

        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Количество студентов");
        axisY->setMin(0);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->addAxis(axisX, Qt::AlignBottom);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisX);
        series->attachAxis(axisY);

        chart->setTitle(QString("Студенты с оценкой %1 по группам").arg(selectedGrade));
        chart->legend()->setVisible(true);


        if (!chartView) {
            chartView = new QChartView(this);
            ui->verticalLayout_2->addWidget(chartView);
        }
        chartView->setChart(chart);
        chartView->setVisible(true);
        ui->tableWidget->setVisible(false);
}

