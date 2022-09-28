#include <QtTest>

#include "formulacreator.h"
#include "Functions/functionofxisy.h"

class FormulaMechanics : public QObject
{
    Q_OBJECT

public:

private slots:
    void createBasicFunctionOfXIsY();

    void createBasicSum_data();
    void createBasicSum();

    void errMultipleEquals();
    void errBrackets_data();
    void errBrackets();
    void errRepeatingBasicModifier();

private:
    Function *createFunction(QString);

};

// #####################################################################################################

void FormulaMechanics::createBasicFunctionOfXIsY()
{
    Function * basicFunctionOfXIsY = createFunction("y = x + 1");

    QVERIFY (dynamic_cast<FunctionOfXIsY*>(basicFunctionOfXIsY) != nullptr);

    delete basicFunctionOfXIsY;
}

void FormulaMechanics::createBasicSum_data()
{
	QTest::addColumn<double>("Input");
	QTest::addColumn<double>("Result");
	
	for (int i = 0; i < 10; ++i)
	{
        QTest::newRow(QString::number(i).toStdString().c_str()) << (double)i << (double)(i + 5);
	}
}

void FormulaMechanics::createBasicSum()
{
    Function * basicSum = createFunction("x + 5");
	
	QFETCH(double, Input);
	QFETCH(double, Result);
	
	QCOMPARE (dynamic_cast<FunctionOfXIsY*>(basicSum)->checkForValue(Input), Result);
	
	delete basicSum;
}

// #####################################################################################################

void FormulaMechanics::errMultipleEquals()
{
    FormulaCreator myFormulaCreator;
    Function *myFormula = myFormulaCreator.createFunction("y = x + 5 = x * 5");

    QCOMPARE(myFormula, nullptr);
    QCOMPARE(myFormulaCreator.getErrMessage(), "Fatal input Error: Multiple \'=\' found (0x0101)");
}

void FormulaMechanics::errBrackets_data()
{
    QTest::addColumn<QString>("Input");
    QTest::addColumn<QString>("ErrorMessage");

    QTest::newRow("Missing closing bracket") << "y = x + (5(x + 7)" << "Fatal input Error: missing closing bracket (0x0111)";
    QTest::newRow("Missing opening bracket") << "y = 5*(x+7)) + x" << "Fatal input Error: missing opening bracket (0x0112)";
    QTest::newRow("Equal sign nested in brackets") << "((x + 5) = (y + 7))" << "Fatal input Error: equal sign is nested in brackets (0x0113)";
    QTest::newRow("inconvenient brackets") << "y = [{x + 5)*(y + 8}]" << "Fatal input Error: mixed use of bracket types (0x0114)";
}

void FormulaMechanics::errBrackets()
{
    QFETCH(QString, Input);
    QFETCH(QString, ErrorMessage);

    FormulaCreator myFormulaCreator;
    Function* myFunction = myFormulaCreator.createFunction(Input);

    QCOMPARE(myFunction, nullptr);
    QCOMPARE(myFormulaCreator.getErrMessage(), ErrorMessage);
}

void FormulaMechanics::errRepeatingBasicModifier()
{
    FormulaCreator myFormulaCreator;
    Function *myFormula = myFormulaCreator.createFunction("y = x ** 5");

    QCOMPARE(myFormula, nullptr);
    QCOMPARE(myFormulaCreator.getErrMessage(), "Fatal process Error: repeating typo of basic modifier (0x2201)");
}

// #####################################################################################################

Function *FormulaMechanics::createFunction(QString myFunction)
{
    FormulaCreator myFormulaCreator;
    return myFormulaCreator.createFunction(myFunction);
}

QTEST_APPLESS_MAIN(FormulaMechanics)

#include "tst_formulamechanics.moc"
