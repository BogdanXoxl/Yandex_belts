#ifndef YANDEX_BELTS_NODE_H
#define YANDEX_BELTS_NODE_H

#include "date.h"

#include <memory>
#include <utility>

enum class Comparison {
  Less,
  LessOrEqual,
  Greater,
  GreaterOrEqual,
  Equal,
  NotEqual
};

enum LogicalOperation {
    Or,
    And
};

template <class CmpType> bool compare(const Comparison& cmp_, const CmpType& left, const CmpType& right){
    switch (cmp_) {
        case Comparison::Less:
            return left < right;
        case Comparison::LessOrEqual:
            return left <= right;
        case Comparison::Greater:
            return left > right;
        case Comparison::GreaterOrEqual:
            return left >= right;
        case Comparison::Equal:
            return left == right;
        case Comparison::NotEqual:
            return left != right;
        default:
            throw std::logic_error("Unknown comparison token");
    }
}


class Node {
public:
    virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class EmptyNode: public Node{
public:
    bool Evaluate(const Date& date, const std::string& event) const override;
};

class DateComparisonNode: public Node{
public:
    DateComparisonNode(const Comparison& cmp, const Date& date);
    bool Evaluate(const Date& date, const std::string& event)const override;
private:
    Comparison cmp_;
    Date date_;
};

class EventComparisonNode: public Node{
public:
    EventComparisonNode(const Comparison& cmp, std::string  value);
    bool Evaluate(const Date& date, const std::string& event)const override;
private:
    Comparison cmp_;
    std::string event_;
};

class LogicalOperationNode: public Node{
public:
    LogicalOperationNode(const LogicalOperation& logicOp, std::shared_ptr<Node> left, std::shared_ptr<Node> right);
    bool Evaluate(const Date& date, const std::string& event)const override;
private:
    LogicalOperation logicOp_;
    std::shared_ptr<Node> first, second;
};



#endif //YANDEX_BELTS_NODE_H
