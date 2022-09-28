#include "oneinputfunctionpart.h"

#include "oneinputdummy.h"
#include "basicModifiers/basmodisum.h"
#include "basicModifiers/basmodsub.h"
#include "basicModifiers/basmodmulti.h"
#include "basicModifiers/basmoddev.h"
#include "variable.h"
#include "number.h"

OneInputFunctionPart::OneInputFunctionPart(QObject *parent)
    : FunctionPart{parent}, myFunctionPart(nullptr)
{

}


bool OneInputFunctionPart::setup(QString myFormula)
{
// ***********************************************************************************************

    // Replace bracket parts
    int bracketNestingLevel = 0;
    QString partInBrackets;
    QString partWithBrackets;
    QList<QString> partsInBrackets;
    for (int i = 0; i < myFormula.size(); ++i)
    {
        if (myFormula[i] == '(')
        {
            if (bracketNestingLevel > 0)
                partInBrackets.push_back(myFormula[i]);
            partWithBrackets.push_back(myFormula[i]);
            bracketNestingLevel++;
         } else if (myFormula[i] ==  ')')
         {
            if (bracketNestingLevel <= 0)
            {
                setErrIndex(0x1112);
                return false;
            }
            partWithBrackets.push_back(myFormula[i]);
            if (--bracketNestingLevel == 0)
            {
                int currentIndex = partsInBrackets.size();
                partsInBrackets.push_back(partInBrackets);
                myFormula.replace(partWithBrackets, "&" + QString::number(currentIndex) + "#");
                i -= partWithBrackets.size();
                partInBrackets.clear();
                partWithBrackets.clear();
            } else
                partInBrackets.push_back(myFormula[i]);
        } else if (bracketNestingLevel > 0)
        {
            partWithBrackets.push_back(myFormula[i]);
            partInBrackets.push_back(myFormula[i]);
        }
    }

// ***********************************************************************************************

    // Check if the whole formula part isn't included in one bracket nest
    if (partsInBrackets.size() == 1 && myFormula[0] == '&'
            && myFormula[myFormula.size()-1] == '#')
    {
        OneInputDummy myDummy;
        if(!myDummy.setup(partsInBrackets.at(0)))
        {
            setErrIndex(myDummy.getErrIndex());
            return false;
        }

        myFunctionPart = myDummy.getFunctionPart();
        return true;
    }

// ***********************************************************************************************

    // Screen for basic modifiers
    // Lowest to highest priority: +; -; *; /; ^
    QString left;
    QString right;
    int errIndex = 0;

    // +
    if (splitOnFirstSign('+', myFormula, &left, &right, &errIndex))
    {
        BasModiSum *mySumPart = new BasModiSum();
        if (!mySumPart->setup(left, right))
        {
            setErrIndex(mySumPart->getErrIndex());
            return false;
        }
        myFunctionPart = mySumPart;
        return true;
    } else if (errIndex != 0)
    {
        setErrIndex(errIndex);
        return false;
    }

    // -
    if (splitOnFirstSign('-', myFormula, &left, &right, &errIndex))
    {
        BasModSub *mySubPart = new BasModSub();
        if (!mySubPart->setup(left, right))
        {
            setErrIndex(mySubPart->getErrIndex());
            return false;
        }
        myFunctionPart = mySubPart;
        return true;
    } else if (errIndex != 0)
    {
        setErrIndex(errIndex);
        return false;
    }

    // *
    if (splitOnFirstSign('*', myFormula, &left, &right, &errIndex))
    {
        BasModMulti *myMultiPart = new BasModMulti();
        if (!myMultiPart->setup(left, right))
        {
            setErrIndex(myMultiPart->getErrIndex());
            return false;
        }
        myFunctionPart = myMultiPart;
        return true;
    } else if (errIndex != 0)
    {
        setErrIndex(errIndex);
        return false;
    }

    // /
    if (splitOnFirstSign('/', myFormula, &left, &right, &errIndex))
    {
        BasModDev *myDevPart = new BasModDev();
        if (!myDevPart->setup(left, right))
        {
            setErrIndex(myDevPart->getErrIndex());
            return false;
        }
        myFunctionPart = myDevPart;
        return true;
    } else if (errIndex != 0)
    {
        setErrIndex(errIndex);
        return false;
    }

    // ^

// ***********************************************************************************************

    // Screen for basic functions ("sin", "arcsin", "sum", ...)

// ***********************************************************************************************

    // Screen for variable (X and Y)
    if (myFormula.size() == 1)
    {
        if (myFormula[0] == 'x')
        {
            myFunctionPart = new Variable(false);
            return true;
        }
        if (myFormula[0] == 'y')
        {
            myFunctionPart = new Variable(true);
            return true;
        }
    }

// ***********************************************************************************************

    // Screen for constants (a, b, c, ...)

// ***********************************************************************************************

    // Screen for numbers
    bool *okPointer = new bool;
    double numberValue = myFormula.toDouble(okPointer);
    if (*okPointer)
    {
        delete okPointer;

        myFunctionPart = new Number(numberValue);
        return true;
    }
    delete okPointer;

// ***********************************************************************************************

    setErrIndex(0x02ff);
    return false;
}


double OneInputFunctionPart::getVal(double xVal, double yVal)
{
    return myFunctionPart->getVal(xVal, yVal);
}


bool OneInputFunctionPart::splitOnFirstSign(QChar sign, QString original, QString* left, QString* right, int* errIndex)
{
    left->clear();
    right->clear();

    if (!original.contains(sign))
    {
        *errIndex = 0;
        return false;
    }
    QStringList parts = original.split(sign, Qt::KeepEmptyParts);

    if (parts[0].isEmpty())
    {
        *errIndex = 0x2201;
        return false;
    }

    *left = parts[0];

    if (parts[1].isEmpty())
    {
        *errIndex = 0x2201;
        return false;
    }

    *right = parts[1];
    for (int i = 2; i < parts.size(); ++i)
    {
        if (parts[i].isEmpty())
        {
            *errIndex = 0x2201;
            return false;
        }
        *right += sign + parts[i];
    }

    return true;
}


QString OneInputFunctionPart::replaceBracketParts(QString formulaString, QList<QString> partsInBrackets)
{
    for (int i = 0; i < partsInBrackets.size(); ++i)
    {
        if (formulaString.contains("&" + QString::number(i) + "#"))
        {
            formulaString.replace("&" + QString::number(i) + "#",
                                  "(" + partsInBrackets[i] +")");
        }
    }

    return formulaString;
}
