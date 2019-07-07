#ifndef _ARITHMETIC_H_
#define _ARITHMETIC_H_

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <list>
#include <string>

class ArithmeticNode
{
public:
    
    virtual ~ArithmeticNode() {}
    
    enum NodeType
    {
        INVALID,
        OPERATOR,
        CONSTANT,
        VARIABLE_X,
        VARIABLE_Y,
    };
    
    enum OperatorType
    {
        OP_PLUS = '+',
        OP_MINUS = '-',
        OP_MULTIPLY = '*',
        OP_DIVID = '/',
        OP_POWER = '^',
        
        OP_EXP = ' exp',
        OP_ABS = ' abs',
        OP_SIGN = 'sign',
        OP_SQRT = 'sqrt',
        
        OP_SIN = ' sin',
        OP_COS = ' cos',
        OP_ARCSIN = 'asin',
        OP_ARCCOS = 'acos',
        OP_TAN = ' tan',
        OP_ARCTAN = 'atan',
        OP_LOG = ' log',
        OP_LOG2 = 'log2',
        OP_LOG10 = '  lg',
        OP_INVALID = 0
    };
    
    virtual NodeType nodeType() const { return INVALID; }
	virtual OperatorType operatorType() const { return OP_INVALID; }
    virtual double value() = 0;
    virtual bool isValid() { return true; }
    
    virtual void setValue(NodeType type, double v) {}
    
    virtual void removeChildNodes() {}
    virtual const std::list<ArithmeticNode*>* childNode() const { return nullptr; }
    virtual std::list<ArithmeticNode*>* childNode() { return nullptr; }
    virtual void addChildNode(ArithmeticNode* node) {}
    
    virtual bool canReduce() { return false; } //���ʽ�Ƿ��ܹ���, ������δ֪���Ľڵ����ȫ���滻Ϊ constant�ڵ�
    
    static ArithmeticNode::OperatorType getOpTypeByName(const char* name);
    static const char* getOpNameByType(ArithmeticNode::OperatorType opType);
};

template <typename ConstantType>
class ArithmeticNodeConstant : public ArithmeticNode
{
public:
    ArithmeticNodeConstant(ConstantType c) : m_constant(c) {}
    NodeType nodeType() const { return CONSTANT; }
    double value() { return (double)m_constant; }  //A constant must be compitable with 'double'.
    inline const ConstantType constant() const { return m_constant; }
    bool canReduce() { return true; }
private:
    ConstantType m_constant;
};

template<int VariableType>
class ArithmeticNodeVariable : public ArithmeticNode
{
public:
    ArithmeticNodeVariable() : m_variable(0.0) { static_assert(VariableType == VARIABLE_X || VariableType == VARIABLE_Y, "Invalid Variable Type!"); };
    NodeType nodeType() const override { return (NodeType)VariableType; }
    double value() override { return m_variable; }
    void setValue(NodeType type, double v) override
    {
        if (type == VariableType)
            m_variable = v;
    }
    
    bool canReduce() override { return false; }
private:
    double m_variable;
};

class ArithmeticNodeOperatorInterface : public ArithmeticNode
{
public:
    
    virtual ~ArithmeticNodeOperatorInterface()
    {
        for(auto* node : m_childNode)
        {
            delete node;
        }
        m_childNode.clear();
    }
    
    void setValue(NodeType type, double v)
    {
        for(auto* node : m_childNode)
            node->setValue(type, v);
    }
    
    NodeType nodeType() const { return OPERATOR; }
    
    void removeChildNodes() { m_childNode.clear(); }
    const std::list<ArithmeticNode*>* childNode() const { return &m_childNode; }
    std::list<ArithmeticNode*>* childNode() { return &m_childNode; }
    void addChildNode(ArithmeticNode* node) { if(node != nullptr) m_childNode.push_back(node); }
    
    bool canReduce() { for(auto* node : m_childNode) if(!node->canReduce()) return false; return true; }
    
protected:
    std::list<ArithmeticNode*> m_childNode;
};
