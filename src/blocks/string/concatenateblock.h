#ifndef CONCATENATEBLOCK_H
#define CONCATENATEBLOCK_H

#include "../../expressionblock.h"

/**
 * @brief The ConcatenateBlock class
 *
 * @author Brent Chesny
 */
class ConcatenateBlock : public ExpressionBlock
{
public:
    /**
     * @brief Constructor
     */
    ConcatenateBlock() : _left(NULL), _right(NULL) {}

    /**
     * @brief Destructor
     */
    virtual ~ConcatenateBlock();

    /**
     * @brief Returns a unique id of the block
     * @return A unique id specific to the block
     */
    virtual QString getId() const {return QString("String_Concatenate");}

    /**
     * @brief Returns the returntype of the block
     * @return The return type of the block
     */
    virtual ParamType getReturnType() const {return Block::STRING_EXPRESSION;}

    /**
     * @brief Returns a list of the paramtypes of the parameters
     * @return A QList<ParamType> containing the paramtype if each parameter
     */
    virtual QList<ParamType> getParamTypes() const;

    /**
     * @brief Returns a description of the parameters
     * @return A description of the parameters
     */
    virtual QString getParamDescription() const {return QObject::tr("Concatenate %1 and %2").arg("%p", "%p"); }

    /**
     * @brief Executes the next step of the block. This function is assumed to do an atomic step in execution, and may not execute infinitely
     * @param executionThread The ExecutionThread this block is running on
     */
    virtual void executeNextStep(ExecutionThread& executionThread) const;

    /**
     * @brief Adds a parameterBlock to this Block
     * @param parameter The block to add
     * @param index The index of the parameter
     * @return True if adding succeeded , false if not
     */
    virtual bool addParameter(Block* parameter, int index);

    /**
     * @brief Creates a new instance of the block and returns it
     * @return A new instance of the block
     */
    virtual Block* newInstance() const {return new ConcatenateBlock();}

private:
    ExpressionBlock* _left;
    ExpressionBlock* _right;
};

#endif // CONCATENATEBLOCK_H
