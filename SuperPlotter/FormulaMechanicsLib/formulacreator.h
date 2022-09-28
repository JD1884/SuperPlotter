#ifndef FORMULACREATOR_H
#define FORMULACREATOR_H

#include <QObject>
#include "Functions/function.h"
#include "FunctionParts/functioncore.h"

class FormulaCreator : public QObject
{
    Q_OBJECT
public:
    explicit FormulaCreator(QObject *parent = nullptr);

    Function *createFunction (QString);

    int getErrIndex();
    QString getErrMessage();


private:
    bool basicInputChecks(QString);

    Function* useNestedFormulaCreator(QString);

    Function* createXYFunction(QString);
    Function* createOnlyXFunction(QString);

    void setErrMessage(int errIndex);

    int errIndex;
    QString errMessage;

};

#endif // FORMULACREATOR_H
