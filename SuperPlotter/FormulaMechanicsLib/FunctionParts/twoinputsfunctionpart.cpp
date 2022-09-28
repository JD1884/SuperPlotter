#include "twoinputsfunctionpart.h"

TwoInputsFunctionPart::TwoInputsFunctionPart(QObject *parent)
    : FunctionPart{parent}
{

}


bool TwoInputsFunctionPart::setup (QString left, QString right)
{
    this->right = new OneInputFunctionPart();
    if (!this->right->setup(right))
    {
        setErrIndex(this->right->getErrIndex());
        return false;
    }

    this->left = new OneInputFunctionPart();
    if (!this->left->setup(left))
    {
        setErrIndex(this->left->getErrIndex());
        return false;
    }

    return true;
}
