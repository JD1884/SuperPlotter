#include "formulacreator.h"

#include <QStack>
#include "Functions/functionofxandyiszero.h"
#include "Functions/functionofxisy.h"

FormulaCreator::FormulaCreator(QObject *parent)
    : QObject{parent}
{

}


Function *FormulaCreator::createFunction (QString myFormula)
{
    myFormula = myFormula.remove(" ").toLower();

    if (!basicInputChecks(myFormula))
        return nullptr;

    myFormula = myFormula
            .replace('[','(').replace(']',')')
            .replace('{','(').replace('}',')')
            .replace('<','(').replace('>',')');

    if (myFormula.count("=") == 0)
    {
        bool yFound = false;
        for (int i = 0; i < myFormula.size(); ++i)
        {
            if (myFormula[i] == 'y')
                yFound = true;
        }

        if (yFound)
        {
            return createXYFunction(myFormula);
        } else
        {
            return createOnlyXFunction(myFormula);
        }
    }


    QStringList myQStringList = myFormula.split("=");
    QString left = myQStringList.at(0);
    QString right = myQStringList.at(1);

    for (int j = 0; j < 2; j++)
    {
        if (left.size() == 1)
        {
            if (left[0] == 'y')
            {
                bool noYInRight = true;
                for (int i = 0; i < right.size() && noYInRight; ++i)
                {
                    if (right[i] == 'y')
                        noYInRight = false;
                }
                if (noYInRight)
                {
                    return useNestedFormulaCreator(right);
                }
            }
        }

        // Swap left and right for retest
        QString swapBuffer = left;
        left = right;
        right = swapBuffer;
    }

    return useNestedFormulaCreator("(" + left + ")-(" + right + ")");

    setErrMessage(0);
    return nullptr;
}

int FormulaCreator::getErrIndex()
{
    return errIndex;
}
QString FormulaCreator::getErrMessage()
{
    return errMessage;
}

bool FormulaCreator::basicInputChecks (QString myFormula)
{
    // Equal sign's test
    if (myFormula.count("=") > 1)
    {
        setErrMessage (0x0101);
        return false;
    }

    // Bracets and unwanted signs test
    QStack<QChar> brackets;
    bool nestedEqual = false;
    QChar unwantedChar = '0';
    for (int i = 0; i < myFormula.size(); i++)
    {
        if (myFormula[i] == '(' ||
                myFormula[i] == '{' ||
                myFormula[i] == '[' ||
                myFormula[i] == '<')
            brackets.push(myFormula[i]);

        if (myFormula[i] == ')' ||
                myFormula[i] == '}' ||
                myFormula[i] == ']' ||
                myFormula[i] == '>')
        {
            if (brackets.empty())
            {
                setErrMessage(0x0112);
                return false;
            }
            QChar lastOpeningBracket = brackets.pop();
            if (!((lastOpeningBracket == '(' && myFormula[i] == ')') ||
                    lastOpeningBracket.digitValue() + 2 == myFormula[i].digitValue()))
            {
                setErrMessage(0x0114);
                return false;
            }
        }
        if (myFormula[i] == '=')
        {
            if (!brackets.empty())
                nestedEqual = true;
        }
        if (myFormula[i] == '&' ||
                myFormula[i] == '#')
            unwantedChar = myFormula[i];
    }
    if (!brackets.isEmpty())
    {
        setErrMessage(0x0111);
        return false;
    }
    if (nestedEqual)
    {
        setErrMessage(0x0113);
        return false;
    }
    if (unwantedChar != '0')
    {
        switch (unwantedChar.digitValue())
        {
        case '&':
            setErrMessage(0x0121);
            return false;
        case '#':
            setErrMessage(0x0122);
            return false;
        default:
            setErrMessage(0x0120);
            return false;
        }
    }

    return true;
}

Function* FormulaCreator::useNestedFormulaCreator(QString myFormula)
{
    FormulaCreator *myNestedFormulaCreator = new FormulaCreator;
    Function *myFunction = myNestedFormulaCreator->createFunction(myFormula);
    if (myFunction == nullptr)
        setErrMessage(myNestedFormulaCreator->getErrIndex());
    delete myNestedFormulaCreator;
    return myFunction;
}

Function* FormulaCreator::createXYFunction(QString myFormula)
{
    FunctionCore* myFunctionPart = new FunctionCore();
    if (!myFunctionPart->setup(myFormula))
    {
        setErrMessage(myFunctionPart->getErrIndex());
        delete myFunctionPart;
        return nullptr;
    }

    return new FunctionOfXAndYIsZero(myFunctionPart);
}

Function* FormulaCreator::createOnlyXFunction(QString myFormula)
{
    FunctionCore* myFunctionPart = new FunctionCore();
    if (!myFunctionPart->setup(myFormula))
    {
        setErrMessage(myFunctionPart->getErrIndex());
        delete myFunctionPart;
        return nullptr;
    }

    return new FunctionOfXIsY(myFunctionPart);
}


void FormulaCreator::setErrMessage(int errIndex)
{
    this->errIndex = errIndex;
    if ((errIndex & 0x0f00) == 0x0100)
    {
        switch (errIndex & 0x00ff)
        {
        case 0x01:
            errMessage = "Fatal input Error: Multiple \'=\' found";
            break;
        case 0x11:
            errMessage = "Fatal input Error: missing closing bracket";
            break;
        case 0x12:
            errMessage = "Fatal input Error: missing opening bracket";
            break;
        case 0x13:
            errMessage = "Fatal input Error: equal sign is nested in brackets";
            break;
        case 0x14:
            errMessage = "Fatal input Error: mixed use of bracket types";
            break;
        case 0x20:
            errMessage = "Fatal input Error: illigal character present";
            break;
        case 0x21:
            errMessage = "Fatal input Error: illigal character \'&\' present";
            break;
        case 0x22:
            errMessage = "Fatal input Error: illigal character \'#\' present";
            break;
        default:
            errMessage = "Unknown input error";
            break;
        }
    } else if ((errIndex & 0x0f00) == 0x0200)
    {
        switch (errIndex & 0x00ff)
        {
        case 0x01:
            errMessage = "Fatal process Error: repeating typo of basic modifier";
            break;
        case 0xff:
            errMessage = "Fatal process Error: unknown opperations founds";
            break;
        default:
            errMessage = "Unknown process error";
            break;
        }
    } else if ((errIndex & 0xff00) == 0xff00)
    {
        errMessage = "Called functionality isn't implemented yet";
    } else
    {
        errMessage = "Unknown error";
    }

    errMessage += " (0x";
    // Pad with 0 if the hex decimal representation of the errIndex has less than 4 characters.
    for (int i = 0; (double)errIndex / qPow(16, 3 - i) < 1.0 && i < 4; ++i)
        errMessage += "0";

    errMessage += QString::number(errIndex, 16);
    errMessage += ")";
}
